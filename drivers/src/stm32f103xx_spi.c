#include "../inc/stm32f103xx_spi.h"
#include <stdint.h>


void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
    if (EnorDi == ENABLE)
    {
        if (pSPIx == SPI1)
        {
            SPI1_PCLK_EN();
        }else if (pSPIx == SPI2)
        {
            SPI2_PCLK_EN();
        }else if (pSPIx == SPI3)
        {
            SPI3_PCLK_EN();
        }
    }
    else {

        if (pSPIx == SPI1)
        {
            SPI1_PCLK_DI();
        }else if (pSPIx == SPI2)
        {
            SPI2_PCLK_DI();
        }else if (pSPIx == SPI3)
        {
            SPI3_PCLK_DI();
        }
    }
}


void SPI_Init(SPI_Handle_t *pSPIHandle)
{
    // configure the SPI_CR1 register
    uint32_t tempreg = 0;

    // configure te devicemode
    tempreg = pSPIHandle->SPIConfig.SPI_DeviceMode << SPI_CR1_MSTR;
    // configure busconfig
    if (pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FD)
    {
        // bidi mode should be cleared
        tempreg &= ~(1 << SPI_CR1_BIDI_MODE);
    }else if (pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD)
    {
        // bidi mode should be set
        tempreg |= (1 << SPI_CR1_BIDI_MODE);
    }else if (pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_RXONLY)
    {
        // bidi mode should be cleared
        tempreg &= ~(1 << SPI_CR1_BIDI_MODE);
        // RXONLY bit must be set
        tempreg |= (1 << SPI_CR1_RXONLY);
    }

    // configure clock speed
    tempreg |= pSPIHandle->SPIConfig.SPI_SclkSpeed << SPI_CR1_BR;

    // configure DFF
    tempreg |= pSPIHandle->SPIConfig.SPI_DFF << SPI_CR1_DFF;

    // configure CPHA
    tempreg |= pSPIHandle->SPIConfig.SPI_CPHA << SPI_CR1_CPHA;

    // configure CPOL
    tempreg |= pSPIHandle->SPIConfig.SPI_CPOL << SPI_CR1_CPOL;

    // configure SSM
    tempreg |= pSPIHandle->SPIConfig.SPI_SSM << SPI_CR1_SSM;


    pSPIHandle->pSPIx->CR1 = tempreg;
}


