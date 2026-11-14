/* Minimal freestanding memory helper for -nostdlib RV32 images.
 * Clang may synthesize memset for automatic aggregate initialization.
 * Keeping it explicit avoids pulling in the host C runtime.
 * This is part of the NEW FPGA B artifact, not the frozen Simple-System A ELF.
 */
#include <stddef.h>
void *memset(void *destination, int fill, size_t count) {
    unsigned char *bytes=(unsigned char *)destination;
    for(size_t i=0;i<count;i++) bytes[i]=(unsigned char)fill;
    return destination;
}
