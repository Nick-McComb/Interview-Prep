#include <stdint.h>
#include <stdio.h>

int count_set_bits(uint32_t n) {
    int count = 0;
    while (n){
        n &= n-1;
        count++;
    }
    return count;
}

int even_or_odd(uint32_t n) {
    return count_set_bits(n) & 1;
}

int main(){
    printf("%d", sizeof(int)); //32 bits
    return 0;
}