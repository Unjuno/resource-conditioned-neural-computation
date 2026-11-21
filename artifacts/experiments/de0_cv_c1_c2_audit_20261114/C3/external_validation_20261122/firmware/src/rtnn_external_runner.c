#include "rtnn_external_runner.h"
#include "realtime_nn_real_sequence_fixed_core.h"

#define RTNN_EXT_MODEL_ID UINT32_C(0x52544e4e)
#define RTNN_EXT_BUILD_ID UINT32_C(0x45585631)
#define RTNN_EXT_BINDING_ID UINT32_C(0x45585632)

static RTNNFixedWorkspace workspace;
static int32_t logits[10];

static int8_t argmax10(const int32_t z[10]) {
  int8_t best=0;
  for (int8_t i=1; i<10; ++i) if (z[i]>z[best]) best=i;
  return best;
}

static void invalid(rtnn_ext_response_t *out, uint8_t status) {
  out->status=status; out->stop_reason=RTNN_EXT_STOP_NONE;
  out->admitted_exit=-1; out->executed_exit=-1; out->prediction=-1; out->label=-1;
  out->cycles_start=0; out->cycles_end=0; out->flags=0;
}

int rtnn_ext_execute(const rtnn_ext_request_t *req, const uint8_t pixels[64],
                     uint32_t payload_crc32, rtnn_ext_response_t *out,
                     const rtnn_ext_config_t *cfg) {
  if (!req || !pixels || !out || !cfg || !cfg->cycle_now ||
      cfg->model_id!=RTNN_EXT_MODEL_ID || cfg->build_id!=RTNN_EXT_BUILD_ID ||
      cfg->binding_id!=RTNN_EXT_BINDING_ID) return -1;
  for (unsigned i=0; i<64; ++i) if (pixels[i]>16u) {
    invalid(out,RTNN_EXT_STATUS_BAD_REQUEST); return 0;
  }
  out->seq=req->seq; out->input_id=req->input_id; out->mode=req->mode;
  out->status=RTNN_EXT_STATUS_OK; out->stop_reason=RTNN_EXT_STOP_NONE;
  out->budget_q16=req->budget_q16; out->payload_crc32=payload_crc32;
  out->admitted_exit=-1; out->executed_exit=-1; out->prediction=-1; out->label=-1;
  out->cycles_start=0; out->cycles_end=0;
  out->model_id=cfg->model_id; out->build_id=cfg->build_id;
  out->binding_id=cfg->binding_id; out->flags=0;
  if (req->model_id!=cfg->model_id || req->build_id!=cfg->build_id) {
    invalid(out,RTNN_EXT_STATUS_WRONG_ID); return 0;
  }
  if (req->input_id==0 || req->input_id>RTNN_EXT_INPUT_COUNT ||
      req->budget_q16!=65535u || req->deadline_cycles!=0 ||
      !((req->mode==RTNN_EXT_MODE_FIXED2 && req->fixed_exit==2u) ||
        (req->mode==RTNN_EXT_MODE_ADAPTIVE && req->fixed_exit==0u))) {
    invalid(out,RTNN_EXT_STATUS_BAD_REQUEST); return 0;
  }

  uint64_t before=cfg->cycle_now(cfg->cycle_ctx);
  out->cycles_start=before;
  if (req->mode==RTNN_EXT_MODE_FIXED2) {
    rtnn_fixed_infer_exit(&workspace,pixels,2u,logits);
    out->admitted_exit=2; out->executed_exit=2;
  } else {
    uint8_t executed=255u;
    rtnn_fixed_infer_budget(&workspace,pixels,65535u,6u,logits,&executed);
    if (executed>5u) { invalid(out,RTNN_EXT_STATUS_INTERNAL); return 0; }
    out->admitted_exit=6; out->executed_exit=(int8_t)executed;
    out->stop_reason=(executed<5u) ? RTNN_EXT_STOP_ENTROPY : RTNN_EXT_STOP_BUDGET;
  }
  out->prediction=argmax10(logits);
  uint64_t after=cfg->cycle_now(cfg->cycle_ctx);
  out->cycles_end=after;
  if (after<before) { invalid(out,RTNN_EXT_STATUS_COUNTER_INVALID); out->cycles_start=before; out->cycles_end=after; out->flags=RTNN_EXT_CYCLE_REGRESSION; return 0; }
  if (after==before) { invalid(out,RTNN_EXT_STATUS_COUNTER_INVALID); out->cycles_start=before; out->cycles_end=after; out->flags=RTNN_EXT_CYCLE_ZERO; return 0; }
  out->flags=RTNN_EXT_CYCLE_VALID;
  return 0;
}
