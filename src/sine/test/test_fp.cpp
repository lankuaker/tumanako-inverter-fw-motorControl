/*
 * This file is part of the tumanako_vc project.
 *
 * Copyright (C) 2010 Johannes Huebner <contact@johanneshuebner.com>
 * Copyright (C) 2010 Edward Cheeseman <cheesemanedward@gmail.com>
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
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

#include "my_fp.h"
#include "test_list.h"
#include "string.h"

using namespace std;

static void TestMacros()
{
   ASSERT(FP_MUL(FP_FROMFLT(5.5), FP_FROMFLT(2.03125)) == FP_FROMFLT(5.5 * 2.03125));
   ASSERT(FP_MUL(FP_FROMFLT(5.5), FP_FROMFLT(2.03225)) == FP_FROMFLT(5.5 * 2.03125));
   ASSERT(FP_DIV(FP_FROMFLT(5.5), FP_FROMFLT(2.03125)) == FP_FROMFLT(5.5 / 2.03125));
}

static void TestItoa()
{
   char buf[10];
   ASSERT(strcmp(fp_itoa(buf, FP_FROMFLT(2.03125)), "2.03") == 0);
   ASSERT(strcmp(fp_itoa(buf, FP_FROMFLT(-2.125)), "-2.12") == 0);
   ASSERT(strcmp(fp_itoa(buf, FP_FROMFLT(2.15624)), "2.12") == 0);
   ASSERT(strcmp(fp_itoa(buf, FP_FROMFLT(2.15625)), "2.15") == 0);
}

static void TestAtoi()
{
   ASSERT(fp_atoi("-2.5") == FP_FROMFLT(-2.5));
   ASSERT(fp_atoi("2.155") == FP_FROMFLT(2.15));
}

void FPTest::RunTest()
{
   TestMacros();
   TestItoa();
   TestAtoi();
}
