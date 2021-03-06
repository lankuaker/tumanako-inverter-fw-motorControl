/*
 * This file is part of the tumanako_vc project.
 *
 * Copyright (C) 2010 Johannes Huebner <contact@johanneshuebner.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef STM32_TIMSCHED_H_INCLUDED
#define STM32_TIMSCHED_H_INCLUDED
#include <stdint.h>

typedef enum _PrioGrp
{
    PRIO_GRP1 = 0, PRIO_GRPLAST
} SCHED_PRIOGRP;

#define TIM_MAXCHAN       4

#define NUMCHAN_TIM2      4

/* Timer table: */
/* Timer number, timer channels, priority group */
#define PRIORITY_GROUPS \
    PRIOGRP_ENTRY(2, NUMCHAN_TIM2, PRIO_GRP1)

/* Map timers to priority groups */
#define PRIOGRP_ENTRY(t,c,g) PRIOGRP_TIM##t = g,
enum
{
    PRIORITY_GROUPS
    PRIOGRP_TIMLAST
};
#undef PRIOGRP_ENTRY


/* Calculates task function index from timer number and channel number */
#define FUNCIDX_TIMx(t,c) ((PRIOGRP_TIM##t) * TIM_MAXCHAN + (c))
#define FUNCIDX_GRPx(g,c) (TIM_MAXCHAN * (g) + (c))

#define MAX_TASKS 4

#ifdef __cplusplus
extern "C"
{
#endif

int create_task(void (*Function)(void), SCHED_PRIOGRP PrioGrp, uint8_t PrioInGrp, uint16_t Period);
void change_interval(SCHED_PRIOGRP PrioGrp, uint8_t PrioInGrp, uint16_t Period);
void init_timsched(void);

#ifdef __cplusplus
}
#endif

#endif // STM32_TIMSCHED_H_INCLUDED
