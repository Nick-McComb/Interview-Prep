/*
Check if a number is a power of two
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

bool powerof2(uint32_t n){
    return ((n>0) && ((n&(n-1)) == 0)); 
}

int main(){
    //printf("%s", "hello world!");

    printf("%d",powerof2(6));
    return 0;
}