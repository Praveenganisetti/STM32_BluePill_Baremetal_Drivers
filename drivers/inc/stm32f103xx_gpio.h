#ifndef STM32F103XX_GPIO_H_
#define STM32F103XX_GPIO_H_

#include "stm32f103xx.h"
#include <stdint.h>

typedef struct
{
    uint8_t GPIO_PinNumber;
    uint8_t GPIO_PinMode;
    uint8_t GPIO_Set_IT_trig;
}GPIO_PinConfig_t;

typedef struct
{
    GPIO_RegDef_t *pGPIOx;
    GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;


/********** GPIO possible modes **********/

/* 
 * note : setting modes for this F1 MC is different from those with F4 series
 * here we have same regiseter for configuring mode and speed of MC.
 * so here we need to set four bits [00|00] the upper two bits decide CNF config
 * and the lower two bits decide "MODE"( ip and op(with different speeds))
 *
 * Here is the example macro for output general purpos push pull config with 2mhz speed
 * Ex : for this the CNF will be 00 and the MODE will be 10 for output 2mhz so if 
 * we combine both we got 0010 --> 0b0010 so thats how it is.
 */ 

/*
 * GPIO PIN Input mode Macros
 */
#define GPIO_IP_AN                  0b0000 // input analog, CNF-00 and MODE-00
#define GPIO_IP_FLOAT               0b0100 // input floating, CNF-01 and MODE-00
#define GPIO_IP_PUPD                0b1000 // input pull-up/pull-down, CNF-10 and MODE-00

/*
 * GPIO PIN Output macros with speed 10Mhz
 */
#define GPIO_OP_10MHZ_PP            0b0001 // General purpose push-pull
#define GPIO_OP_10MHZ_OD            0b0101 // General purpose Open-drain
#define GPIO_OP_10MHZ_AFPP          0b1001 // General purpose Alt function push-pull
#define GPIO_OP_10MHZ_AFOD          0b1101 // General purpose Alt function Open-drain

/*
 * GPIO PIN Output macros with speed 2Mhz
 */
#define GPIO_OP_2MHZ_PP            0b0010 // General purpose push-pull
#define GPIO_OP_2MHZ_OD            0b0110 // General purpose Open-drain
#define GPIO_OP_2MHZ_AFPP          0b1010 // General purpose Alt function push-pull
#define GPIO_OP_2MHZ_AFOD          0b1110 // General purpose Alt function Open-drain

/*
 * GPIO PIN Output macros with speed 50Mhz
 */
#define GPIO_OP_50MHZ_PP            0b0011 // General purpose push-pull
#define GPIO_OP_50MHZ_OD            0b0111 // General purpose Open-drain
#define GPIO_OP_50MHZ_AFPP          0b1011 // General purpose Alt function push-pull
#define GPIO_OP_50MHZ_AFOD          0b1111 // General purpose Alt function Open-drain


/*****GPIO PIN MACROS *******/

#define PIN0        0
#define PIN1        1
#define PIN2        2
#define PIN3        3
#define PIN4        4
#define PIN5        5
#define PIN6        6
#define PIN7        7
#define PIN8        8
#define PIN9        9
#define PIN10       10
#define PIN11       11
#define PIN12       12
#define PIN13       13
#define PIN14       14


#define EXTI_RT_BIT             0
#define EXTI_FT_BIT             1
#define EXTI_RFT_BIT            2


/****************** API's supported by the driver *******************/

/*
 * Peripheral clock enable
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);



/*
 * Init and DeInit 
 */
void GPIO_Init(GPIO_Handle_t *pGPIO_Handle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * Data Read Write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
 * IRQ Configuration and ISR Handling
 */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);


#endif // !STM32F103XX_GPIO_H_

