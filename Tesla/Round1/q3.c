#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
/*
    FINITE STATE MACHINE
    
    States: 
    POWER_OFF
    POWER_INIT
    POWER_ON
    FAULT

    Legal Transitions: 
    POWER_OFF -> POWER_INIT
    POWER_INIT -> POWER_ON
    POWER_ON -> POWER_OFF
    ALL STATES -> FAULT
    FAULT -> POWER_OFF (recovery)

*/

typedef enum 
{
    POWER_OFF,
    POWER_INIT,
    POWER_ON,
    FAULT
} power_state_t;

static power_state_t current_state = POWER_OFF;


bool valid_transition(power_state_t from, power_state_t to){
    switch(from){
        case POWER_OFF: 
            return (to==POWER_INIT || to==FAULT ) ;
            break;
        case POWER_INIT:
            return (to==POWER_ON || to==FAULT);
            break;
        case POWER_ON:
            return (to==POWER_OFF || to==FAULT);
            break;
        case FAULT:   //recovery    
            return to==POWER_OFF;
            break;
        default:
            return false;
    }
}

bool transition_to(power_state_t to){

    if (!valid_transition(current_state, to)){
        current_state = FAULT;
        return false;
    }
    current_state = to;
    return true;
}

int main(){

    return 0; 
}