.cpu cortex-m3
.syntax unified
.thumb

.global _estack
.global Reset_Handler

/* =========================================================
 * Vector Table
 * ========================================================= */

.section .isr_vector, "a", %progbits
.type g_pfnVectors, %object

g_pfnVectors:

.word _estack                 /* Initial Stack Pointer */
.word Reset_Handler           /* Reset Handler */
.word NMI_Handler
.word HardFault_Handler
.word MemManage_Handler
.word BusFault_Handler
.word UsageFault_Handler

.word 0
.word 0
.word 0
.word 0

.word SVC_Handler
.word DebugMon_Handler
.word 0
.word PendSV_Handler
.word SysTick_Handler

/* External Interrupts */
.word WWDG_IRQHandler           /* 16: IRQ0  */
.word PVD_IRQHandler            /* 17: IRQ1  */
.word TAMPER_IRQHandler         /* 18: IRQ2  */
.word RTC_IRQHandler            /* 19: IRQ3  */
.word FLASH_IRQHandler          /* 20: IRQ4  */
.word RCC_IRQHandler            /* 21: IRQ5  */
.word EXTI0_IRQHandler          /* 22: IRQ6  */
.word EXTI1_IRQHandler          /* 23: IRQ7  */
.word EXTI2_IRQHandler          /* 24: IRQ8  */
.word EXTI3_IRQHandler          /* 25: IRQ9  */
.word EXTI4_IRQHandler          /* 26: IRQ10 */
.word DMA1_Channel1_IRQHandler  /* 27: IRQ11 */
.word DMA1_Channel2_IRQHandler  /* 28: IRQ12 */
.word DMA1_Channel3_IRQHandler  /* 29: IRQ13 */
.word DMA1_Channel4_IRQHandler  /* 30: IRQ14 */
.word DMA1_Channel5_IRQHandler  /* 31: IRQ15 */
.word DMA1_Channel6_IRQHandler  /* 32: IRQ16 */
.word DMA1_Channel7_IRQHandler  /* 33: IRQ17 */
.word ADC1_2_IRQHandler         /* 34: IRQ18 */
.word USB_HP_CAN1_TX_IRQHandler /* 35: IRQ19 */
.word USB_LP_CAN1_RX0_IRQHandler/* 36: IRQ20 */
.word CAN1_RX1_IRQHandler       /* 37: IRQ21 */
.word CAN1_SCE_IRQHandler       /* 38: IRQ22 */
.word EXTI9_5_IRQHandler        /* 39: IRQ23 */
.word TIM1_BRK_IRQHandler       /* 40: IRQ24 */
.word TIM1_UP_IRQHandler        /* 41: IRQ25 */
.word TIM1_TRG_COM_IRQHandler   /* 42: IRQ26 */
.word TIM1_CC_IRQHandler        /* 43: IRQ27 */
.word TIM2_IRQHandler           /* 44: IRQ28 */
.word TIM3_IRQHandler           /* 45: IRQ29 */
.word TIM4_IRQHandler           /* 46: IRQ30 */
.word I2C1_EV_IRQHandler        /* 47: IRQ31 */
.word I2C1_ER_IRQHandler        /* 48: IRQ32 */
.word I2C2_EV_IRQHandler        /* 49: IRQ33 */
.word I2C2_ER_IRQHandler        /* 50: IRQ34 */
.word SPI1_IRQHandler           /* 51: IRQ35 */
.word SPI2_IRQHandler           /* 52: IRQ36 */
.word USART1_IRQHandler         /* 53: IRQ37 */
.word USART2_IRQHandler         /* 54: IRQ38 */
.word USART3_IRQHandler         /* 55: IRQ39 */
.word EXTI15_10_IRQHandler      /* 56: IRQ40 */
.word RTC_Alarm_IRQHandler      /* 57: IRQ41 */
.word USBWakeUp_IRQHandler      /* 58: IRQ42 */

/* =========================================================
 * Code Section
 * ========================================================= */

.section .text
.thumb

/* =========================================================
 * Reset Handler
 * ========================================================= */

.global Reset_Handler
.type Reset_Handler, %function

Reset_Handler:
    bl main

LoopForever:
    b LoopForever

.size Reset_Handler, .-Reset_Handler

/* =========================================================
 * Default Handler
 * ========================================================= */

.global Default_Handler
.type Default_Handler, %function

Default_Handler:
Infinite_Loop:
    b Infinite_Loop

.size Default_Handler, .-Default_Handler

/* =========================================================
 * Weak Aliases
 * ========================================================= */

.weak NMI_Handler
.thumb_set NMI_Handler, Default_Handler

.weak HardFault_Handler
.thumb_set HardFault_Handler, Default_Handler

.weak MemManage_Handler
.thumb_set MemManage_Handler, Default_Handler

.weak BusFault_Handler
.thumb_set BusFault_Handler, Default_Handler

.weak UsageFault_Handler
.thumb_set UsageFault_Handler, Default_Handler

.weak SVC_Handler
.thumb_set SVC_Handler, Default_Handler

.weak DebugMon_Handler
.thumb_set DebugMon_Handler, Default_Handler

.weak PendSV_Handler
.thumb_set PendSV_Handler, Default_Handler

.weak SysTick_Handler
.thumb_set SysTick_Handler, Default_Handler

.weak WWDG_IRQHandler
.thumb_set WWDG_IRQHandler, Default_Handler

.weak PVD_IRQHandler
.thumb_set PVD_IRQHandler, Default_Handler

.weak TAMPER_IRQHandler
.thumb_set TAMPER_IRQHandler, Default_Handler

.weak RTC_IRQHandler
.thumb_set RTC_IRQHandler, Default_Handler

.weak FLASH_IRQHandler
.thumb_set FLASH_IRQHandler, Default_Handler

.weak RCC_IRQHandler
.thumb_set RCC_IRQHandler, Default_Handler

.weak EXTI0_IRQHandler
.thumb_set EXTI0_IRQHandler, Default_Handler

.weak EXTI1_IRQHandler
.thumb_set EXTI1_IRQHandler, Default_Handler

.weak EXTI2_IRQHandler
.thumb_set EXTI2_IRQHandler, Default_Handler

.weak EXTI3_IRQHandler
.thumb_set EXTI3_IRQHandler, Default_Handler

.weak EXTI4_IRQHandler
.thumb_set EXTI4_IRQHandler, Default_Handler

.weak DMA1_Channel1_IRQHandler
.thumb_set DMA1_Channel1_IRQHandler, Default_Handler

.weak DMA1_Channel2_IRQHandler  
.thumb_set DMA1_Channel2_IRQHandler, Default_Handler

.weak DMA1_Channel3_IRQHandler  
.thumb_set DMA1_Channel3_IRQHandler, Default_Handler

.weak DMA1_Channel4_IRQHandler  
.thumb_set DMA1_Channel4_IRQHandler, Default_Handler

.weak DMA1_Channel5_IRQHandler  
.thumb_set DMA1_Channel5_IRQHandler, Default_Handler

.weak DMA1_Channel6_IRQHandler  
.thumb_set DMA1_Channel6_IRQHandler, Default_Handler

.weak DMA1_Channel7_IRQHandler  
.thumb_set DMA1_Channel7_IRQHandler, Default_Handler

.weak ADC1_2_IRQHandler
.thumb_set ADC1_2_IRQHandler, Default_Handler

.weak USB_HP_CAN1_TX_IRQHandler 
.thumb_set USB_HP_CAN1_TX_IRQHandler, Default_Handler

.weak USB_LP_CAN1_RX0_IRQHandler
.thumb_set USB_LP_CAN1_RX0_IRQHandler, Default_Handler

.weak CAN1_RX1_IRQHandler
.thumb_set CAN1_RX1_IRQHandler, Default_Handler

.weak CAN1_SCE_IRQHandler
.thumb_set CAN1_SCE_IRQHandler, Default_Handler

.weak EXTI9_5_IRQHandler
.thumb_set EXTI9_5_IRQHandler, Default_Handler

.weak TIM1_BRK_IRQHandler
.thumb_set TIM1_BRK_IRQHandler, Default_Handler

.weak TIM1_UP_IRQHandler
.thumb_set TIM1_UP_IRQHandler, Default_Handler

.weak TIM1_TRG_COM_IRQHandler
.thumb_set TIM1_TRG_COM_IRQHandler, Default_Handler

.weak TIM1_CC_IRQHandler
.thumb_set TIM1_CC_IRQHandler, Default_Handler

.weak TIM2_IRQHandler
.thumb_set TIM2_IRQHandler, Default_Handler

.weak TIM3_IRQHandler
.thumb_set TIM3_IRQHandler, Default_Handler

.weak TIM4_IRQHandler
.thumb_set TIM4_IRQHandler, Default_Handler

.weak I2C1_EV_IRQHandler
.thumb_set I2C1_EV_IRQHandler, Default_Handler

.weak I2C1_ER_IRQHandler
.thumb_set I2C1_ER_IRQHandler, Default_Handler

.weak I2C2_EV_IRQHandler
.thumb_set I2C2_EV_IRQHandler, Default_Handler

.weak I2C2_ER_IRQHandler
.thumb_set I2C2_ER_IRQHandler, Default_Handler

.weak SPI1_IRQHandler
.thumb_set SPI1_IRQHandler, Default_Handler

.weak SPI2_IRQHandler
.thumb_set SPI2_IRQHandler, Default_Handler

.weak USART1_IRQHandler
.thumb_set USART1_IRQHandler, Default_Handler

.weak USART2_IRQHandler
.thumb_set USART2_IRQHandler, Default_Handler

.weak USART3_IRQHandler
.thumb_set USART3_IRQHandler, Default_Handler

.weak EXTI15_10_IRQHandler
.thumb_set EXTI15_10_IRQHandler, Default_Handler

.weak RTC_Alarm_IRQHandler
.thumb_set RTC_Alarm_IRQHandler, Default_Handler

.weak USBWakeUp_IRQHandler
.thumb_set USBWakeUp_IRQHandler, Default_Handler


