.section .text
.global _start
_start:
    li sp, 0xbffffff0
    jal main
1:  j 1b
