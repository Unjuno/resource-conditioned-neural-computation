#include <stdint.h>
#include "realtime_nn_real_sequence_fixed_core.h"
#include "rtnn_ibex_inputs.h"

#define UART (*(volatile uint32_t*)0x20000u)

static void putc1(char c){ UART=(uint32_t)(uint8_t)c; }
static void puts1(const char*s){ while(*s) putc1(*s++); }
static void hex32(uint32_t x){ static const char h[]="0123456789abcdef"; for(int i=7;i>=0;--i) putc1(h[(x>>(i*4))&15u]); }
static uint32_t cyc(void){ uint32_t x; __asm__ volatile("csrr %0, mcycle" : "=r"(x)); return x; }
static int argmax10(const int32_t z[10]){ int b=0; for(int i=1;i<10;++i) if(z[i]>z[b]) b=i; return b; }

int main(void){
  static RTNNFixedWorkspace w;
  int32_t z[10];
  for(uint32_t n=0;n<2u;++n){
    for(uint32_t c=0;c<7u;++c){
      uint32_t a=cyc();
      rtnn_fixed_certify_class(&w,RTNN_IBEX_INPUTS[n],(uint8_t)c,z);
      uint32_t b=cyc();
      puts1("RTNN n="); putc1((char)('0'+n));
      puts1(" c="); putc1((char)('0'+c));
      puts1(" cyc="); hex32(b-a);
      puts1(" pred="); putc1((char)('0'+argmax10(z)));
      putc1('\n');
    }
  }
  return 0;
}
