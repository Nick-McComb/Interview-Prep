#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void reverse_string(char* string){
    char* string_end = string + strlen(string)-1;
    //printf("%s", string_end);
    //printf("%s", string);
    while(string < string_end){
        char temp = *string;
        *string = *string_end;
        *string_end = temp;
        string_end--;
        string ++;
    }
    return;
}


int number_ones(int n){
    int count = 0;
    while(n) {
        n &= n-1;
        count++;
    }
    return count; 
}

bool is_power_of_two(int n){
    return (n>0) && ((n&(n-1)) == 0);
}


int main() {
    char string[] = "Hello, World!"; //Hello, World!'\0'
    reverse_string(string);
    printf("%s\n", string);
    int numbers =  0x76; //0b01110110
    printf("%d\n", number_ones(numbers));
    int numbers_pow2 = 128;
    int numbers_npow2 = 122;
    printf("%d\n", is_power_of_two(numbers_pow2));
    printf("%d\n", is_power_of_two(numbers_npow2));
    return 0;
}