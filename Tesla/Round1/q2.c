#include <stdio.h>
#include <stdint.h>

uint32_t reg = 0x00000090;
//uint32_t mask = 0xffffffff;

void set_bit(uint32_t *reg, uint8_t bit){
    uint32_t setter = 1U << bit; //#00000010
    *reg |= setter; 
}
void clear_bit(uint32_t *reg, uint8_t bit){
    uint32_t clear =  ~ (1U << bit);
    *reg &= clear;
}
void toggle_bit(uint32_t *reg, uint8_t bit){
    *reg ^= (1U << bit);
}


int main() {

    clear_bit(&reg, 8);
    printf("%x", reg);
    return 0;

}