/**
 * @file alg_filter.cpp
 * @author your name (you@domain.com)
 * @brief 滤波器
 * @version 0.1
 * @date 2023-05-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/* Includes ------------------------------------------------------------------*/

#include "alg_filter.h"

/* Private macros ------------------------------------------------------------*/

/* Private types -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function declarations ---------------------------------------------*/

/* Function prototypes -------------------------------------------------------*/

/**
 * @brief 初始化滤波器
 * 
 * @param __Filter_Fourier_Type 滤波器类型
 * @param __Frequency_Low 滤波器特征低频, 非高通有效
 * @param __Frequency_High 滤波器特征高频, 非低通有效
 * @param __Sampling_Frequency 滤波器采样频率
 */
void Class_Filter_Fourier::Init(float __Value_Constrain_Low, float __Value_Constrain_High, Enum_Filter_Fourier_Type __Filter_Fourier_Type, float __Frequency_Low, float __Frequency_High, float __Sampling_Frequency)
{
    //平均数求法
    float system_function_sum = 0;
    //特征低角速度
    float omega_low;
    //特征高角速度
    float omega_high;

    Value_Constrain_Low = __Value_Constrain_Low;
    Value_Constrain_High = __Value_Constrain_High;
    Filter_Fourier_Type = __Filter_Fourier_Type;
    Frequency_Low = __Frequency_Low;
    Frequency_High = __Frequency_High;
    Sampling_Frequency = __Sampling_Frequency;

    omega_low = 2 * PI * Frequency_Low / Sampling_Frequency;
    omega_high = 2 * PI * Frequency_High / Sampling_Frequency;

    switch (Filter_Fourier_Type)
    {
    case (Filter_Fourier_Type_LOWPASS):
    {
        for(int i = 0; i < FILTER_FOURIER_ORDER + 1; i++)
        {
            System_Function[i] = omega_low / PI * Math_Sinc((i - FILTER_FOURIER_ORDER / 2.0f) * omega_low);
        }
    }
    break;
    case (Filter_Fourier_Type_HIGHPASS):
    {
        for(int i = 0; i < FILTER_FOURIER_ORDER + 1; i++)
        {
            System_Function[i] = Math_Sinc((i - FILTER_FOURIER_ORDER / 2.0f) * PI) - omega_high / PI * Math_Sinc((i - FILTER_FOURIER_ORDER / 2.0f) * omega_high);
        }
    }
    break;
    case (Filter_Fourier_Type_BANDPASS):
    {
        for(int i = 0; i < FILTER_FOURIER_ORDER + 1; i++)
        {
            System_Function[i] = omega_high / PI * Math_Sinc((i - FILTER_FOURIER_ORDER / 2.0f) * omega_high) - omega_low / PI * Math_Sinc((i - FILTER_FOURIER_ORDER / 2.0f) * omega_low);
        }
    }
    break;
    case (Filter_Fourier_Type_BANDSTOP):
    {
        for(int i = 0; i < FILTER_FOURIER_ORDER + 1; i++)
        {
            System_Function[i] = Math_Sinc((i - FILTER_FOURIER_ORDER / 2.0f) * PI) + omega_low / PI * Math_Sinc((i - FILTER_FOURIER_ORDER / 2.0f) * omega_low) - omega_high / PI * Math_Sinc((i - FILTER_FOURIER_ORDER / 2.0f) * omega_high);
        }
    }
    break;
    }

    for(int i = 0; i < FILTER_FOURIER_ORDER + 1; i++)
    {
        system_function_sum += System_Function[i];
    }

    for(int i = 0; i < FILTER_FOURIER_ORDER + 1; i++)
    {
        System_Function[i] /= system_function_sum;
    }
}

/**
 * @brief 获取输出值
 * 
 * @return float 输出值
 */
float Class_Filter_Fourier::Get_Out()
{
    return(Out);
}

/**
 * @brief 设定当前值
 * 
 * @param __Now 当前值
 */
void Class_Filter_Fourier::Set_Now(float __Now)
{
    Math_Constrain(&__Now, Value_Constrain_Low, Value_Constrain_High);
    Input_Signal[Signal_Flag] = __Now;
    Signal_Flag++;
    if(Signal_Flag == FILTER_FOURIER_ORDER + 1)
    {
        Signal_Flag = 0;
    }
}

/**
 * @brief 滤波器调整值
 * 
 */
void Class_Filter_Fourier::TIM_Adjust_PeriodElapsedCallback()
{
    Out = 0;
    for(int i = 0; i < FILTER_FOURIER_ORDER + 1; i++)
    {
        Out += System_Function[i] * Input_Signal[(Signal_Flag + i) % (FILTER_FOURIER_ORDER + 1)];
    }
}

/**
 * @brief 获取输出值
 * 
 * @return float 输出值
 */
void Class_Filter_Kalman::Init(float __Value, float __Error_Estimate, float __Error_Measure)
{
    Now = __Value;
    Error_Estimate = __Error_Estimate;
    Error_Measure = __Error_Measure;
}

/**
 * @brief 获取输出值
 * 
 * @return float 输出值
 */
float Class_Filter_Kalman::Get_Out()
{
    return(Out);
}

/**
 * @brief 设定当前值
 * 
 * @param __Now 当前值
 */
void Class_Filter_Kalman::Set_Now(float __Now)
{
    Now = __Now;
}

 /**
  * @brief 滤波器调整值
  * 
  */
void Class_Filter_Kalman::Recv_Adjust_PeriodElapsedCallback()
{
    Kalman_Gain = Error_Estimate / (Error_Estimate + Error_Measure);

    Out = Out + Kalman_Gain * (Now - Out);

    Error_Estimate = (1.0f - Kalman_Gain) * Error_Estimate;
}

/************************ COPYRIGHT(C) USTC-ROBOWALKER **************************/
