#ifndef STM32F103XX_H_
#define STM32F103XX_H_

#include <stdint.h>

#define __vo volatile

/*******************************START: processor specific macros *********************************/
/*
 * ARM CORTEX Mx Processor NVIC ISERx Registers addresses
 */
#define NVIC_ISER0                  ((__vo uint32_t *)0xE000E100)
#define NVIC_ISER1                  ((__vo uint32_t *)0xE000E104)
#define NVIC_ISER2                  ((__vo uint32_t *)0xE000E108)
#define NVIC_ISER3                  ((__vo uint32_t *)0xE000E10c)

/*
 * ARM CORTEX Mx Processor NVIC ICERx Registers addresses
 */
#define NVIC_ICER0                  ((__vo uint32_t *)0xE000E180)
#define NVIC_ICER1                  ((__vo uint32_t *)0xE000E184)
#define NVIC_ICER2                  ((__vo uint32_t *)0xE000E188)
#define NVIC_ICER3                  ((__vo uint32_t *)0xE000E18c)


#define FLASH_BASE_ADDR             0x08000000U
#define SRM_BASE_ADDR               0x20000000U
#define ROM_BASE_ADDR               0x1FFFF000U /* system memory */
#define                             SRAM SRM_BASE_ADDR

/*
 * AHB and APBx peripheral bus base addresses
 */

#define PERIPH_BASE                 0x40000000U
#define AHB_PERIPH_BASE             0x40020000U
#define APB1_PERIPH_BASE            PERIPH_BASE
#define APB2_PERIPH_BASE            0x40010000U

/*
 * Base addresses of AHB bus peripherals 
 * TODO : Complete for all other peripherals
 */

#define DMA1_BASEADDR               (AHB_PERIPH_BASE + 0x0000)
#define DMA2_BASEADDR               (AHB_PERIPH_BASE + 0x0400)
#define RCC_BASEADDR                (AHB_PERIPH_BASE + 0x1000)

/*
 * Base addresses of APB1 bus peripherals 
 */

#define SPI2_BASEADDR               (APB1_PERIPH_BASE + 0x3800)
#define SPI3_BASEADDR               (APB1_PERIPH_BASE + 0x3C00)
#define USART2_BASEADDR             (APB1_PERIPH_BASE + 0x4400)
#define USART3_BASEADDR             (APB1_PERIPH_BASE + 0x4800)
#define UART4_BASEADDR              (APB1_PERIPH_BASE + 0x4C00)
#define UART5_BASEADDR              (APB1_PERIPH_BASE + 0x5000)
#define I2C1_BASEADDR               (APB1_PERIPH_BASE + 0x5400)
#define I2C2_BASEADDR               (APB1_PERIPH_BASE + 0x5800)

/*
 * Base addresses of APB2 bus peripherals
 * TODO : Complete for all other peripherals
 */

#define AFIO_BASEADDR               (APB2_PERIPH_BASE + 0x0000)
#define EXTI_BASEADDR               (APB2_PERIPH_BASE + 0x0400)
#define GPIOA_BASEADDR              (APB2_PERIPH_BASE + 0x0800)
#define GPIOB_BASEADDR              (APB2_PERIPH_BASE + 0x0C00)
#define GPIOC_BASEADDR              (APB2_PERIPH_BASE + 0x1000)
#define GPIOD_BASEADDR              (APB2_PERIPH_BASE + 0x1400)
#define GPIOE_BASEADDR              (APB2_PERIPH_BASE + 0x1800)
#define GPIOF_BASEADDR              (APB2_PERIPH_BASE + 0x1C00)
#define GPIOG_BASEADDR              (APB2_PERIPH_BASE + 0x2000)
#define ADC1_BASEADDR               (APB2_PERIPH_BASE + 0x2400)
#define ADC2_BASEADDR               (APB2_PERIPH_BASE + 0x2800)
#define TIM1_BASEADDR               (APB2_PERIPH_BASE + 0x2C00)
#define SPI1_BASEADDR               (APB2_PERIPH_BASE + 0x3000)
#define TIM8_BASEADDR               (APB2_PERIPH_BASE + 0x3400)
#define USART1_BASEADDR             (APB2_PERIPH_BASE + 0x3800)
#define ADC3_BASEADDR               (APB2_PERIPH_BASE + 0x3C00)
#define TIM9_BASEADDR               (APB2_PERIPH_BASE + 0x4C00)
#define TIM10_BASEADDR              (APB2_PERIPH_BASE + 0x5000)
#define TIM11_BASEADDR              (APB2_PERIPH_BASE + 0x5400)




/******************* Registers peripheral structures **********************/


typedef struct
{
    __vo uint32_t CRL;
    __vo uint32_t CRH;
    __vo uint32_t IDR;
    __vo uint32_t ODR;
    __vo uint32_t BSRR;
    __vo uint32_t BRR;
    __vo uint32_t LCKR;
}GPIO_RegDef_t ;

typedef struct
{
    __vo uint32_t CR;
    __vo uint32_t CFGR;
    __vo uint32_t CIR;
    __vo uint32_t APB2RSTR;
    __vo uint32_t APB1RSTR;
    __vo uint32_t AHBENR;
    __vo uint32_t APB2ENR;
    __vo uint32_t APB1ENR;
    __vo uint32_t BDCR;
    __vo uint32_t CSR;
}RCC_RegDef_t;

#define RCC         ((RCC_RegDef_t *)RCC_BASEADDR)

/*
 * register definition peripheral structre for EXTI 
 */
typedef struct
{
    __vo uint32_t IMR;
    __vo uint32_t EMR;
    __vo uint32_t RTSR;
    __vo uint32_t FTSR;
    __vo uint32_t SWIER;
    __vo uint32_t PR;

}EXTI_RegDef_t;

#define EXTI        ((EXTI_RegDef_t *)EXTI_BASEADDR)

/*
 * register definition peripheral structre for AFIO 
 */
typedef struct
{
    __vo uint32_t EVCR;
    __vo uint32_t MAPR;
    __vo uint32_t EXTICR[4];
    __vo uint32_t MAPR2;
}AFIO_RegDef_t;

#define AFIO        ((AFIO_RegDef_t *)AFIO_BASEADDR)

/*
 * peripheral definitions ( peripheral base addresses typecasted to GPIO_RegDef_t )
 */

#define GPIOA      ((GPIO_RegDef_t *)GPIOA_BASEADDR)
#define GPIOB      ((GPIO_RegDef_t *)GPIOB_BASEADDR)
#define GPIOC      ((GPIO_RegDef_t *)GPIOC_BASEADDR)
#define GPIOD      ((GPIO_RegDef_t *)GPIOD_BASEADDR)
#define GPIOE      ((GPIO_RegDef_t *)GPIOE_BASEADDR)
#define GPIOF      ((GPIO_RegDef_t *)GPIOF_BASEADDR)
#define GPIOG      ((GPIO_RegDef_t *)GPIOG_BASEADDR)


/*                                                                                                  */
/* ************************************ CLOCK ENABLE MACROS *****************************************/
/*                                                                                                  */

/*
 * clock enable macros for GPIOx peripherals 
 */

#define GPIOA_PCLK_EN()             (RCC->APB2ENR |= (1 << 2))
#define GPIOB_PCLK_EN()             (RCC->APB2ENR |= (1 << 3))
#define GPIOC_PCLK_EN()             (RCC->APB2ENR |= (1 << 4))
#define GPIOD_PCLK_EN()             (RCC->APB2ENR |= (1 << 5))
#define GPIOE_PCLK_EN()             (RCC->APB2ENR |= (1 << 6))
#define GPIOF_PCLK_EN()             (RCC->APB2ENR |= (1 << 7))
#define GPIOG_PCLK_EN()             (RCC->APB2ENR |= (1 << 8))

/*
 * clock enable macros for I2Cx peripherals 
 */

#define I2C1_PCLK_EN()              (RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN()              (RCC->APB1ENR |= (1 << 22))

/*
 * clock enable macros for SPIx peripherals 
 */

#define SPI1_PCLK_EN()              (RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()              (RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()              (RCC->APB1ENR |= (1 << 15))

/*
 * clock enable macros for USARTx and UARTx peripherals 
 */

#define USART1_PCLK_EN()            (RCC->APB2ENR |= (1 << 14))
#define USART2_PCLK_EN()            (RCC->APB1ENR |= (1 << 17))
#define USART3_PCLK_EN()            (RCC->APB1ENR |= (1 << 18))
#define UART4_PCLK_EN()            (RCC->APB1ENR |= (1 << 19))
#define UART5_PCLK_EN()            (RCC->APB1ENR |= (1 << 20))

/*
 * clock enable macros for ADCx peripherals 
 */

#define ADC1_PCLK_EN()              (RCC->APB2ENR |= (1 << 9))
#define ADC2_PCLK_EN()              (RCC->APB2ENR |= (1 << 10))
#define ADC3_PCLK_EN()              (RCC->APB2ENR |= (1 << 15))

/*
 * clock enable macro for AFIO
 */
#define AFIO_ICLK_EN()              (RCC->APB2ENR |= (1 << 0))


/*
 * ************************************ CLOCK DISABLE MACROS ****************************************
 */

/*
 * clock disable macros for GPIOx peripherals 
 */

#define GPIOA_PCLK_DI()             (RCC->APB2ENR &= ~(1 << 2))
#define GPIOB_PCLK_DI()             (RCC->APB2ENR &= ~(1 << 3))
#define GPIOC_PCLK_DI()             (RCC->APB2ENR &= ~(1 << 4))
#define GPIOD_PCLK_DI()             (RCC->APB2ENR &= ~(1 << 5))
#define GPIOE_PCLK_DI()             (RCC->APB2ENR &= ~(1 << 6))
#define GPIOF_PCLK_DI()             (RCC->APB2ENR &= ~(1 << 7))
#define GPIOG_PCLK_DI()             (RCC->APB2ENR &= ~(1 << 8))

/*
 * clock disable macros for I2Cx peripherals 
 */

#define I2C1_PCLK_DI()              (RCC->APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DI()              (RCC->APB1ENR &= ~(1 << 22))

/*
 * clock disable macros for SPIx peripherals 
 */

#define SPI1_PCLK_DI()              (RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI()              (RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI()              (RCC->APB1ENR &= ~(1 << 15))

/*
 * clock disable macros for USARTx and UARTx peripherals 
 */

#define USART1_PCLK_DI()            (RCC->APB2ENR &= ~(1 << 14))
#define USART2_PCLK_DI()            (RCC->APB1ENR &= ~(1 << 17))
#define USART3_PCLK_DI()            (RCC->APB1ENR &= ~(1 << 18))
#define UART4_PCLK_DI()            (RCC->APB1ENR &= ~(1 << 19))
#define UART5_PCLK_DI()            (RCC->APB1ENR &= ~(1 << 20))

/*
 * clock disable macros for ADCx peripherals 
 */

#define ADC1_PCLK_DI()              (RCC->APB2ENR &= ~(1 << 9))
#define ADC2_PCLK_DI()              (RCC->APB2ENR &= ~(1 << 10))
#define ADC3_PCLK_DI()              (RCC->APB2ENR &= ~(1 << 15))

/*
 * Macros to reset GPIOx peripherals
 */
#define GPIOA_REG_RESET()           do{ (RCC->APB2RSTR |= (1 << 2)); (RCC->APB2RSTR &= ~(1 << 2)); }while(0)
#define GPIOB_REG_RESET()           do{ (RCC->APB2RSTR |= (1 << 3)); (RCC->APB2RSTR &= ~(1 << 3)); }while(0)
#define GPIOC_REG_RESET()           do{ (RCC->APB2RSTR |= (1 << 4)); (RCC->APB2RSTR &= ~(1 << 4)); }while(0)
#define GPIOD_REG_RESET()           do{ (RCC->APB2RSTR |= (1 << 5)); (RCC->APB2RSTR &= ~(1 << 5)); }while(0)
#define GPIOE_REG_RESET()           do{ (RCC->APB2RSTR |= (1 << 6)); (RCC->APB2RSTR &= ~(1 << 6)); }while(0)
#define GPIOF_REG_RESET()           do{ (RCC->APB2RSTR |= (1 << 7)); (RCC->APB2RSTR &= ~(1 << 7)); }while(0)
#define GPIOG_REG_RESET()           do{ (RCC->APB2RSTR |= (1 << 8)); (RCC->APB2RSTR &= ~(1 << 8)); }while(0)


/*
 * this macro returns a code( between 0 to 7) for a given GPIO base address(x)
 */
#define GPIO_BASEADDR_TO_CODE(x)          ( (x == GPIOA) ? 0:\
                                            (x == GPIOB) ? 1:\
                                            (x == GPIOC) ? 2:\
                                            (x == GPIOD) ? 3:\
                                            (x == GPIOE) ? 4:\
                                            (x == GPIOF) ? 5:\
                                            (x == GPIOG) ? 6:0 )
/*
 * IRQ( Interrupt request) number for STM32F103XX
 * TODO : May need to compleate for all the other peripherals
 */
#define IRQ_NO_EXTI0                    13
#define IRQ_NO_EXTI1                    14
#define IRQ_NO_EXTI2                    15
#define IRQ_NO_EXTI3                    16
#define IRQ_NO_EXTI4                    17
#define IRQ_NO_EXTI9_5                  30
#define IRQ_NO_EXTI15_10                47

/*
 * Generic macros 
 */

#define ENABLE              1
#define DISABLE             0
#define SET                 ENABLE
#define RESET               DISABLE
#define GPIO_PIN_SET        SET
#define GPIO_PIN_RESET      RESET



#endif // !STM32F103XX_H_
