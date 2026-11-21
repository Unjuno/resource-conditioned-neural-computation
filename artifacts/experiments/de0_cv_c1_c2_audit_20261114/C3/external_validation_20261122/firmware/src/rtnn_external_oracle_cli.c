#include "realtime_nn_real_sequence_fixed_core.h"
#include <stdint.h>
#include <stdio.h>

/* Input is a raw sequence of 64-byte images only. Labels are never read. */
static RTNNFixedWorkspace workspace;
static int32_t logits[10];
static int argmax10(const int32_t z[10]) {
  int best=0;
  for (int i=1;i<10;i++) if (z[i]>z[best]) best=i;
  return best;
}
int main(void) {
  uint8_t pixels[64];
  unsigned long id=0;
  puts("input_id,mode,prediction,admitted_exit,executed_exit,stop_reason,cap_violation");
  while (fread(pixels,1,64,stdin)==64) {
    ++id;
    for (unsigned i=0;i<64;i++) if (pixels[i]>16) return 3;
    rtnn_fixed_infer_exit(&workspace,pixels,2,logits);
    printf("%lu,fixed2,%d,2,2,none,0\n",id,argmax10(logits));
    uint8_t executed=255;
    rtnn_fixed_infer_budget(&workspace,pixels,65535,6,logits,&executed);
    if (executed>5) return 4;
    printf("%lu,adaptive,%d,6,%u,%s,%u\n",id,argmax10(logits),executed,
           executed<5?"entropy":"budget",executed>6?1u:0u);
  }
  if (!feof(stdin)) return 5;
  return 0;
}
