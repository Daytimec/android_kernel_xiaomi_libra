/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2019-2020 Sultan Alsawaf <sultan@kerneltoast.com>.
 */
#ifndef _SIMPLE_LMK_H_
#define _SIMPLE_LMK_H_

#include <linux/types.h>

struct mm_struct;

#ifdef CONFIG_ANDROID_SIMPLE_LMK
void simple_lmk_decide_reclaim(int kswapd_priority);
void simple_lmk_mm_freed(struct mm_struct *mm);
bool simple_lmk_victim(void);
#else
static inline void simple_lmk_decide_reclaim(int kswapd_priority)
{
}
static inline void simple_lmk_mm_freed(struct mm_struct *mm)
{
}
static inline bool simple_lmk_victim(void)
{
	return false;
}
#endif

#endif /* _SIMPLE_LMK_H_ */
