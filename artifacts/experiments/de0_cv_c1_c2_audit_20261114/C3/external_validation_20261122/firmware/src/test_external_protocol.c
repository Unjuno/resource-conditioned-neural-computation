#include "rtnn_external_runner.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

static uint64_t clock_value=100;
static uint64_t tick(void *unused) { (void)unused; return ++clock_value; }
int main(void) {
  uint8_t px[64]; for(unsigned i=0;i<64;i++) px[i]=(uint8_t)((i*7u)%17u);
  uint32_t crc=rtnn_ext_crc32(px,64);
  rtnn_ext_config_t cfg={0x52544e4eu,0x45585631u,0x45585632u,tick,0};
  rtnn_ext_request_t q={1,9,RTNN_EXT_MODE_FIXED2,2,65535,0,0x52544e4eu,0x45585631u};
  rtnn_ext_response_t r={0};
  assert(rtnn_ext_execute(&q,px,crc,&r,&cfg)==0 && r.status==RTNN_EXT_STATUS_OK);
  assert(r.input_id==9 && r.seq==1 && r.label==-1 && r.prediction>=0 && r.prediction<=9);
  assert(r.cycles_end>r.cycles_start && r.flags==RTNN_EXT_CYCLE_VALID);
  q.mode=RTNN_EXT_MODE_ADAPTIVE; q.fixed_exit=0; q.seq=2;
  assert(rtnn_ext_execute(&q,px,crc,&r,&cfg)==0 && r.status==RTNN_EXT_STATUS_OK);
  assert(r.admitted_exit==6 && r.executed_exit>=0 && r.executed_exit<=5 && r.label==-1);
  q.mode=RTNN_EXT_MODE_FIXED2; q.fixed_exit=2; q.seq=3;
  q.model_id^=1;
  assert(rtnn_ext_execute(&q,px,crc,&r,&cfg)==0 && r.status==RTNN_EXT_STATUS_WRONG_ID);
  q.model_id=cfg.model_id; q.seq=4; px[0]=17;
  assert(rtnn_ext_execute(&q,px,crc,&r,&cfg)==0 && r.status==RTNN_EXT_STATUS_BAD_REQUEST);
  puts("DYNAMIC_INPUT_FIXED2_ADAPTIVE_ID_PIXEL_CRC_TEST_PASS");
  return 0;
}
