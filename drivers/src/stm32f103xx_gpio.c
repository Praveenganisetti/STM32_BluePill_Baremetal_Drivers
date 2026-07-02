#include "../inc/stm32f103xx_gpio.h"
#include <stdint.h>


/****************** API's supported by the driver *******************/

/*
 * Peripheral clock setup
 */

/********************************************************************
 * @fn                  - GPIO_PeriClockControl
 *
 * @brief               - This function enables or disables Peripheral clock for the given GPIO port
 *
 * @param[in]           - Base address of gpio Peripheral
 * @param[in]           - ENABLE or DISABLE macros
 * @param[in]           -
 *
 * @return              - none
 *
 * @note                - none
 */

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
    if (EnorDi == ENABLE)
    {
        if (pGPIOx == GPIOA)
        {
            GPIOA_PCLK_EN();
        }else if (pGPIOx == GPIOB)
        {
            GPIOB_PCLK_EN();
        }else if (pGPIOx == GPIOC)
        {
            GPIOC_PCLK_EN();
        }else if (pGPIOx == GPIOD)
        {
            GPIOD_PCLK_EN();
        }else if (pGPIOx == GPIOE)
        {
            GPIOE_PCLK_EN();
        }else if (pGPIOx == GPIOF)
        {
            GPIOF_PCLK_EN();
        }else if (pGPIOx == GPIOG)
        {
            GPIOG_PCLK_EN();
        }
    }
    else {

        if (pGPIOx == GPIOA)
        {
            GPIOA_PCLK_DI();
        }else if (pGPIOx == GPIOB)
        {
            GPIOB_PCLK_DI();
        }else if (pGPIOx == GPIOC)
        {
            GPIOC_PCLK_DI();
        }else if (pGPIOx == GPIOD)
        {
            GPIOD_PCLK_DI();
        }else if (pGPIOx == GPIOE)
        {
            GPIOE_PCLK_DI();
        }else if (pGPIOx == GPIOF)
        {
            GPIOF_PCLK_DI();
        }else if (pGPIOx == GPIOG)
        {
            GPIOG_PCLK_DI();
        }
    }
}



/*
 * Init and DeInit 
 */


/********************************************************************
 * @fn                  - GPIO_Init
 *
 * @brief               - This function initializes and deinitializes the GPIO Peripherals
 *
 * @param[in]           - 
 * @param[in]           - ENABLE or DISABLE macros
 * @param[in]           -
 *
 * @return              - none
 *
 * @note                - none
 */
void GPIO_Init(GPIO_Handle_t *pGPIO_Handle)
{
    uint32_t temp;
    if(pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber <= 7 )
    {
        temp = pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber;
        pGPIO_Handle->pGPIOx->CRL &= ~( 0xF << (4 * temp) );
        pGPIO_Handle->pGPIOx->CRL |= (pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode << (4 * temp) );
    }
    else if(pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber <= 15)
    {
        temp = pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber -8;
        pGPIO_Handle->pGPIOx->CRH &= ~( 0xF << (4 * temp) );
        pGPIO_Handle->pGPIOx->CRH |= (pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode << (4 * temp) );
    }

    if(pGPIO_Handle->GPIO_PinConfig.GPIO_Set_IT_trig == GPIO_IT_FT_BIT )
    {
        // 1,configure FTSR
        EXTI->FTSR |= (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
        // clear the corresponding RTSR bit
        EXTI->RTSR &= ~(1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);

    }

    else if (pGPIO_Handle->GPIO_PinConfig.GPIO_Set_IT_trig == GPIO_IT_RT_BIT )
    {
        // 1,configure RTSR
        EXTI->RTSR |= (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
        // clear the corresponding FTSR bit
        EXTI->FTSR &= ~(1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
    }

    else if (pGPIO_Handle->GPIO_PinConfig.GPIO_Set_IT_trig == GPIO_IT_RFT_BIT )
    {
        // 1,configure both RTSR and FTSR
        EXTI->RTSR |= (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
        EXTI->FTSR |= (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
    }
        // 2. configure the gpio port selection in AFIO_EXTICR register
        uint8_t temp1 = pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber / 4;
        uint8_t temp2 = pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber % 4;
        uint8_t portcode = GPIO_BASEADDR_TO_CODE(pGPIO_Handle->pGPIOx);
        AFIO->EXTICR[temp1] |= portcode << (temp2 * 4);

        // 3. enable the EXTI interrup delivery using IMR
        EXTI->IMR |= 1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber;
    }


void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
    if (pGPIOx == GPIOA)
    {
        GPIOA_REG_RESET();
    }
    else if (pGPIOx == GPIOB)
    {
        GPIOB_REG_RESET();
    }
    else if (pGPIOx == GPIOC)
    {
        GPIOC_REG_RESET();
    }
    else if (pGPIOx == GPIOD)
    {
        GPIOD_REG_RESET();
    }
    else if (pGPIOx == GPIOE)
    {
        GPIOE_REG_RESET();
    }
    else if (pGPIOx == GPIOF)
    {
        GPIOF_REG_RESET();
    }
    else if (pGPIOx == GPIOG)
    {
        GPIOG_REG_RESET();
    }
}

/*
 * Data Read Write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
    uint8_t value;
    value = (uint8_t)((pGPIOx->IDR >> PinNumber ) & 0x00000001 );
    return value;
}


uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
    uint16_t value;
    value = (uint16_t)pGPIOx->IDR;
    return value;

}

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t value)
{
    if (value == GPIO_PIN_SET)
    {
        pGPIOx->ODR |= (1 << PinNumber);
    }
    else
    {
        pGPIOx->ODR &= ~(1 << PinNumber);
    }
}

void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t value)
{
    pGPIOx->ODR = value;
}

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
    pGPIOx->ODR ^= (1 << PinNumber);
}

/*
 * IRQ Configuration and ISR Handling
 */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{
    if (EnorDi == ENABLE)
    {
        if (IRQNumber <= 31)
        {
            // program ISER0 register
            *NVIC_ISER0 |= (1 << IRQNumber);
        }
        else if (IRQNumber > 31 && IRQNumber < 64 )
        {
            // program ISER1 register
            *NVIC_ISER1 |= (1 << (IRQNumber % 32) );
        }
        else if (IRQNumber > 64 && IRQNumber < 96 )
        {
            // program ISER2 register
            *NVIC_ISER2 |= (1 << (IRQNumber % 64) );
        }
    }
    else
    {
        if (IRQNumber <= 31 )
        {
            // program ICER0 register
            *NVIC_ICER0 |= (1 << IRQNumber);
        }
        else if (IRQNumber > 31 && IRQNumber < 64 )
        {
            // program ICER1 register
            *NVIC_ICER1 |= (1 << IRQNumber % 32);
        }
        else if (IRQNumber > 64 && IRQNumber < 96 )
        {
            // program ICER2 register
            *NVIC_ICER2 |= (1 << IRQNumber % 64);
        }
    }

}

void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority)
{
    // Firsst lets find out ipr register
    uint8_t iprx = IRQNumber / 4;
    uint8_t iprx_section = IRQNumber % 4;

    uint8_t shift_amount = (8 * iprx_section) + (8 - NO_PR_BITS_IMPLEMENTED);
    *(NVIC_PR_BASE_ADDR + iprx) |= ( IRQPriority << shift_amount);
}


void GPIO_IRQHandling(uint8_t PinNumber)
{
    // clear the exti pr register correspondidng to the pin number
    if(EXTI->PR & (1 << PinNumber))
    {
        // clear
        EXTI->PR |= (1 << PinNumber);
    }
}





