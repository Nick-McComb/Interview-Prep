#include <stdio.h>
#include <stdint.h>

volatile uint32_t sample_register = 0;

#define PERIPH_REG (*(volatile uint32_t *)&sample_register) 
//pointer to unsigned 32-bit integer, made it volatile, constantly updates and checks hardware
// assigned to address of sample_register and dereferenced to be actual value



void set_mode(uint32_t mode){
    uint32_t mask = 0xF;
    PERIPH_REG = (PERIPH_REG & ~mask) | (mode & mask); 
    //wipes the last 4 bits of PERIPH_REG and sets them to mode 
    //ands mode with mask to ensure only last 4 bits are used
}

void enable_peripheral(void){
    uint32_t enable_bit = 0x10;
    PERIPH_REG |= enable_bit;
    //or's the enable bit and the peripheral register to set the enable bit to 1
}
