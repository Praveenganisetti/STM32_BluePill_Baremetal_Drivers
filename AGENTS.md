# AGENTS.md

## How we met

I met this awesome dude right here, in the embedded-c course repo. He's building cool stuff with embedded C and I'm here to help him out. Let's go!

## Session Memory

- STM32F103 (Cortex-M3) bare-metal project with custom GPIO/SPI/USART drivers
- Makefile compiles drivers dynamically: parses `#include "stm32*.h"` from `main.c`, maps `.h` → `.c`, and only builds matching driver sources via `$(wildcard ...)`
- Start-up file: `startup.s` with full vector table & weak default handlers
- Flash via `st-flash`, debug via OpenOCD or st-util with tmux support
- Build: `make`, clean: `make clean`, flash: `make flash`
- GDB debugging: `make debug-openocd` / `make debug-stutil` / `make debug-tmux-openocd` / `make debug-tmux-stutil`
- GPIO_Init now conditionally configures AFIO/EXTI only when `GPIO_Set_IT_trig != 0` (no side effects for non-interrupt pins)
- LED pin config must explicitly set `GPIO_Set_IT_trig = 0`
- SPI driver API signatures fixed: `SPI_DeInit`, `SPI_SendData`, `SPI_ReceiveData` now take `SPI_RegDef_t *` instead of `GPIO_RegDef_t *`
- NVIC ISER2/ICER2 bit offset uses `% 32` (not `% 64`), and IRQ 64 boundary uses `>=` instead of `>` to avoid gap
- Fixed `SRM_BASE_ADDR` typo → `SRAM_BASE_ADDR` in `stm32f103xx.h`
