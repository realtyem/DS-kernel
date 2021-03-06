/*
 * ARM specific SMP header, this contains our implementation
 * details.
 */
#ifndef __ASMARM_SMP_PLAT_H
#define __ASMARM_SMP_PLAT_H

#include <asm/cputype.h>

/* all SMP configurations have the extended CPUID registers */
static inline int tlb_ops_need_broadcast(void)
{
	return ((read_cpuid_ext(CPUID_EXT_MMFR3) >> 12) & 0xf) < 2;
}

static inline int cache_ops_need_broadcast(void)
{
	return ((read_cpuid_ext(CPUID_EXT_MMFR3) >> 12) & 0xf) < 1;
}

#endif
