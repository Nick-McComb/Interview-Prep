#include <stdint.h>


/*
    Question:
    What happens if this is called from both main loop and an ISR?
*/

static volatile uint32_t counter = 999; 

void update_counter(uint32_t *counter) {
    //disable interupt 
    if (*counter < 1000) {
        (*counter)++;
    }
    //disable interupt
}

// could cause issues with ISR or main loop calling for the counter memory before it is updated by the previous process
// This would cause both processes to pull 999 and then update by 1 rather than 1 process than the next (atomic) 