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
static const char *ng0 = "/home/bruno/Documentos/WorkSpace/ISE/eth2/tri_mode_eth_mac/example_design/tri_mode_eth_mac_example_design.vhd";
extern char *IEEE_P_2592010699;



static void work_a_3366461247_2543805730_p_0(char *t0)
{
    unsigned char t1;
    char *t2;
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
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    int t20;

LAB0:    xsi_set_current_line(433, ng0);
    t2 = (t0 + 6272U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 19752);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(434, ng0);
    t4 = (t0 + 7112U);
    t8 = *((char **)t4);
    t9 = *((unsigned char *)t8);
    t10 = (t9 == (unsigned char)3);
    if (t10 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(438, ng0);
    t2 = (t0 + 20088);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_delta(t2, 5U, 1, 0LL);
    xsi_set_current_line(439, ng0);
    t2 = (t0 + 7432U);
    t4 = *((char **)t2);
    t17 = (5 - 4);
    t18 = (t17 * 1U);
    t19 = (0 + t18);
    t2 = (t4 + t19);
    t5 = (t0 + 20088);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t2, 5U);
    xsi_driver_first_trans_delta(t5, 0U, 5U, 0LL);
    xsi_set_current_line(440, ng0);
    t2 = (t0 + 7432U);
    t4 = *((char **)t2);
    t20 = (5 - 5);
    t17 = (t20 * -1);
    t18 = (1U * t17);
    t19 = (0 + t18);
    t2 = (t4 + t19);
    t1 = *((unsigned char *)t2);
    t5 = (t0 + 20152);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t1;
    xsi_driver_first_trans_fast(t5);

LAB9:    goto LAB3;

LAB5:    t4 = (t0 + 6312U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

LAB8:    xsi_set_current_line(435, ng0);
    t4 = xsi_get_transient_memory(6U);
    memset(t4, 0, 6U);
    t11 = t4;
    memset(t11, (unsigned char)3, 6U);
    t12 = (t0 + 20088);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t4, 6U);
    xsi_driver_first_trans_fast(t12);
    xsi_set_current_line(436, ng0);
    t2 = (t0 + 20152);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    goto LAB9;

}

static void work_a_3366461247_2543805730_p_1(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(452, ng0);

LAB3:    t1 = (t0 + 6312U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 20216);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast(t1);

LAB2:    t8 = (t0 + 19768);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3366461247_2543805730_p_2(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(453, ng0);

LAB3:    t1 = (t0 + 6312U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 20280);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast(t1);

LAB2:    t8 = (t0 + 19784);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3366461247_2543805730_p_3(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(457, ng0);

LAB3:    t1 = (t0 + 7592U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 20344);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast(t1);

LAB2:    t8 = (t0 + 19800);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3366461247_2543805730_p_4(char *t0)
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
    char *t10;
    unsigned char t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;

LAB0:    xsi_set_current_line(463, ng0);
    t1 = (t0 + 12872U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB3;

LAB4:
LAB5:    t9 = (t0 + 12712U);
    t10 = *((char **)t9);
    t11 = *((unsigned char *)t10);
    t9 = (t0 + 20408);
    t12 = (t9 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = t11;
    xsi_driver_first_trans_fast_port(t9);

LAB2:    t16 = (t0 + 19816);
    *((int *)t16) = 1;

LAB1:    return;
LAB3:    t1 = (t0 + 20408);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)4;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB2;

LAB6:    goto LAB2;

}

static void work_a_3366461247_2543805730_p_5(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(467, ng0);
    t1 = (t0 + 4552U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 20472);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast(t1);
    t1 = (t0 + 19832);
    *((int *)t1) = 1;

LAB1:    return;
}

static void work_a_3366461247_2543805730_p_6(char *t0)
{
    char t18[16];
    char t20[16];
    unsigned char t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    unsigned char t9;
    unsigned char t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    unsigned char t17;
    char *t19;
    char *t21;
    char *t22;
    int t23;
    unsigned int t24;
    unsigned char t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;

LAB0:    xsi_set_current_line(476, ng0);
    t2 = (t0 + 6432U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 19848);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(477, ng0);
    t4 = (t0 + 9832U);
    t8 = *((char **)t4);
    t9 = *((unsigned char *)t8);
    t10 = (t9 == (unsigned char)3);
    if (t10 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(481, ng0);
    t2 = (t0 + 10312U);
    t4 = *((char **)t2);
    t12 = (27 - 26);
    t13 = (t12 * 1U);
    t14 = (0 + t13);
    t2 = (t4 + t14);
    t8 = ((IEEE_P_2592010699) + 4000);
    t11 = (t20 + 0U);
    t15 = (t11 + 0U);
    *((int *)t15) = 26;
    t15 = (t11 + 4U);
    *((int *)t15) = 0;
    t15 = (t11 + 8U);
    *((int *)t15) = -1;
    t23 = (0 - 26);
    t24 = (t23 * -1);
    t24 = (t24 + 1);
    t15 = (t11 + 12U);
    *((unsigned int *)t15) = t24;
    t5 = xsi_base_array_concat(t5, t18, t8, (char)97, t2, t20, (char)99, (unsigned char)2, (char)101);
    t24 = (27U + 1U);
    t1 = (28U != t24);
    if (t1 == 1)
        goto LAB13;

LAB14:    t15 = (t0 + 20536);
    t16 = (t15 + 56U);
    t19 = *((char **)t16);
    t21 = (t19 + 56U);
    t22 = *((char **)t21);
    memcpy(t22, t5, 28U);
    xsi_driver_first_trans_fast(t15);
    xsi_set_current_line(482, ng0);
    t2 = (t0 + 10472U);
    t4 = *((char **)t2);
    t12 = (27 - 26);
    t13 = (t12 * 1U);
    t14 = (0 + t13);
    t2 = (t4 + t14);
    t8 = ((IEEE_P_2592010699) + 4000);
    t11 = (t20 + 0U);
    t15 = (t11 + 0U);
    *((int *)t15) = 26;
    t15 = (t11 + 4U);
    *((int *)t15) = 0;
    t15 = (t11 + 8U);
    *((int *)t15) = -1;
    t23 = (0 - 26);
    t24 = (t23 * -1);
    t24 = (t24 + 1);
    t15 = (t11 + 12U);
    *((unsigned int *)t15) = t24;
    t5 = xsi_base_array_concat(t5, t18, t8, (char)97, t2, t20, (char)99, (unsigned char)2, (char)101);
    t24 = (27U + 1U);
    t1 = (28U != t24);
    if (t1 == 1)
        goto LAB15;

LAB16:    t15 = (t0 + 20600);
    t16 = (t15 + 56U);
    t19 = *((char **)t16);
    t21 = (t19 + 56U);
    t22 = *((char **)t21);
    memcpy(t22, t5, 28U);
    xsi_driver_first_trans_fast(t15);

LAB9:    goto LAB3;

LAB5:    t4 = (t0 + 6472U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

LAB8:    xsi_set_current_line(478, ng0);
    t4 = (t0 + 10312U);
    t11 = *((char **)t4);
    t12 = (27 - 26);
    t13 = (t12 * 1U);
    t14 = (0 + t13);
    t4 = (t11 + t14);
    t15 = (t0 + 9832U);
    t16 = *((char **)t15);
    t17 = *((unsigned char *)t16);
    t19 = ((IEEE_P_2592010699) + 4000);
    t21 = (t20 + 0U);
    t22 = (t21 + 0U);
    *((int *)t22) = 26;
    t22 = (t21 + 4U);
    *((int *)t22) = 0;
    t22 = (t21 + 8U);
    *((int *)t22) = -1;
    t23 = (0 - 26);
    t24 = (t23 * -1);
    t24 = (t24 + 1);
    t22 = (t21 + 12U);
    *((unsigned int *)t22) = t24;
    t15 = xsi_base_array_concat(t15, t18, t19, (char)97, t4, t20, (char)99, t17, (char)101);
    t24 = (27U + 1U);
    t25 = (28U != t24);
    if (t25 == 1)
        goto LAB11;

LAB12:    t22 = (t0 + 20536);
    t26 = (t22 + 56U);
    t27 = *((char **)t26);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    memcpy(t29, t15, 28U);
    xsi_driver_first_trans_fast(t22);
    xsi_set_current_line(479, ng0);
    t2 = (t0 + 9672U);
    t4 = *((char **)t2);
    t2 = (t0 + 20600);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t11 = (t8 + 56U);
    t15 = *((char **)t11);
    memcpy(t15, t4, 28U);
    xsi_driver_first_trans_fast(t2);
    goto LAB9;

LAB11:    xsi_size_not_matching(28U, t24, 0);
    goto LAB12;

LAB13:    xsi_size_not_matching(28U, t24, 0);
    goto LAB14;

LAB15:    xsi_size_not_matching(28U, t24, 0);
    goto LAB16;

}

static void work_a_3366461247_2543805730_p_7(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned char t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;

LAB0:    xsi_set_current_line(488, ng0);

LAB3:    t1 = (t0 + 10472U);
    t2 = *((char **)t1);
    t3 = (27 - 27);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t0 + 20664);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = t7;
    xsi_driver_first_trans_fast_port(t8);

LAB2:    t13 = (t0 + 19864);
    *((int *)t13) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3366461247_2543805730_p_8(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned char t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;

LAB0:    xsi_set_current_line(490, ng0);

LAB3:    t1 = (t0 + 10312U);
    t2 = *((char **)t1);
    t3 = (27 - 27);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t0 + 20728);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = t7;
    xsi_driver_first_trans_fast_port(t8);

LAB2:    t13 = (t0 + 19880);
    *((int *)t13) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3366461247_2543805730_p_9(char *t0)
{
    char t18[16];
    char t20[16];
    unsigned char t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    unsigned char t9;
    unsigned char t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    unsigned char t17;
    char *t19;
    char *t21;
    char *t22;
    int t23;
    unsigned int t24;
    unsigned char t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;

LAB0:    xsi_set_current_line(499, ng0);
    t2 = (t0 + 6272U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 19896);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(500, ng0);
    t4 = (t0 + 10152U);
    t8 = *((char **)t4);
    t9 = *((unsigned char *)t8);
    t10 = (t9 == (unsigned char)3);
    if (t10 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(504, ng0);
    t2 = (t0 + 10632U);
    t4 = *((char **)t2);
    t12 = (31 - 30);
    t13 = (t12 * 1U);
    t14 = (0 + t13);
    t2 = (t4 + t14);
    t8 = ((IEEE_P_2592010699) + 4000);
    t11 = (t20 + 0U);
    t15 = (t11 + 0U);
    *((int *)t15) = 30;
    t15 = (t11 + 4U);
    *((int *)t15) = 0;
    t15 = (t11 + 8U);
    *((int *)t15) = -1;
    t23 = (0 - 30);
    t24 = (t23 * -1);
    t24 = (t24 + 1);
    t15 = (t11 + 12U);
    *((unsigned int *)t15) = t24;
    t5 = xsi_base_array_concat(t5, t18, t8, (char)97, t2, t20, (char)99, (unsigned char)2, (char)101);
    t24 = (31U + 1U);
    t1 = (32U != t24);
    if (t1 == 1)
        goto LAB13;

LAB14:    t15 = (t0 + 20792);
    t16 = (t15 + 56U);
    t19 = *((char **)t16);
    t21 = (t19 + 56U);
    t22 = *((char **)t21);
    memcpy(t22, t5, 32U);
    xsi_driver_first_trans_fast(t15);
    xsi_set_current_line(505, ng0);
    t2 = (t0 + 10792U);
    t4 = *((char **)t2);
    t12 = (31 - 30);
    t13 = (t12 * 1U);
    t14 = (0 + t13);
    t2 = (t4 + t14);
    t8 = ((IEEE_P_2592010699) + 4000);
    t11 = (t20 + 0U);
    t15 = (t11 + 0U);
    *((int *)t15) = 30;
    t15 = (t11 + 4U);
    *((int *)t15) = 0;
    t15 = (t11 + 8U);
    *((int *)t15) = -1;
    t23 = (0 - 30);
    t24 = (t23 * -1);
    t24 = (t24 + 1);
    t15 = (t11 + 12U);
    *((unsigned int *)t15) = t24;
    t5 = xsi_base_array_concat(t5, t18, t8, (char)97, t2, t20, (char)99, (unsigned char)2, (char)101);
    t24 = (31U + 1U);
    t1 = (32U != t24);
    if (t1 == 1)
        goto LAB15;

LAB16:    t15 = (t0 + 20856);
    t16 = (t15 + 56U);
    t19 = *((char **)t16);
    t21 = (t19 + 56U);
    t22 = *((char **)t21);
    memcpy(t22, t5, 32U);
    xsi_driver_first_trans_fast(t15);

LAB9:    goto LAB3;

LAB5:    t4 = (t0 + 6312U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

LAB8:    xsi_set_current_line(501, ng0);
    t4 = (t0 + 10632U);
    t11 = *((char **)t4);
    t12 = (31 - 30);
    t13 = (t12 * 1U);
    t14 = (0 + t13);
    t4 = (t11 + t14);
    t15 = (t0 + 10152U);
    t16 = *((char **)t15);
    t17 = *((unsigned char *)t16);
    t19 = ((IEEE_P_2592010699) + 4000);
    t21 = (t20 + 0U);
    t22 = (t21 + 0U);
    *((int *)t22) = 30;
    t22 = (t21 + 4U);
    *((int *)t22) = 0;
    t22 = (t21 + 8U);
    *((int *)t22) = -1;
    t23 = (0 - 30);
    t24 = (t23 * -1);
    t24 = (t24 + 1);
    t22 = (t21 + 12U);
    *((unsigned int *)t22) = t24;
    t15 = xsi_base_array_concat(t15, t18, t19, (char)97, t4, t20, (char)99, t17, (char)101);
    t24 = (31U + 1U);
    t25 = (32U != t24);
    if (t25 == 1)
        goto LAB11;

LAB12:    t22 = (t0 + 20792);
    t26 = (t22 + 56U);
    t27 = *((char **)t26);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    memcpy(t29, t15, 32U);
    xsi_driver_first_trans_fast(t22);
    xsi_set_current_line(502, ng0);
    t2 = (t0 + 9992U);
    t4 = *((char **)t2);
    t2 = (t0 + 20856);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t11 = (t8 + 56U);
    t15 = *((char **)t11);
    memcpy(t15, t4, 32U);
    xsi_driver_first_trans_fast(t2);
    goto LAB9;

LAB11:    xsi_size_not_matching(32U, t24, 0);
    goto LAB12;

LAB13:    xsi_size_not_matching(32U, t24, 0);
    goto LAB14;

LAB15:    xsi_size_not_matching(32U, t24, 0);
    goto LAB16;

}

static void work_a_3366461247_2543805730_p_10(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned char t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;

LAB0:    xsi_set_current_line(511, ng0);

LAB3:    t1 = (t0 + 10792U);
    t2 = *((char **)t1);
    t3 = (31 - 31);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t0 + 20920);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = t7;
    xsi_driver_first_trans_fast_port(t8);

LAB2:    t13 = (t0 + 19912);
    *((int *)t13) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3366461247_2543805730_p_11(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned char t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;

LAB0:    xsi_set_current_line(513, ng0);

LAB3:    t1 = (t0 + 10632U);
    t2 = *((char **)t1);
    t3 = (31 - 31);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t0 + 20984);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = t7;
    xsi_driver_first_trans_fast_port(t8);

LAB2:    t13 = (t0 + 19928);
    *((int *)t13) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3366461247_2543805730_p_12(char *t0)
{
    char t18[16];
    char t20[16];
    unsigned char t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    unsigned char t9;
    unsigned char t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    unsigned char t17;
    char *t19;
    char *t21;
    char *t22;
    int t23;
    unsigned int t24;
    unsigned char t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;

LAB0:    xsi_set_current_line(521, ng0);
    t2 = (t0 + 6272U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 19944);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(522, ng0);
    t4 = (t0 + 2312U);
    t8 = *((char **)t4);
    t9 = *((unsigned char *)t8);
    t10 = (t9 == (unsigned char)3);
    if (t10 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(525, ng0);
    t2 = (t0 + 11112U);
    t4 = *((char **)t2);
    t12 = (15 - 14);
    t13 = (t12 * 1U);
    t14 = (0 + t13);
    t2 = (t4 + t14);
    t8 = ((IEEE_P_2592010699) + 4000);
    t11 = (t20 + 0U);
    t15 = (t11 + 0U);
    *((int *)t15) = 14;
    t15 = (t11 + 4U);
    *((int *)t15) = 0;
    t15 = (t11 + 8U);
    *((int *)t15) = -1;
    t23 = (0 - 14);
    t24 = (t23 * -1);
    t24 = (t24 + 1);
    t15 = (t11 + 12U);
    *((unsigned int *)t15) = t24;
    t5 = xsi_base_array_concat(t5, t18, t8, (char)97, t2, t20, (char)99, (unsigned char)2, (char)101);
    t24 = (15U + 1U);
    t1 = (16U != t24);
    if (t1 == 1)
        goto LAB13;

LAB14:    t15 = (t0 + 21048);
    t16 = (t15 + 56U);
    t19 = *((char **)t16);
    t21 = (t19 + 56U);
    t22 = *((char **)t21);
    memcpy(t22, t5, 16U);
    xsi_driver_first_trans_fast(t15);

LAB9:    xsi_set_current_line(527, ng0);
    t2 = (t0 + 10952U);
    t4 = *((char **)t2);
    t12 = (15 - 14);
    t13 = (t12 * 1U);
    t14 = (0 + t13);
    t2 = (t4 + t14);
    t5 = (t0 + 2472U);
    t8 = *((char **)t5);
    t1 = *((unsigned char *)t8);
    t11 = ((IEEE_P_2592010699) + 4000);
    t15 = (t20 + 0U);
    t16 = (t15 + 0U);
    *((int *)t16) = 14;
    t16 = (t15 + 4U);
    *((int *)t16) = 0;
    t16 = (t15 + 8U);
    *((int *)t16) = -1;
    t23 = (0 - 14);
    t24 = (t23 * -1);
    t24 = (t24 + 1);
    t16 = (t15 + 12U);
    *((unsigned int *)t16) = t24;
    t5 = xsi_base_array_concat(t5, t18, t11, (char)97, t2, t20, (char)99, t1, (char)101);
    t24 = (15U + 1U);
    t3 = (16U != t24);
    if (t3 == 1)
        goto LAB15;

LAB16:    t16 = (t0 + 21112);
    t19 = (t16 + 56U);
    t21 = *((char **)t19);
    t22 = (t21 + 56U);
    t26 = *((char **)t22);
    memcpy(t26, t5, 16U);
    xsi_driver_first_trans_fast(t16);
    goto LAB3;

LAB5:    t4 = (t0 + 6312U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

LAB8:    xsi_set_current_line(523, ng0);
    t4 = (t0 + 11112U);
    t11 = *((char **)t4);
    t12 = (15 - 14);
    t13 = (t12 * 1U);
    t14 = (0 + t13);
    t4 = (t11 + t14);
    t15 = (t0 + 2312U);
    t16 = *((char **)t15);
    t17 = *((unsigned char *)t16);
    t19 = ((IEEE_P_2592010699) + 4000);
    t21 = (t20 + 0U);
    t22 = (t21 + 0U);
    *((int *)t22) = 14;
    t22 = (t21 + 4U);
    *((int *)t22) = 0;
    t22 = (t21 + 8U);
    *((int *)t22) = -1;
    t23 = (0 - 14);
    t24 = (t23 * -1);
    t24 = (t24 + 1);
    t22 = (t21 + 12U);
    *((unsigned int *)t22) = t24;
    t15 = xsi_base_array_concat(t15, t18, t19, (char)97, t4, t20, (char)99, t17, (char)101);
    t24 = (15U + 1U);
    t25 = (16U != t24);
    if (t25 == 1)
        goto LAB11;

LAB12:    t22 = (t0 + 21048);
    t26 = (t22 + 56U);
    t27 = *((char **)t26);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    memcpy(t29, t15, 16U);
    xsi_driver_first_trans_fast(t22);
    goto LAB9;

LAB11:    xsi_size_not_matching(16U, t24, 0);
    goto LAB12;

LAB13:    xsi_size_not_matching(16U, t24, 0);
    goto LAB14;

LAB15:    xsi_size_not_matching(16U, t24, 0);
    goto LAB16;

}

static void work_a_3366461247_2543805730_p_13(char *t0)
{
    unsigned char t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;

LAB0:    xsi_set_current_line(538, ng0);
    t2 = (t0 + 6112U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 19960);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(539, ng0);
    t4 = (t0 + 5032U);
    t8 = *((char **)t4);
    t4 = (t0 + 21176);
    t9 = (t4 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t8, 2U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(540, ng0);
    t2 = (t0 + 5192U);
    t4 = *((char **)t2);
    t2 = (t0 + 21240);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t4, 10U);
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(541, ng0);
    t2 = (t0 + 5352U);
    t4 = *((char **)t2);
    t2 = (t0 + 21304);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t4, 32U);
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(542, ng0);
    t2 = (t0 + 5512U);
    t4 = *((char **)t2);
    t1 = *((unsigned char *)t4);
    t2 = (t0 + 21368);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = t1;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(543, ng0);
    t2 = (t0 + 5672U);
    t4 = *((char **)t2);
    t1 = *((unsigned char *)t4);
    t2 = (t0 + 21432);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = t1;
    xsi_driver_first_trans_fast(t2);
    goto LAB3;

LAB5:    t4 = (t0 + 6152U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

}

static void work_a_3366461247_2543805730_p_14(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(547, ng0);

LAB3:    t1 = (t0 + 11912U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 21496);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast(t1);

LAB2:    t8 = (t0 + 19976);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3366461247_2543805730_p_15(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(548, ng0);

LAB3:    t1 = (t0 + 12072U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 21560);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast(t1);

LAB2:    t8 = (t0 + 19992);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3366461247_2543805730_p_16(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(649, ng0);

LAB3:    t1 = (t0 + 8392U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 21624);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast(t1);

LAB2:    t8 = (t0 + 20008);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_3366461247_2543805730_init()
{
	static char *pe[] = {(void *)work_a_3366461247_2543805730_p_0,(void *)work_a_3366461247_2543805730_p_1,(void *)work_a_3366461247_2543805730_p_2,(void *)work_a_3366461247_2543805730_p_3,(void *)work_a_3366461247_2543805730_p_4,(void *)work_a_3366461247_2543805730_p_5,(void *)work_a_3366461247_2543805730_p_6,(void *)work_a_3366461247_2543805730_p_7,(void *)work_a_3366461247_2543805730_p_8,(void *)work_a_3366461247_2543805730_p_9,(void *)work_a_3366461247_2543805730_p_10,(void *)work_a_3366461247_2543805730_p_11,(void *)work_a_3366461247_2543805730_p_12,(void *)work_a_3366461247_2543805730_p_13,(void *)work_a_3366461247_2543805730_p_14,(void *)work_a_3366461247_2543805730_p_15,(void *)work_a_3366461247_2543805730_p_16};
	xsi_register_didat("work_a_3366461247_2543805730", "isim/testbench.sim/work/a_3366461247_2543805730.didat");
	xsi_register_executes(pe);
}
