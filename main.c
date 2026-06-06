#include "stm32f103xx_gpio.h"
#include "stm32f103xx.h"
#include <stdint.h>

#define HIGH 1
#define LOW  0
#define BTN_PRESSED LOW

void delay(void)
{
    for (uint32_t i=0; i<500000/2; i++);
}

int main(void)
{
    // For led
    GPIO_Handle_t GpioLed, GPIOBtn;
    GpioLed.pGPIOx = GPIOB;

    GpioLed.GPIO_PinConfig.GPIO_PinNumber = PIN12;
    GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_OP_10MHZ_PP;

    GPIO_PeriClockControl(GPIOB, ENABLE);
    GPIO_Init(&GpioLed);



    // For button
    GPIOBtn.pGPIOx = GPIOA;

    GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = PIN0;
    GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_IP_PUPD;

    GPIO_PeriClockControl(GPIOA, ENABLE);
    GPIO_Init(&GPIOBtn);

    GPIO_WriteToOutputPin(GPIOA, PIN0, ENABLE);

    while (1)
    {
        if ((GPIO_ReadFromInputPin(GPIOA, PIN0)) == BTN_PRESSED ) {
        delay();
        GPIO_ToggleOutputPin(GPIOB, PIN12);
        }
    }return 0;
}
