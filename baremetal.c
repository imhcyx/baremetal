#include <stdint.h>

#define XUARTPS_CR_OFFSET   0x00000000
#define XUARTPS_MR_OFFSET   0x00000004
#define XUARTPS_BAUDGEN_OFFSET  0x00000018
#define BAUD_RATE_DIVIDER_OFFSET  0x00000034
#define XUARTPS_FIFO_OFFSET 0x00000030
#define UART0_BASE_ADDR 0xff000000
#define XUARTPS_SR_OFFSET 0x0000002c

char array[] = "\r\n\n\n**************\r\n Hello World!\r\n**************\r\n";

static inline void _putc(char c){
    while((*((volatile unsigned char*)(UART0_BASE_ADDR + XUARTPS_SR_OFFSET)) & 0x10) != 0);
    *((volatile unsigned char*)(UART0_BASE_ADDR + XUARTPS_FIFO_OFFSET)) = c;
}

static inline void init_uart(){
    while((*((volatile unsigned char*)(UART0_BASE_ADDR + XUARTPS_SR_OFFSET)) & 0x8) == 0);
}

int main()
{
    init_uart();
    
    int i;
    for(i = 0;array[i];i ++)
        _putc(array[i]);
    return 0;
}
