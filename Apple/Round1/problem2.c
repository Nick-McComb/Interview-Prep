/*
2. Reverse a String (Pointer Basics)

Problem

Write a function that reverses a string in place.

Example:

input: "hello"
output: "olleh"
Signature
void reverse(char *str)
Key Idea

Use two pointers:

start → ← end

Swap until they meet.

Example:

hello
^   ^

Swap h and o. 
*/

#include <stdio.h>
#include <string.h>


void reverse(char *string){
    int size = strlen(string);
    char * begin = string;
    char * end = string + size -1;
    
    while(begin < end){
        char temp = *begin;
        *begin = *end;
        *end = temp;
        begin++;
        end--;
    }
}



int main(){

    char test[] = "Hello"; // '\0'
    printf("%s\n", test);
    reverse(test);
    printf(test);
    return 0;
}
