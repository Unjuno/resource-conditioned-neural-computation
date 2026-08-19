#include <stdint.h>
#include "realtime_nn_real_sequence_fixed_core.h"

#define MMIO_OUT  (*(volatile uint32_t *)(uintptr_t)0x00020000u)
#define MMIO_HALT (*(volatile uint32_t *)(uintptr_t)0x00020008u)

static RTNNFixedWorkspace workspace;
static int32_t logits[10];
static const uint8_t inputs[4][64] = {
  {0,0,5,13,9,1,0,0,0,0,13,15,10,15,5,0,0,3,15,2,0,11,8,0,0,4,12,0,0,8,8,0,0,5,8,0,0,9,8,0,0,4,11,0,1,12,7,0,0,2,14,5,10,12,0,0,0,0,6,13,10,0,0,0},
  {0,0,0,12,13,5,0,0,0,0,4,16,16,13,0,0,0,0,0,9,13,16,2,0,0,0,0,3,16,12,0,0,0,0,0,3,16,8,0,0,0,0,0,6,16,4,0,0,0,0,2,15,16,15,8,0,0,0,1,13,16,16,11,0},
  {0,0,5,15,12,0,0,0,0,3,15,8,14,0,0,0,0,2,13,0,14,0,0,0,0,5,12,8,16,4,0,0,0,4,15,16,16,16,7,0,0,0,3,8,10,12,8,0,0,0,3,12,2,13,4,0,0,0,5,14,14,5,0,0},
  {0,0,0,3,14,5,0,0,0,0,2,15,14,15,1,0,0,0,8,13,2,14,3,0,0,1,16,8,0,11,8,0,0,4,16,5,0,8,8,0,0,4,16,3,0,10,7,0,0,2,14,9,9,15,1,0,0,0,1,13,16,7,0,0}
};

static inline uint32_t read_cycle(void) {
  uint32_t x;
  __asm__ volatile ("csrr %0, mcycle" : "=r"(x));
  return x;
}
static void putc0(char c){ MMIO_OUT=(uint32_t)(uint8_t)c; }
static void puts0(const char*s){while(*s)putc0(*s++);}
static void putu(uint32_t v){
  char b[10]; unsigned n=0;
  if(!v){putc0('0');return;}
  while(v){ uint32_t q=v/10u; b[n++]=(char)('0'+(v-q*10u)); v=q; }
  while(n)putc0(b[--n]);
}
static int argmax10(const int32_t*z){int b=0;for(int i=1;i<10;++i)if(z[i]>z[b])b=i;return b;}
int main(void){
  uint32_t oh0=read_cycle(); uint32_t oh1=read_cycle();
  puts0("RTNN_IBEX_BEGIN\n"); puts0("RTNN_OVERHEAD,"); putu(oh1-oh0); putc0('\n');
  for(uint32_t in=0;in<4;++in){
    for(uint32_t c=0;c<7;++c){
      uint32_t t0=read_cycle();
      rtnn_fixed_certify_class(&workspace,inputs[in],(uint8_t)c,logits);
      uint32_t t1=read_cycle();
      puts0("RTNN,");putu(in);putc0(',');putu(c);putc0(',');putu(t1-t0);putc0(',');putu((uint32_t)argmax10(logits));putc0('\n');
    }
  }
  puts0("RTNN_IBEX_END\n");
  MMIO_HALT=1;
  return 0;
}
