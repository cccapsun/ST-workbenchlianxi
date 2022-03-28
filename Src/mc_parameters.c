
/**
  ******************************************************************************
  * @file    mc_parameters.c
  * @author  Motor Control SDK Team, ST Microelectronics
  * @brief   This file provides definitions of HW parameters specific to the
  *          configuration of the subsystem.该文件提供了特定于子系统配置的硬件参数定义。
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "parameters_conversion.h"

#include "r3_1_f30x_pwm_curr_fdbk.h"

/* USER CODE BEGIN Additional include */

/* USER CODE END Additional include */

#define FREQ_RATIO 1                /* Dummy value for single drive */
#define FREQ_RELATION HIGHEST_FREQ  /* Dummy value for single drive */

/**
  * @brief  Current sensor parameters Motor 1 - three shunt 1 ADC (STM32F302x8)
  */
const R3_1_Params_t R3_1_ParamsM1 =
{
/* Dual MC parameters --------------------------------------------------------*/
  .FreqRatio       = FREQ_RATIO,/* 电流频率比，设定值为1*/
  .IsHigherFreqTim = FREQ_RELATION, /*最大频率时间*/

/* Current reading A/D Conversions initialization  当前读数 A/D 转换初始化-----------------------------*/
  .ADCx           = ADC1,
  .ADCConfig = {
                 MC_ADC_CHANNEL_2<<ADC_JSQR_JSQ1_Pos | MC_ADC_CHANNEL_3<<ADC_JSQR_JSQ2_Pos | 1<<ADC_JSQR_JL_Pos | (LL_ADC_INJ_TRIG_EXT_TIM1_TRGO & ~ADC_INJ_TRIG_EXT_EDGE_DEFAULT),
                 MC_ADC_CHANNEL_1<<ADC_JSQR_JSQ1_Pos | MC_ADC_CHANNEL_3<<ADC_JSQR_JSQ2_Pos | 1<<ADC_JSQR_JL_Pos | (LL_ADC_INJ_TRIG_EXT_TIM1_TRGO & ~ADC_INJ_TRIG_EXT_EDGE_DEFAULT),
                 MC_ADC_CHANNEL_3<<ADC_JSQR_JSQ1_Pos | MC_ADC_CHANNEL_1<<ADC_JSQR_JSQ2_Pos | 1<<ADC_JSQR_JL_Pos | (LL_ADC_INJ_TRIG_EXT_TIM1_TRGO & ~ADC_INJ_TRIG_EXT_EDGE_DEFAULT),
                 MC_ADC_CHANNEL_2<<ADC_JSQR_JSQ1_Pos | MC_ADC_CHANNEL_1<<ADC_JSQR_JSQ2_Pos | 1<<ADC_JSQR_JL_Pos | (LL_ADC_INJ_TRIG_EXT_TIM1_TRGO & ~ADC_INJ_TRIG_EXT_EDGE_DEFAULT),
                 MC_ADC_CHANNEL_1<<ADC_JSQR_JSQ1_Pos | MC_ADC_CHANNEL_2<<ADC_JSQR_JSQ2_Pos | 1<<ADC_JSQR_JL_Pos | (LL_ADC_INJ_TRIG_EXT_TIM1_TRGO & ~ADC_INJ_TRIG_EXT_EDGE_DEFAULT),
                 MC_ADC_CHANNEL_3<<ADC_JSQR_JSQ1_Pos | MC_ADC_CHANNEL_2<<ADC_JSQR_JSQ2_Pos | 1<<ADC_JSQR_JL_Pos | (LL_ADC_INJ_TRIG_EXT_TIM1_TRGO & ~ADC_INJ_TRIG_EXT_EDGE_DEFAULT),
  },

  .ADCDataReg1 = {
                   &ADC1->JDR1,
                   &ADC1->JDR1,
                   &ADC1->JDR2,
                   &ADC1->JDR2,
                   &ADC1->JDR1,
                   &ADC1->JDR2,
  },
  .ADCDataReg2 = {
                   &ADC1->JDR2,
                   &ADC1->JDR2,
                   &ADC1->JDR1,
                   &ADC1->JDR1,
                   &ADC1->JDR2,
                   &ADC1->JDR1,
  },

/* PWM generation parameters  PWM生成参数--------------------------------------------------*/
  .RepetitionCounter = REP_COUNTER,
  .Tafter            = TW_AFTER,
  .Tbefore           = TW_BEFORE_R3_1,
  .Tsampling         = (uint16_t)SAMPLING_TIME,
  .Tcase2            = (uint16_t)SAMPLING_TIME + (uint16_t)TDEAD + (uint16_t)TRISE,
  .Tcase3            = ((uint16_t)TDEAD + (uint16_t)TNOISE + (uint16_t)SAMPLING_TIME)/2u,
  .TIMx               = TIM1,

/* PWM Driving signals initialization   PWM驱动信号初始化----------------------------------------*/
  .LowSideOutputs = (LowSideOutputsFunction_t)LOW_SIDE_SIGNALS_ENABLING,
 .pwm_en_u_port      = M1_PWM_EN_UVW_GPIO_Port,
 .pwm_en_u_pin       = M1_PWM_EN_UVW_Pin,
 .pwm_en_v_port      = M1_PWM_EN_UVW_GPIO_Port,
 .pwm_en_v_pin       = M1_PWM_EN_UVW_Pin,
 .pwm_en_w_port      = M1_PWM_EN_UVW_GPIO_Port,
 .pwm_en_w_pin       = M1_PWM_EN_UVW_Pin,

/* Emergency input (BKIN2) signal initialization  紧急输入（BKIN2）信号初始化-----------------------------*/
  .BKIN2Mode     = EXT_MODE,

/* Internal COMP settings  内部 COMP 设置----------------------------------------------------*/
  .CompOCPASelection     = MC_NULL,
  .CompOCPAInvInput_MODE = NONE,
  .CompOCPBSelection     = MC_NULL,
  .CompOCPBInvInput_MODE = NONE,
  .CompOCPCSelection     = MC_NULL,
  .CompOCPCInvInput_MODE = NONE,

  .CompOVPSelection      = MC_NULL,
  .CompOVPInvInput_MODE  = NONE,

/* DAC settings --------------------------------------------------------------*/
  .DAC_OCP_Threshold =  23830,
  .DAC_OVP_Threshold =  23830,
};

/* USER CODE BEGIN Additional parameters */

/* USER CODE END Additional parameters */

/******************* (C) COPYRIGHT 2019 STMicroelectronics *****END OF FILE****/
