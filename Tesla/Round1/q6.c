#include <stdint.h>
#include <stdio.h>

/*
    2. Bit Manipulation (Power Control)

    Question:
    You have a power control register:

    Bit	Meaning
    0	Enable LV Rail
    1	Enable HV Wake
    2	Fault Present
    3	Reset

    Write C functions to:

    Enable LV rail

    Clear fault bit

    Check if a fault exists
*/

volatile uint8_t power_control_register = 0x0;



void enable_LV_rail(){
    power_control_set(1U);
}

void power_control_set(uint8_t n)
{
    power_control_register |= n;
}