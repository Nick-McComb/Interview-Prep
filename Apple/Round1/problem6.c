/*
string palindrome

string = "Hello"
string = "ababa"
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_pal(char* str){
    int size = strlen(str);
    if(!size){
        return false;
    }
    char* start = str;
    char* end = str + size - 1;
    while(start<end){
        if(*start != *end){
            return false;
        }
        start++;
        end--;
    }
    return true;
}


int main(){
    char test1[] = "Hello"; //false
    char test2[] = "ababa"; //true
    char test3[] = "a"; //true
    char test4[] = ""; //false?
    printf("%d", is_pal(test1));
    printf("%d", is_pal(test2));
    printf("%d", is_pal(test3));
    printf("%d", is_pal(test4));
    return 0;
}