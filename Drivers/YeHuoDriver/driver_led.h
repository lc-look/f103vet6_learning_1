#ifndef _DRIVER_LED_H
#define _DRIVER_LED_H

#define LED_GREEN 0
#define LED_BLUE 2
#define LED_RED 1

#define LED_ON 1
#define LED_OFF 0

/*
    @brief 
    函数名称：  LED_Init
    功能描述：  LED初始化函数，在HAL的初始化代码中配置好GPIO引脚，所以本函数可以为空
                但为了不依赖于stm32cubemx，此函数也实现了GPIO的配置。
    @param  void
    @return 0 - successful other - failure

*/
int LED_Init(void);

/*
    @brief Choose which LED to light
    @param  LED_name LED_Green, LED_Red, LED_Blue
    @param  LED_ON_OFF state, LED_ON - light, LED_OFF - off
    @return 0 successful, otherwise - failure
*/
int LED_Control(int LED_name, int LED_ON_OFF);

void LED_Test(void);
#endif