/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/bruno/Documentos/WorkSpace/ISE/eth2/tri_mode_eth_mac/example_design/address_swap_module.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_2763492388968962707_503743352(char *, char *, unsigned int , unsigned int );
unsigned char ieee_p_2592010699_sub_374109322130769762_503743352(char *, unsigned char );


static void work_a_2676204058_0468659574_p_0(char *t0)
{
    char t17[16];
    char t19[32];
    char *t1;
    unsigned char t2;
    unsigned char t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    unsigned char t9;
    unsigned char t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t18;
    char *t20;
    char *t21;
    int t22;
    unsigned int t23;
    char *t24;
    int t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;

LAB0:    xsi_set_current_line(135, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 10024);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(136, ng0);
    t4 = (t0 + 2952U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    if (t7 == 1)
        goto LAB8;

LAB9:    t3 = (unsigned char)0;

LAB10:    if (t3 != 0)
        goto LAB5;

LAB7:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(137, ng0);
    t4 = (t0 + 1352U);
    t11 = *((char **)t4);
    t4 = (t0 + 3752U);
    t12 = *((char **)t4);
    t13 = (0 - 0);
    t14 = (t13 * 8U);
    t15 = (0 + t14);
    t4 = (t12 + t15);
    t18 = (t0 + 11936);
    t20 = (t19 + 0U);
    t21 = (t20 + 0U);
    *((int *)t21) = 0;
    t21 = (t20 + 4U);
    *((int *)t21) = 4;
    t21 = (t20 + 8U);
    *((int *)t21) = 1;
    t22 = (4 - 0);
    t23 = (t22 * 1);
    t23 = (t23 + 1);
    t21 = (t20 + 12U);
    *((unsigned int *)t21) = t23;
    t21 = (t19 + 16U);
    t24 = (t21 + 0U);
    *((int *)t24) = 7;
    t24 = (t21 + 4U);
    *((int *)t24) = 0;
    t24 = (t21 + 8U);
    *((int *)t24) = -1;
    t25 = (0 - 7);
    t23 = (t25 * -1);
    t23 = (t23 + 1);
    t24 = (t21 + 12U);
    *((unsigned int *)t24) = t23;
    t16 = xsi_base_array_concat(t16, t17, t18, (char)109, t11, (char)97, t4, t19, (char)101);
    t24 = (t0 + 10344);
    t26 = (t24 + 56U);
    t27 = *((char **)t26);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    memcpy(t29, t16, 48U);
    xsi_driver_first_trans_fast(t24);
    goto LAB6;

LAB8:    t4 = (t0 + 3432U);
    t8 = *((char **)t4);
    t9 = *((unsigned char *)t8);
    t10 = (t9 == (unsigned char)3);
    t3 = t10;
    goto LAB10;

}

static void work_a_2676204058_0468659574_p_1(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;

LAB0:    xsi_set_current_line(142, ng0);

LAB3:    t1 = (t0 + 3752U);
    t2 = *((char **)t1);
    t3 = (5 - 0);
    t4 = (t3 * 1);
    t5 = (8U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = (t0 + 10408);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t1, 8U);
    xsi_driver_first_trans_fast(t7);

LAB2:    t12 = (t0 + 10040);
    *((int *)t12) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_2676204058_0468659574_p_2(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;

LAB0:    xsi_set_current_line(152, ng0);
    t1 = (t0 + 2792U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    xsi_set_current_line(155, ng0);
    t1 = (t0 + 3112U);
    t2 = *((char **)t1);
    t1 = (t0 + 10472);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 8U);
    xsi_driver_first_trans_fast(t1);

LAB3:    t1 = (t0 + 10056);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(153, ng0);
    t1 = (t0 + 1352U);
    t5 = *((char **)t1);
    t1 = (t0 + 10472);
    t6 = (t1 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t5, 8U);
    xsi_driver_first_trans_fast(t1);
    goto LAB3;

}

static void work_a_2676204058_0468659574_p_3(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    int64 t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;

LAB0:    xsi_set_current_line(166, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 10072);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(167, ng0);
    t3 = (t0 + 3432U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(168, ng0);
    t3 = (t0 + 5008U);
    t7 = *((char **)t3);
    t8 = *((int64 *)t7);
    t3 = (t0 + 3272U);
    t9 = *((char **)t3);
    t3 = (t0 + 10536);
    t10 = (t3 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t9, 8U);
    xsi_driver_first_trans_delta(t3, 0U, 8U, t8);
    t14 = (t0 + 10536);
    xsi_driver_intertial_reject(t14, t8, t8);
    goto LAB6;

}

static void work_a_2676204058_0468659574_p_4(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;

LAB0:    xsi_set_current_line(173, ng0);

LAB3:    t1 = (t0 + 2632U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = ieee_p_2592010699_sub_374109322130769762_503743352(IEEE_P_2592010699, t3);
    t1 = (t0 + 10600);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = t4;
    xsi_driver_first_trans_fast(t1);

LAB2:    t9 = (t0 + 10088);
    *((int *)t9) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_2676204058_0468659574_p_5(char *t0)
{
    char t15[16];
    char t17[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    unsigned char t8;
    unsigned char t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t16;
    char *t18;
    char *t19;
    int t20;
    unsigned int t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;

LAB0:    xsi_set_current_line(181, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 10104);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(182, ng0);
    t3 = (t0 + 3432U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(183, ng0);
    t3 = (t0 + 1512U);
    t7 = *((char **)t3);
    t8 = *((unsigned char *)t7);
    t9 = ieee_p_2592010699_sub_374109322130769762_503743352(IEEE_P_2592010699, t8);
    t3 = (t0 + 4072U);
    t10 = *((char **)t3);
    t11 = (0 - 0);
    t12 = (t11 * 1U);
    t13 = (0 + t12);
    t3 = (t10 + t13);
    t16 = (t0 + 12144);
    t18 = (t17 + 0U);
    t19 = (t18 + 0U);
    *((int *)t19) = 0;
    t19 = (t18 + 4U);
    *((int *)t19) = 4;
    t19 = (t18 + 8U);
    *((int *)t19) = 1;
    t20 = (4 - 0);
    t21 = (t20 * 1);
    t21 = (t21 + 1);
    t19 = (t18 + 12U);
    *((unsigned int *)t19) = t21;
    t14 = xsi_base_array_concat(t14, t15, t16, (char)99, t9, (char)97, t3, t17, (char)101);
    t19 = (t0 + 10664);
    t22 = (t19 + 56U);
    t23 = *((char **)t22);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    memcpy(t25, t14, 6U);
    xsi_driver_first_trans_fast(t19);
    goto LAB6;

}

static void work_a_2676204058_0468659574_p_6(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;

LAB0:    xsi_set_current_line(190, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 10120);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(191, ng0);
    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(194, ng0);
    t1 = (t0 + 3432U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB8;

LAB10:
LAB9:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(192, ng0);
    t3 = (t0 + 10728);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast(t3);
    goto LAB6;

LAB8:    xsi_set_current_line(195, ng0);
    t1 = (t0 + 4072U);
    t4 = *((char **)t1);
    t11 = (5 - 0);
    t12 = (t11 * 1);
    t13 = (1U * t12);
    t14 = (0 + t13);
    t1 = (t4 + t14);
    t6 = *((unsigned char *)t1);
    t7 = (t0 + 10728);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t15 = *((char **)t10);
    *((unsigned char *)t15) = t6;
    xsi_driver_first_trans_fast(t7);
    goto LAB9;

}

static void work_a_2676204058_0468659574_p_7(char *t0)
{
    char *t1;
    char *t2;
    int64 t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;

LAB0:    xsi_set_current_line(201, ng0);

LAB3:    t1 = (t0 + 5008U);
    t2 = *((char **)t1);
    t3 = *((int64 *)t2);
    t1 = (t0 + 4552U);
    t4 = *((char **)t1);
    t5 = *((unsigned char *)t4);
    t6 = ieee_p_2592010699_sub_374109322130769762_503743352(IEEE_P_2592010699, t5);
    t1 = (t0 + 10792);
    t7 = (t1 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = t6;
    xsi_driver_first_trans_delta(t1, 0U, 1, t3);
    t11 = (t0 + 10792);
    xsi_driver_intertial_reject(t11, t3, t3);

LAB2:    t12 = (t0 + 10136);
    *((int *)t12) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_2676204058_0468659574_p_8(char *t0)
{
    char t15[16];
    char t17[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    unsigned char t8;
    unsigned char t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t16;
    char *t18;
    char *t19;
    int t20;
    unsigned int t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;

LAB0:    xsi_set_current_line(209, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 10152);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(210, ng0);
    t3 = (t0 + 3432U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(211, ng0);
    t3 = (t0 + 1672U);
    t7 = *((char **)t3);
    t8 = *((unsigned char *)t7);
    t9 = ieee_p_2592010699_sub_374109322130769762_503743352(IEEE_P_2592010699, t8);
    t3 = (t0 + 3912U);
    t10 = *((char **)t3);
    t11 = (0 - 0);
    t12 = (t11 * 1U);
    t13 = (0 + t12);
    t3 = (t10 + t13);
    t16 = (t0 + 12144);
    t18 = (t17 + 0U);
    t19 = (t18 + 0U);
    *((int *)t19) = 0;
    t19 = (t18 + 4U);
    *((int *)t19) = 4;
    t19 = (t18 + 8U);
    *((int *)t19) = 1;
    t20 = (4 - 0);
    t21 = (t20 * 1);
    t21 = (t21 + 1);
    t19 = (t18 + 12U);
    *((unsigned int *)t19) = t21;
    t14 = xsi_base_array_concat(t14, t15, t16, (char)99, t9, (char)97, t3, t17, (char)101);
    t19 = (t0 + 10856);
    t22 = (t19 + 56U);
    t23 = *((char **)t22);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    memcpy(t25, t14, 6U);
    xsi_driver_first_trans_fast(t19);
    goto LAB6;

}

static void work_a_2676204058_0468659574_p_9(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;

LAB0:    xsi_set_current_line(218, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 10168);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(219, ng0);
    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(222, ng0);
    t1 = (t0 + 3432U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB8;

LAB10:
LAB9:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(220, ng0);
    t3 = (t0 + 10920);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast(t3);
    goto LAB6;

LAB8:    xsi_set_current_line(223, ng0);
    t1 = (t0 + 3912U);
    t4 = *((char **)t1);
    t11 = (5 - 0);
    t12 = (t11 * 1);
    t13 = (1U * t12);
    t14 = (0 + t13);
    t1 = (t4 + t14);
    t6 = *((unsigned char *)t1);
    t7 = (t0 + 10920);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t15 = *((char **)t10);
    *((unsigned char *)t15) = t6;
    xsi_driver_first_trans_fast(t7);
    goto LAB9;

}

static void work_a_2676204058_0468659574_p_10(char *t0)
{
    char *t1;
    char *t2;
    int64 t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;

LAB0:    xsi_set_current_line(229, ng0);

LAB3:    t1 = (t0 + 5008U);
    t2 = *((char **)t1);
    t3 = *((int64 *)t2);
    t1 = (t0 + 4392U);
    t4 = *((char **)t1);
    t5 = *((unsigned char *)t4);
    t6 = ieee_p_2592010699_sub_374109322130769762_503743352(IEEE_P_2592010699, t5);
    t1 = (t0 + 10984);
    t7 = (t1 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = t6;
    xsi_driver_first_trans_delta(t1, 0U, 1, t3);
    t11 = (t0 + 10984);
    xsi_driver_intertial_reject(t11, t3, t3);

LAB2:    t12 = (t0 + 10184);
    *((int *)t12) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_2676204058_0468659574_p_11(char *t0)
{
    char t15[16];
    char t17[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    unsigned char t8;
    unsigned char t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t16;
    char *t18;
    char *t19;
    int t20;
    unsigned int t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;

LAB0:    xsi_set_current_line(237, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 10200);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(238, ng0);
    t3 = (t0 + 3432U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(239, ng0);
    t3 = (t0 + 1832U);
    t7 = *((char **)t3);
    t8 = *((unsigned char *)t7);
    t9 = ieee_p_2592010699_sub_374109322130769762_503743352(IEEE_P_2592010699, t8);
    t3 = (t0 + 4232U);
    t10 = *((char **)t3);
    t11 = (0 - 0);
    t12 = (t11 * 1U);
    t13 = (0 + t12);
    t3 = (t10 + t13);
    t16 = (t0 + 12144);
    t18 = (t17 + 0U);
    t19 = (t18 + 0U);
    *((int *)t19) = 0;
    t19 = (t18 + 4U);
    *((int *)t19) = 4;
    t19 = (t18 + 8U);
    *((int *)t19) = 1;
    t20 = (4 - 0);
    t21 = (t20 * 1);
    t21 = (t21 + 1);
    t19 = (t18 + 12U);
    *((unsigned int *)t19) = t21;
    t14 = xsi_base_array_concat(t14, t15, t16, (char)99, t9, (char)97, t3, t17, (char)101);
    t19 = (t0 + 11048);
    t22 = (t19 + 56U);
    t23 = *((char **)t22);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    memcpy(t25, t14, 6U);
    xsi_driver_first_trans_fast(t19);
    goto LAB6;

}

static void work_a_2676204058_0468659574_p_12(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;

LAB0:    xsi_set_current_line(246, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 10216);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(247, ng0);
    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(250, ng0);
    t1 = (t0 + 3432U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB8;

LAB10:
LAB9:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(248, ng0);
    t3 = (t0 + 11112);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast(t3);
    goto LAB6;

LAB8:    xsi_set_current_line(251, ng0);
    t1 = (t0 + 4232U);
    t4 = *((char **)t1);
    t11 = (5 - 0);
    t12 = (t11 * 1);
    t13 = (1U * t12);
    t14 = (0 + t13);
    t1 = (t4 + t14);
    t6 = *((unsigned char *)t1);
    t7 = (t0 + 11112);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t15 = *((char **)t10);
    *((unsigned char *)t15) = t6;
    xsi_driver_first_trans_fast(t7);
    goto LAB9;

}

static void work_a_2676204058_0468659574_p_13(char *t0)
{
    char *t1;
    char *t2;
    int64 t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;

LAB0:    xsi_set_current_line(257, ng0);

LAB3:    t1 = (t0 + 5008U);
    t2 = *((char **)t1);
    t3 = *((int64 *)t2);
    t1 = (t0 + 4712U);
    t4 = *((char **)t1);
    t5 = *((unsigned char *)t4);
    t6 = ieee_p_2592010699_sub_374109322130769762_503743352(IEEE_P_2592010699, t5);
    t1 = (t0 + 11176);
    t7 = (t1 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = t6;
    xsi_driver_first_trans_delta(t1, 0U, 1, t3);
    t11 = (t0 + 11176);
    xsi_driver_intertial_reject(t11, t3, t3);

LAB2:    t12 = (t0 + 10232);
    *((int *)t12) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_2676204058_0468659574_p_14(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned char t15;
    unsigned char t16;
    char *t17;
    char *t18;
    char *t19;
    int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned char t24;
    static char *nl0[] = {&&LAB12, &&LAB13, &&LAB14, &&LAB15, &&LAB16, &&LAB17, &&LAB18, &&LAB19};

LAB0:    xsi_set_current_line(265, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 10248);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(266, ng0);
    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(269, ng0);
    t1 = (t0 + 3432U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB8;

LAB10:
LAB9:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(267, ng0);
    t3 = (t0 + 11240);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)0;
    xsi_driver_first_trans_fast(t3);
    goto LAB6;

LAB8:    xsi_set_current_line(270, ng0);
    t1 = (t0 + 3592U);
    t4 = *((char **)t1);
    t6 = *((unsigned char *)t4);
    t1 = (char *)((nl0) + t6);
    goto **((char **)t1);

LAB11:    goto LAB9;

LAB12:    xsi_set_current_line(272, ng0);
    t7 = (t0 + 4072U);
    t8 = *((char **)t7);
    t11 = (4 - 0);
    t12 = (t11 * 1);
    t13 = (1U * t12);
    t14 = (0 + t13);
    t7 = (t8 + t14);
    t15 = *((unsigned char *)t7);
    t16 = (t15 == (unsigned char)3);
    if (t16 != 0)
        goto LAB21;

LAB23:    xsi_set_current_line(275, ng0);
    t1 = (t0 + 11240);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB22:    goto LAB11;

LAB13:    xsi_set_current_line(279, ng0);
    t1 = (t0 + 4072U);
    t3 = *((char **)t1);
    t11 = (4 - 0);
    t12 = (t11 * 1);
    t13 = (1U * t12);
    t14 = (0 + t13);
    t1 = (t3 + t14);
    t5 = *((unsigned char *)t1);
    t6 = (t5 == (unsigned char)2);
    if (t6 == 1)
        goto LAB27;

LAB28:    t2 = (unsigned char)0;

LAB29:    t24 = (!(t2));
    if (t24 != 0)
        goto LAB24;

LAB26:    xsi_set_current_line(282, ng0);
    t1 = (t0 + 11240);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB25:    goto LAB11;

LAB14:    xsi_set_current_line(286, ng0);
    t1 = (t0 + 4072U);
    t3 = *((char **)t1);
    t11 = (4 - 0);
    t12 = (t11 * 1);
    t13 = (1U * t12);
    t14 = (0 + t13);
    t1 = (t3 + t14);
    t5 = *((unsigned char *)t1);
    t6 = (t5 == (unsigned char)2);
    if (t6 == 1)
        goto LAB33;

LAB34:    t2 = (unsigned char)0;

LAB35:    t24 = (!(t2));
    if (t24 != 0)
        goto LAB30;

LAB32:    xsi_set_current_line(289, ng0);
    t1 = (t0 + 11240);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB31:    goto LAB11;

LAB15:    xsi_set_current_line(293, ng0);
    t1 = (t0 + 4072U);
    t3 = *((char **)t1);
    t11 = (4 - 0);
    t12 = (t11 * 1);
    t13 = (1U * t12);
    t14 = (0 + t13);
    t1 = (t3 + t14);
    t5 = *((unsigned char *)t1);
    t6 = (t5 == (unsigned char)2);
    if (t6 == 1)
        goto LAB39;

LAB40:    t2 = (unsigned char)0;

LAB41:    t24 = (!(t2));
    if (t24 != 0)
        goto LAB36;

LAB38:    xsi_set_current_line(296, ng0);
    t1 = (t0 + 11240);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB37:    goto LAB11;

LAB16:    xsi_set_current_line(300, ng0);
    t1 = (t0 + 4072U);
    t3 = *((char **)t1);
    t11 = (4 - 0);
    t12 = (t11 * 1);
    t13 = (1U * t12);
    t14 = (0 + t13);
    t1 = (t3 + t14);
    t5 = *((unsigned char *)t1);
    t6 = (t5 == (unsigned char)2);
    if (t6 == 1)
        goto LAB45;

LAB46:    t2 = (unsigned char)0;

LAB47:    t24 = (!(t2));
    if (t24 != 0)
        goto LAB42;

LAB44:    xsi_set_current_line(303, ng0);
    t1 = (t0 + 11240);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB43:    goto LAB11;

LAB17:    xsi_set_current_line(307, ng0);
    t1 = (t0 + 4072U);
    t3 = *((char **)t1);
    t11 = (4 - 0);
    t12 = (t11 * 1);
    t13 = (1U * t12);
    t14 = (0 + t13);
    t1 = (t3 + t14);
    t5 = *((unsigned char *)t1);
    t6 = (t5 == (unsigned char)2);
    if (t6 == 1)
        goto LAB51;

LAB52:    t2 = (unsigned char)0;

LAB53:    t24 = (!(t2));
    if (t24 != 0)
        goto LAB48;

LAB50:    xsi_set_current_line(310, ng0);
    t1 = (t0 + 11240);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB49:    goto LAB11;

LAB18:    xsi_set_current_line(314, ng0);
    t1 = (t0 + 4072U);
    t3 = *((char **)t1);
    t11 = (4 - 0);
    t12 = (t11 * 1);
    t13 = (1U * t12);
    t14 = (0 + t13);
    t1 = (t3 + t14);
    t5 = *((unsigned char *)t1);
    t6 = (t5 == (unsigned char)2);
    if (t6 == 1)
        goto LAB57;

LAB58:    t2 = (unsigned char)0;

LAB59:    t24 = (!(t2));
    if (t24 != 0)
        goto LAB54;

LAB56:    xsi_set_current_line(317, ng0);
    t1 = (t0 + 11240);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB55:    goto LAB11;

LAB19:    xsi_set_current_line(321, ng0);
    t1 = (t0 + 4072U);
    t3 = *((char **)t1);
    t11 = (4 - 0);
    t12 = (t11 * 1);
    t13 = (1U * t12);
    t14 = (0 + t13);
    t1 = (t3 + t14);
    t5 = *((unsigned char *)t1);
    t6 = (t5 == (unsigned char)2);
    if (t6 == 1)
        goto LAB63;

LAB64:    t2 = (unsigned char)0;

LAB65:    t24 = (!(t2));
    if (t24 != 0)
        goto LAB60;

LAB62:    xsi_set_current_line(324, ng0);
    t1 = (t0 + 11240);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB61:    goto LAB11;

LAB20:    xsi_set_current_line(328, ng0);
    t1 = (t0 + 11240);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB11;

LAB21:    xsi_set_current_line(273, ng0);
    t9 = (t0 + 11240);
    t10 = (t9 + 56U);
    t17 = *((char **)t10);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    *((unsigned char *)t19) = (unsigned char)1;
    xsi_driver_first_trans_fast(t9);
    goto LAB22;

LAB24:    xsi_set_current_line(280, ng0);
    t8 = (t0 + 11240);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t17 = (t10 + 56U);
    t18 = *((char **)t17);
    *((unsigned char *)t18) = (unsigned char)2;
    xsi_driver_first_trans_fast(t8);
    goto LAB25;

LAB27:    t4 = (t0 + 3912U);
    t7 = *((char **)t4);
    t20 = (4 - 0);
    t21 = (t20 * 1);
    t22 = (1U * t21);
    t23 = (0 + t22);
    t4 = (t7 + t23);
    t15 = *((unsigned char *)t4);
    t16 = (t15 == (unsigned char)3);
    t2 = t16;
    goto LAB29;

LAB30:    xsi_set_current_line(287, ng0);
    t8 = (t0 + 11240);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t17 = (t10 + 56U);
    t18 = *((char **)t17);
    *((unsigned char *)t18) = (unsigned char)3;
    xsi_driver_first_trans_fast(t8);
    goto LAB31;

LAB33:    t4 = (t0 + 3912U);
    t7 = *((char **)t4);
    t20 = (4 - 0);
    t21 = (t20 * 1);
    t22 = (1U * t21);
    t23 = (0 + t22);
    t4 = (t7 + t23);
    t15 = *((unsigned char *)t4);
    t16 = (t15 == (unsigned char)3);
    t2 = t16;
    goto LAB35;

LAB36:    xsi_set_current_line(294, ng0);
    t8 = (t0 + 11240);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t17 = (t10 + 56U);
    t18 = *((char **)t17);
    *((unsigned char *)t18) = (unsigned char)4;
    xsi_driver_first_trans_fast(t8);
    goto LAB37;

LAB39:    t4 = (t0 + 3912U);
    t7 = *((char **)t4);
    t20 = (4 - 0);
    t21 = (t20 * 1);
    t22 = (1U * t21);
    t23 = (0 + t22);
    t4 = (t7 + t23);
    t15 = *((unsigned char *)t4);
    t16 = (t15 == (unsigned char)3);
    t2 = t16;
    goto LAB41;

LAB42:    xsi_set_current_line(301, ng0);
    t8 = (t0 + 11240);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t17 = (t10 + 56U);
    t18 = *((char **)t17);
    *((unsigned char *)t18) = (unsigned char)5;
    xsi_driver_first_trans_fast(t8);
    goto LAB43;

LAB45:    t4 = (t0 + 3912U);
    t7 = *((char **)t4);
    t20 = (4 - 0);
    t21 = (t20 * 1);
    t22 = (1U * t21);
    t23 = (0 + t22);
    t4 = (t7 + t23);
    t15 = *((unsigned char *)t4);
    t16 = (t15 == (unsigned char)3);
    t2 = t16;
    goto LAB47;

LAB48:    xsi_set_current_line(308, ng0);
    t8 = (t0 + 11240);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t17 = (t10 + 56U);
    t18 = *((char **)t17);
    *((unsigned char *)t18) = (unsigned char)6;
    xsi_driver_first_trans_fast(t8);
    goto LAB49;

LAB51:    t4 = (t0 + 3912U);
    t7 = *((char **)t4);
    t20 = (4 - 0);
    t21 = (t20 * 1);
    t22 = (1U * t21);
    t23 = (0 + t22);
    t4 = (t7 + t23);
    t15 = *((unsigned char *)t4);
    t16 = (t15 == (unsigned char)3);
    t2 = t16;
    goto LAB53;

LAB54:    xsi_set_current_line(315, ng0);
    t8 = (t0 + 11240);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t17 = (t10 + 56U);
    t18 = *((char **)t17);
    *((unsigned char *)t18) = (unsigned char)7;
    xsi_driver_first_trans_fast(t8);
    goto LAB55;

LAB57:    t4 = (t0 + 3912U);
    t7 = *((char **)t4);
    t20 = (4 - 0);
    t21 = (t20 * 1);
    t22 = (1U * t21);
    t23 = (0 + t22);
    t4 = (t7 + t23);
    t15 = *((unsigned char *)t4);
    t16 = (t15 == (unsigned char)3);
    t2 = t16;
    goto LAB59;

LAB60:    xsi_set_current_line(322, ng0);
    t8 = (t0 + 11240);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t17 = (t10 + 56U);
    t18 = *((char **)t17);
    *((unsigned char *)t18) = (unsigned char)7;
    xsi_driver_first_trans_fast(t8);
    goto LAB61;

LAB63:    t4 = (t0 + 3912U);
    t7 = *((char **)t4);
    t20 = (4 - 0);
    t21 = (t20 * 1);
    t22 = (1U * t21);
    t23 = (0 + t22);
    t4 = (t7 + t23);
    t15 = *((unsigned char *)t4);
    t16 = (t15 == (unsigned char)3);
    t2 = t16;
    goto LAB65;

}

static void work_a_2676204058_0468659574_p_15(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    static char *nl0[] = {&&LAB3, &&LAB4, &&LAB5, &&LAB6, &&LAB7, &&LAB8, &&LAB9, &&LAB10};

LAB0:    xsi_set_current_line(343, ng0);
    t1 = (t0 + 3592U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (char *)((nl0) + t3);
    goto **((char **)t1);

LAB2:    t1 = (t0 + 10264);
    *((int *)t1) = 1;

LAB1:    return;
LAB3:    xsi_set_current_line(345, ng0);
    t4 = (t0 + 11304);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(346, ng0);
    t1 = (t0 + 11368);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB4:    xsi_set_current_line(349, ng0);
    t1 = (t0 + 11304);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(350, ng0);
    t1 = (t0 + 11368);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB5:    xsi_set_current_line(353, ng0);
    t1 = (t0 + 11304);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(354, ng0);
    t1 = (t0 + 11368);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB6:    xsi_set_current_line(357, ng0);
    t1 = (t0 + 11304);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(358, ng0);
    t1 = (t0 + 11368);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB7:    xsi_set_current_line(361, ng0);
    t1 = (t0 + 11304);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(362, ng0);
    t1 = (t0 + 11368);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB8:    xsi_set_current_line(365, ng0);
    t1 = (t0 + 11304);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(366, ng0);
    t1 = (t0 + 11368);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB9:    xsi_set_current_line(369, ng0);
    t1 = (t0 + 11304);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(370, ng0);
    t1 = (t0 + 11368);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB10:    xsi_set_current_line(373, ng0);
    t1 = (t0 + 11304);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(374, ng0);
    t1 = (t0 + 11368);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB11:    xsi_set_current_line(377, ng0);
    t1 = (t0 + 11304);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(378, ng0);
    t1 = (t0 + 11368);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

}


extern void work_a_2676204058_0468659574_init()
{
	static char *pe[] = {(void *)work_a_2676204058_0468659574_p_0,(void *)work_a_2676204058_0468659574_p_1,(void *)work_a_2676204058_0468659574_p_2,(void *)work_a_2676204058_0468659574_p_3,(void *)work_a_2676204058_0468659574_p_4,(void *)work_a_2676204058_0468659574_p_5,(void *)work_a_2676204058_0468659574_p_6,(void *)work_a_2676204058_0468659574_p_7,(void *)work_a_2676204058_0468659574_p_8,(void *)work_a_2676204058_0468659574_p_9,(void *)work_a_2676204058_0468659574_p_10,(void *)work_a_2676204058_0468659574_p_11,(void *)work_a_2676204058_0468659574_p_12,(void *)work_a_2676204058_0468659574_p_13,(void *)work_a_2676204058_0468659574_p_14,(void *)work_a_2676204058_0468659574_p_15};
	xsi_register_didat("work_a_2676204058_0468659574", "isim/testbench.sim/work/a_2676204058_0468659574.didat");
	xsi_register_executes(pe);
}
