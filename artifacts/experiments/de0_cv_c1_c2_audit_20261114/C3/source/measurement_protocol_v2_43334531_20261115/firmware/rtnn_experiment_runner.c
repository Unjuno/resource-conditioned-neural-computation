/* Same frozen Q15 core, with a NEW experimental runner and distinct build ID.
 * Not the August Simple-System cycle binding. This code does not certify WCET.
 */
#include "rtnn_experiment_runner.h"
#include "realtime_nn_real_sequence_fixed_core.h"
#include "heldout360.h"
#include <stdint.h>
#include <limits.h>

static RTNNFixedWorkspace workspace;
static int32_t logits[10];

static int8_t argmax10(const int32_t *z){
  int8_t best=0;
  for(int8_t i=1;i<10;++i)if(z[i]>z[best])best=i;
  return best;
}
static int8_t admit(const rtnn_fw_config_t*c,uint32_t deadline){
  if(!c->has_fpga_cycle_binding||c->binding_id==0)return -1;
  int8_t chosen=-1;uint32_t last=0;
  for(int i=0;i<7;++i){
    uint32_t bound=c->upper_total_cycles[i];
    if(bound==0||bound==UINT32_MAX||bound<last)return -1;
    last=bound;
    if(bound<=deadline)chosen=(int8_t)i;
  }
  return chosen;
}
static void fail(rtnn_exp_response_t*out,uint8_t status){
  out->status=status;out->admitted_exit=-1;out->executed_exit=-1;
  out->prediction=-1;out->label=-1;out->stop_reason=0;
  out->cycles_start=0;out->cycles_end=0;out->flags=0;
}
int rtnn_fw_execute(const rtnn_exp_request_t*req,rtnn_exp_response_t*out,
                    const rtnn_fw_config_t*cfg){
  if(!req||!out||!cfg||!cfg->cycle_now||!cfg->model_id||!cfg->build_id)return -1;
  out->seq=req->seq;out->input_id=req->input_id;out->mode=req->mode;
  out->status=RTNN_STATUS_OK;out->stop_reason=0;out->budget_q16=req->budget_q16;
  out->deadline_cycles=req->deadline_cycles;out->admitted_exit=-1;
  out->executed_exit=-1;out->prediction=-1;out->label=-1;
  out->cycles_start=0;out->cycles_end=0;
  out->model_id=cfg->model_id;out->build_id=cfg->build_id;
  out->binding_id=cfg->binding_id;out->flags=0;
  if(req->model_id!=cfg->model_id||req->build_id!=cfg->build_id){
    fail(out,RTNN_STATUS_WRONG_ID);return 0;
  }
  if(req->mode==RTNN_MODE_STATUS) return 0;
  if(req->input_id>=RTNN_TEST_COUNT||req->mode>RTNN_MODE_DEADLINE||
     req->fixed_exit>6u||(req->mode!=RTNN_MODE_FIXED&&req->fixed_exit!=0u)){
    fail(out,RTNN_STATUS_BAD_REQUEST);return 0;
  }
  const uint8_t* pixels=rtnn_test_pixels[req->input_id];
  out->label=(int8_t)rtnn_test_labels[req->input_id];
  if(req->mode==RTNN_MODE_DEADLINE){
    if(!cfg->has_fpga_cycle_binding||cfg->binding_id==0){
      fail(out,RTNN_STATUS_REJECTED);return 0;
    }
  }
  uint64_t before=cfg->cycle_now(cfg->cycle_ctx);
  out->cycles_start=before;
  uint8_t budget_cap=rtnn_fixed_budget_ceiling_q16(req->budget_q16);
  int8_t allowed= (int8_t)budget_cap;
  if(req->mode==RTNN_MODE_FIXED) allowed=(int8_t)req->fixed_exit;
  if(req->mode==RTNN_MODE_DEADLINE){
    int8_t d=admit(cfg,req->deadline_cycles);
    if(d<0){fail(out,RTNN_STATUS_REJECTED);return 0;}
    out->admitted_exit=d;
    if(d<allowed)allowed=d;
  }else out->admitted_exit=allowed;
  if(req->mode==RTNN_MODE_FIXED||req->mode==RTNN_MODE_CAPPED){
    rtnn_fixed_infer_exit(&workspace,pixels,(uint8_t)allowed,logits);
    out->executed_exit=allowed;
  }else{
    uint8_t executed=255u;
    rtnn_fixed_infer_budget(&workspace,pixels,req->budget_q16,(uint8_t)allowed,
                            logits,&executed);
    if(executed>6u || (int8_t)executed>allowed){
      fail(out,RTNN_STATUS_INTERNAL);return 0;
    }
    out->executed_exit=(int8_t)executed;
    /* This frozen seed-63 policy has maximum useful exit 5. A full 6-block
       permission is not an entropy early-stop. Distinguish the policy ceiling
       from an actual confidence-triggered exit to keep the paper log honest. */
    const uint8_t policy_ceiling=5u;
    const uint8_t effective_allowed=(uint8_t)allowed>policy_ceiling ?
                                    policy_ceiling : (uint8_t)allowed;
    out->stop_reason=(executed<effective_allowed)?1u:
                      (req->mode==RTNN_MODE_DEADLINE &&
                       allowed<(int8_t)budget_cap &&
                       effective_allowed==(uint8_t)allowed)?3u:2u;
  }
  out->prediction=argmax10(logits);
  uint64_t after=cfg->cycle_now(cfg->cycle_ctx);
  out->cycles_end=after;
  if(after<before){out->status=RTNN_STATUS_COUNTER_INVALID;
    out->flags=RTNN_CYCLE_REGRESSION;return 0;}
  if(after==before){out->status=RTNN_STATUS_COUNTER_INVALID;
    out->flags=RTNN_CYCLE_ZERO;return 0;}
  out->flags=RTNN_CYCLE_VALID;
  return 0;
}
