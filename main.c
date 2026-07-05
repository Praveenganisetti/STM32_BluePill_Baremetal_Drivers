#include "stm32f103xx_gpio.h"
#include "stm32f103xx.h"
#include "stm32f103xx_spi.h"
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
    GpioLed.pGPIOx = GPIOC;

    GpioLed.GPIO_PinConfig.GPIO_PinNumber = PIN13;
    GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_OP_2MHZ_PP;

    GPIO_PeriClockControl(GPIOC, ENABLE);
    GPIO_Init(&GpioLed);
    GPIO_WriteToOutputPin(GPIOC, PIN13, HIGH);


    // For button
    GPIOBtn.pGPIOx = GPIOB;

    GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = PIN12;
    GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_IP_PUPD;
    GPIOBtn.GPIO_PinConfig.GPIO_Set_IT_trig = GPIO_IT_FT_BIT;

    GPIO_PeriClockControl(GPIOB, ENABLE);
    GPIO_Init(&GPIOBtn);

    GPIO_WriteToOutputPin(GPIOB, PIN12, ENABLE);

    // Irq configurations
    AFIO_ICLK_EN();
    GPIO_IRQPriorityConfig(IRQ_NO_EXTI15_10, 15);
    GPIO_IRQInterruptConfig(IRQ_NO_EXTI15_10, ENABLE);

    SPI_PeriClockControl(SPI1, ENABLE);
    while (1);
 
}


void EXTI15_10_IRQHandler(void)
{
    GPIO_IRQHandling(PIN12);
    GPIO_ToggleOutputPin(GPIOC, PIN13);
}

