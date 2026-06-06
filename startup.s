.cpu cortex-m3
.thumb

.section .isr_vector, "a", %progbits
.word 0x20005000
.word _reset

.section .text
.global _reset
.thumb_func

_reset:
    bl main

loop:
    b loop
