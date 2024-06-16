#include "driver_led.h"
#include "driver_timer.h"

#include "gpio.h"

int LED_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    /* 使能对应的GPIO时钟口*/
    __HAL_RCC_GPIOB_CLK_ENABLE();

    /* 设置GPIO pin口的输出电位*/
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_5, GPIO_PIN_SET);

    /* 设置GPIO pin口的配置 : PB0 绿灯 PB1 蓝灯 PB5 红灯*/
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_5;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    return 0;
}

int LED_Control(int which, int on)
{
    if (on)
    {
        switch(which)
        {
            case LED_GREEN:HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);break;
            case LED_BLUE:HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);break;
            case LED_RED:HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);
            break;
        }
        return 0;
    }
    else
    {
        switch(which)
        {
            case LED_GREEN:HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);break;
            case LED_BLUE:HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);break;
            case LED_RED:HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);
            break;
        }
        return 0;
    }
    return 1;
}

void LED_Test(void)
{
    LED_Init();
    while(1)
    {
        LED_Control(LED_GREEN,LED_ON);
        mdelay(500);
        LED_Control(LED_GREEN,LED_OFF);
        mdelay(500);
        LED_Control(LED_BLUE,LED_ON);
        mdelay(500);
        LED_Control(LED_BLUE,LED_OFF);    
        mdelay(500);
        LED_Control(LED_RED,LED_ON);
        mdelay(500);
        LED_Control(LED_RED,LED_OFF);
        mdelay(500);
    }
}