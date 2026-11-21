#include "rtnn_external_runner.h"
#include <stdint.h>
#include <stdio.h>

static uint64_t fake_cycles=100;
static uint64_t fake_clock(void *ctx){(void)ctx;return fake_cycles+=37;}
int main(void){
  static uint8_t px[64]; uint32_t seq=0; unsigned long iid=0;
  rtnn_ext_config_t cfg={0x52544e4eu,0x45585631u,0x45585632u,fake_clock,0};
  puts("input_id,mode,prediction,admitted_exit,executed_exit,stop_reason,status,label");
  while(fread(px,1,64,stdin)==64){
    ++iid; for(unsigned i=0;i<64;i++)if(px[i]>16)return 3;
    for(unsigned m=0;m<2;m++){
      rtnn_ext_request_t q={0}; q.seq=++seq;q.input_id=(uint16_t)iid;q.mode=m?RTNN_EXT_MODE_ADAPTIVE:RTNN_EXT_MODE_FIXED2;
      q.fixed_exit=m?0:2;q.budget_q16=65535;q.deadline_cycles=0;q.model_id=cfg.model_id;q.build_id=cfg.build_id;
      rtnn_ext_response_t r={0}; uint32_t crc=rtnn_ext_crc32(px,64);
      if(rtnn_ext_execute(&q,px,crc,&r,&cfg)||r.status!=RTNN_EXT_STATUS_OK||r.label!=-1||r.prediction<0||r.prediction>9||r.executed_exit>r.admitted_exit||r.cycles_end<=r.cycles_start)return 4;
      const char *stop=r.stop_reason==RTNN_EXT_STOP_NONE?"none":(r.stop_reason==RTNN_EXT_STOP_ENTROPY?"entropy":"budget");
      printf("%lu,%s,%d,%d,%d,%s,%u,%d\n",iid,m?"adaptive":"fixed2",r.prediction,r.admitted_exit,r.executed_exit,stop,r.status,r.label);
    }
  }
  if(!feof(stdin))return 5;
  return 0;
}
