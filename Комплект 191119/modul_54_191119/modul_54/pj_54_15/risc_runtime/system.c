#include "system.h"

unsigned int sys_kernel_pa_to_va(unsigned int pa)
{
    if(pa < 0x40000000) return (pa + 0xa0000000);
    if(pa < 0xC0000000) return (pa - 0x40000000);
    return pa;
}
unsigned int sys_kernel_va_to_pa(unsigned int va)
{
    if(va >= 0xE0000000) return va;
    if(va >= 0xa0000000) return (va - 0xa0000000);
    if(va < 0x80000000) return (va + 0x40000000);
    return sys_kernel_va_to_pa(va | 0x20000000); //cache address
}

unsigned get_cpu_clock(void)
{
    if ((CR_PLL0&0x80) != 0)
        return ((CLOCK)*(CR_PLL0&0x7f));
    else
        return CLOCK;
}

unsigned get_dsp_clock(void)
{
    if (CR_PLL0&0x800000 != 0)
        return((CLOCK)*((CR_PLL0&0x7f0000)>>16));
    else
        return CLOCK;

};
