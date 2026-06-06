CC      = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

MCU     = -mcpu=cortex-m3 -mthumb
STL = st-flash

CFLAGS  = $(MCU)
CFLAGS += -Wall
CFLAGS += -O0
CFLAGS += -g
CFLAGS += -Idrivers/inc
CFLAGS += -Iinclude

LDFLAGS = $(MCU)
LDFLAGS += -Tlinkerscript.ld
LDFLAGS += -nostdlib

SRC = main.c startup.s $(wildcard drivers/src/*.c)

OBJ = $(SRC:.c=.o)
OBJ := $(OBJ:.s=.o)

TARGET = Application

all: $(TARGET).bin

$(TARGET).elf: $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(CC) $(MCU) -c $< -o $@

flash:
	$(STL) write Application.bin 0x8000000

clean:
	rm -f *.o *.elf *.bin $(wildcard drivers/src/*.o)

erase:
	$(STL) erase
