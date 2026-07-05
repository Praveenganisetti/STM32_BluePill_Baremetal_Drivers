#ifndef STM32F103XX_SPI_H
#define STM32F103XX_SPI_H

#include "stm32f103xx.h"
#include <stdint.h>

typedef struct
{
    uint8_t     SPI_DeviceMode;
    uint8_t     SPI_BusConfig;
    uint8_t     SPI_SclkSpeed;
    uint8_t     SPI_DFF;
    uint8_t     SPI_CPHA;
    uint8_t     SPI_CPOL;
    uint8_t     SPI_SSM;
}SPI_Config_t;

typedef struct
{
    SPI_RegDef_t    *pSPIx;
    SPI_Config_t    SPIConfig;
}SPI_Handle_t;

#define SPI_MASTER_MODE     1
#define SPI_SLAVE_MODE      0

#define SPI_BUS_CONFIG_FD       1
#define SPI_BUS_CONFIG_HD       2
#define SPI_BUS_CONFIG_RXONLY   3           // simplex

#define SPI_SCLK_SPEED_DIV2     0
#define SPI_SCLK_SPEED_DIV4     1
#define SPI_SCLK_SPEED_DIV8     2
#define SPI_SCLK_SPEED_DIV16    3
#define SPI_SCLK_SPEED_DIV32    4
#define SPI_SCLK_SPEED_DIV64    5
#define SPI_SCLK_SPEED_DIV128   6
#define SPI_SCLK_SPEED_DIV256   7


#define SPI_DFF_8_BIT       0
#define SPI_DFF_16_BIT      1

#define SPI_CPHA_HIGH   1
#define SPI_CPHA_LOW    0

#define SPI_CPOL_HIGH   1
#define SPI_CPOL_LOW    0

#define SPI_SSM_EN      1 // software slave management
#define SPI_SSM_DI      0 




/**************************************************************************
 *                      API's supported by this driver
 *      For more information the API's check the function definitions
 **************************************************************************/

/*
 * Peripheral clock enable
 */
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi);

/*
 * Init and DeInit 
 */
void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_DeInit(SPI_RegDef_t *pSPIx);

/*
 * Data send and receive
 */
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTXBuffer, uint32_t Len);
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRXBuffer, uint32_t Len);

/*
 * Irq configuration and ISR handling
 */
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority);
void SPI_IRQHandling(SPI_Handle_t *pHandle);



#endif // !STM32F103XX_SPI_H

