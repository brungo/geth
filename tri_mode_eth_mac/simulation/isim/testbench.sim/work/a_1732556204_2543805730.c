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
static const char *ng0 = "/home/bruno/Documentos/WorkSpace/ISE/eth2/tri_mode_eth_mac/example_design/tri_mode_eth_mac_block.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_374109322130769762_503743352(char *, unsigned char );


static void work_a_1732556204_2543805730_p_0(char *t0)
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
    int t17;
    int t18;
    int t19;
    int t20;
    int t22;
    char *t23;
    int t25;
    char *t26;
    int t28;
    char *t29;
    int t31;
    char *t32;
    int t34;
    char *t35;
    int t37;
    char *t38;
    int t40;
    char *t41;
    int t43;
    char *t44;
    int t46;
    char *t47;
    int t49;
    char *t50;
    char *t52;
    char *t53;
    char *t54;
    char *t55;
    char *t56;

LAB0:    xsi_set_current_line(427, ng0);
    t2 = (t0 + 1152U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 15920);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(428, ng0);
    t4 = (t0 + 8552U);
    t8 = *((char **)t4);
    t9 = *((unsigned char *)t8);
    t10 = (t9 == (unsigned char)3);
    if (t10 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(432, ng0);
    t2 = (t0 + 16176);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(433, ng0);
    t2 = (t0 + 8712U);
    t4 = *((char **)t2);
    t2 = (t0 + 30620);
    t17 = xsi_mem_cmp(t2, t4, 4U);
    if (t17 == 1)
        goto LAB12;

LAB27:    t8 = (t0 + 30624);
    t18 = xsi_mem_cmp(t8, t4, 4U);
    if (t18 == 1)
        goto LAB13;

LAB28:    t12 = (t0 + 30628);
    t19 = xsi_mem_cmp(t12, t4, 4U);
    if (t19 == 1)
        goto LAB14;

LAB29:    t14 = (t0 + 30632);
    t20 = xsi_mem_cmp(t14, t4, 4U);
    if (t20 == 1)
        goto LAB15;

LAB30:    t16 = (t0 + 30636);
    t22 = xsi_mem_cmp(t16, t4, 4U);
    if (t22 == 1)
        goto LAB16;

LAB31:    t23 = (t0 + 30640);
    t25 = xsi_mem_cmp(t23, t4, 4U);
    if (t25 == 1)
        goto LAB17;

LAB32:    t26 = (t0 + 30644);
    t28 = xsi_mem_cmp(t26, t4, 4U);
    if (t28 == 1)
        goto LAB18;

LAB33:    t29 = (t0 + 30648);
    t31 = xsi_mem_cmp(t29, t4, 4U);
    if (t31 == 1)
        goto LAB19;

LAB34:    t32 = (t0 + 30652);
    t34 = xsi_mem_cmp(t32, t4, 4U);
    if (t34 == 1)
        goto LAB20;

LAB35:    t35 = (t0 + 30656);
    t37 = xsi_mem_cmp(t35, t4, 4U);
    if (t37 == 1)
        goto LAB21;

LAB36:    t38 = (t0 + 30660);
    t40 = xsi_mem_cmp(t38, t4, 4U);
    if (t40 == 1)
        goto LAB22;

LAB37:    t41 = (t0 + 30664);
    t43 = xsi_mem_cmp(t41, t4, 4U);
    if (t43 == 1)
        goto LAB23;

LAB38:    t44 = (t0 + 30668);
    t46 = xsi_mem_cmp(t44, t4, 4U);
    if (t46 == 1)
        goto LAB24;

LAB39:    t47 = (t0 + 30672);
    t49 = xsi_mem_cmp(t47, t4, 4U);
    if (t49 == 1)
        goto LAB25;

LAB40:
LAB26:    xsi_set_current_line(448, ng0);
    t2 = (t0 + 30732);
    t5 = (t0 + 16112);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t2, 4U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(449, ng0);
    t2 = (t0 + 16176);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);

LAB11:
LAB9:    goto LAB3;

LAB5:    t4 = (t0 + 1192U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

LAB8:    xsi_set_current_line(429, ng0);
    t4 = (t0 + 30616);
    t12 = (t0 + 16112);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t4, 4U);
    xsi_driver_first_trans_fast(t12);
    xsi_set_current_line(430, ng0);
    t2 = (t0 + 16176);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    goto LAB9;

LAB12:    xsi_set_current_line(434, ng0);
    t50 = (t0 + 30676);
    t52 = (t0 + 16112);
    t53 = (t52 + 56U);
    t54 = *((char **)t53);
    t55 = (t54 + 56U);
    t56 = *((char **)t55);
    memcpy(t56, t50, 4U);
    xsi_driver_first_trans_fast(t52);
    goto LAB11;

LAB13:    xsi_set_current_line(435, ng0);
    t2 = (t0 + 30680);
    t5 = (t0 + 16112);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t2, 4U);
    xsi_driver_first_trans_fast(t5);
    goto LAB11;

LAB14:    xsi_set_current_line(436, ng0);
    t2 = (t0 + 30684);
    t5 = (t0 + 16112);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t2, 4U);
    xsi_driver_first_trans_fast(t5);
    goto LAB11;

LAB15:    xsi_set_current_line(437, ng0);
    t2 = (t0 + 30688);
    t5 = (t0 + 16112);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t2, 4U);
    xsi_driver_first_trans_fast(t5);
    goto LAB11;

LAB16:    xsi_set_current_line(438, ng0);
    t2 = (t0 + 30692);
    t5 = (t0 + 16112);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t2, 4U);
    xsi_driver_first_trans_fast(t5);
    goto LAB11;

LAB17:    xsi_set_current_line(439, ng0);
    t2 = (t0 + 30696);
    t5 = (t0 + 16112);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t2, 4U);
    xsi_driver_first_trans_fast(t5);
    goto LAB11;

LAB18:    xsi_set_current_line(440, ng0);
    t2 = (t0 + 30700);
    t5 = (t0 + 16112);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t2, 4U);
    xsi_driver_first_trans_fast(t5);
    goto LAB11;

LAB19:    xsi_set_current_line(441, ng0);
    t2 = (t0 + 30704);
    t5 = (t0 + 16112);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t2, 4U);
    xsi_driver_first_trans_fast(t5);
    goto LAB11;

LAB20:    xsi_set_current_line(442, ng0);
    t2 = (t0 + 30708);
    t5 = (t0 + 16112);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t2, 4U);
    xsi_driver_first_trans_fast(t5);
    goto LAB11;

LAB21:    xsi_set_current_line(443, ng0);
    t2 = (t0 + 30712);
    t5 = (t0 + 16112);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t2, 4U);
    xsi_driver_first_trans_fast(t5);
    goto LAB11;

LAB22:    xsi_set_current_line(444, ng0);
    t2 = (t0 + 30716);
    t5 = (t0 + 16112);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t2, 4U);
    xsi_driver_first_trans_fast(t5);
    goto LAB11;

LAB23:    xsi_set_current_line(445, ng0);
    t2 = (t0 + 30720);
    t5 = (t0 + 16112);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t2, 4U);
    xsi_driver_first_trans_fast(t5);
    goto LAB11;

LAB24:    xsi_set_current_line(446, ng0);
    t2 = (t0 + 30724);
    t5 = (t0 + 16112);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t2, 4U);
    xsi_driver_first_trans_fast(t5);
    goto LAB11;

LAB25:    xsi_set_current_line(447, ng0);
    t2 = (t0 + 30728);
    t5 = (t0 + 16112);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t2, 4U);
    xsi_driver_first_trans_fast(t5);
    goto LAB11;

LAB41:;
}

static void work_a_1732556204_2543805730_p_1(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(469, ng0);

LAB3:    t1 = (t0 + 11272U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 16240);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast(t1);

LAB2:    t8 = (t0 + 15936);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_1732556204_2543805730_p_2(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(472, ng0);

LAB3:    t1 = (t0 + 10472U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 16304);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t8 = (t0 + 15952);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_1732556204_2543805730_p_3(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(473, ng0);

LAB3:    t1 = (t0 + 11112U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 16368);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t8 = (t0 + 15968);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_1732556204_2543805730_p_4(char *t0)
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
    int64 t15;

LAB0:    xsi_set_current_line(500, ng0);
    t2 = (t0 + 11072U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 15984);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(501, ng0);
    t4 = (t0 + 11912U);
    t8 = *((char **)t4);
    t9 = *((unsigned char *)t8);
    t10 = (t9 == (unsigned char)3);
    if (t10 != 0)
        goto LAB8;

LAB10:    t2 = (t0 + 11592U);
    t4 = *((char **)t2);
    t1 = *((unsigned char *)t4);
    t3 = (t1 == (unsigned char)3);
    if (t3 != 0)
        goto LAB11;

LAB12:    xsi_set_current_line(506, ng0);
    t15 = (1 * 1000LL);
    t2 = (t0 + 16432);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_delta(t2, 0U, 1, t15);
    t12 = (t0 + 16432);
    xsi_driver_intertial_reject(t12, t15, t15);

LAB9:    goto LAB3;

LAB5:    t4 = (t0 + 11112U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

LAB8:    xsi_set_current_line(502, ng0);
    t4 = (t0 + 16432);
    t11 = (t4 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = (unsigned char)2;
    xsi_driver_first_trans_fast(t4);
    goto LAB9;

LAB11:    xsi_set_current_line(504, ng0);
    t15 = (1 * 1000LL);
    t2 = (t0 + 10312U);
    t5 = *((char **)t2);
    t6 = *((unsigned char *)t5);
    t7 = ieee_p_2592010699_sub_374109322130769762_503743352(IEEE_P_2592010699, t6);
    t2 = (t0 + 16432);
    t8 = (t2 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t7;
    xsi_driver_first_trans_delta(t2, 0U, 1, t15);
    t14 = (t0 + 16432);
    xsi_driver_intertial_reject(t14, t15, t15);
    goto LAB9;

}

static void work_a_1732556204_2543805730_p_5(char *t0)
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
    int64 t15;

LAB0:    xsi_set_current_line(515, ng0);
    t2 = (t0 + 11232U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 16000);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(516, ng0);
    t4 = (t0 + 11752U);
    t8 = *((char **)t4);
    t9 = *((unsigned char *)t8);
    t10 = (t9 == (unsigned char)3);
    if (t10 != 0)
        goto LAB8;

LAB10:    t2 = (t0 + 11432U);
    t4 = *((char **)t2);
    t1 = *((unsigned char *)t4);
    t3 = (t1 == (unsigned char)3);
    if (t3 != 0)
        goto LAB11;

LAB12:    xsi_set_current_line(521, ng0);
    t15 = (1 * 1000LL);
    t2 = (t0 + 16496);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_delta(t2, 0U, 1, t15);
    t12 = (t0 + 16496);
    xsi_driver_intertial_reject(t12, t15, t15);

LAB9:    goto LAB3;

LAB5:    t4 = (t0 + 11272U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

LAB8:    xsi_set_current_line(517, ng0);
    t4 = (t0 + 16496);
    t11 = (t4 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = (unsigned char)2;
    xsi_driver_first_trans_fast(t4);
    goto LAB9;

LAB11:    xsi_set_current_line(519, ng0);
    t15 = (1 * 1000LL);
    t2 = (t0 + 10632U);
    t5 = *((char **)t2);
    t6 = *((unsigned char *)t5);
    t7 = ieee_p_2592010699_sub_374109322130769762_503743352(IEEE_P_2592010699, t6);
    t2 = (t0 + 16496);
    t8 = (t2 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t7;
    xsi_driver_first_trans_delta(t2, 0U, 1, t15);
    t14 = (t0 + 16496);
    xsi_driver_intertial_reject(t14, t15, t15);
    goto LAB9;

}

static void work_a_1732556204_2543805730_p_6(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(528, ng0);

LAB3:    t1 = (t0 + 10312U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 16560);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t8 = (t0 + 16016);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_1732556204_2543805730_p_7(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(529, ng0);

LAB3:    t1 = (t0 + 10632U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 16624);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t8 = (t0 + 16032);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_1732556204_2543805730_init()
{
	static char *pe[] = {(void *)work_a_1732556204_2543805730_p_0,(void *)work_a_1732556204_2543805730_p_1,(void *)work_a_1732556204_2543805730_p_2,(void *)work_a_1732556204_2543805730_p_3,(void *)work_a_1732556204_2543805730_p_4,(void *)work_a_1732556204_2543805730_p_5,(void *)work_a_1732556204_2543805730_p_6,(void *)work_a_1732556204_2543805730_p_7};
	xsi_register_didat("work_a_1732556204_2543805730", "isim/testbench.sim/work/a_1732556204_2543805730.didat");
	xsi_register_executes(pe);
}
