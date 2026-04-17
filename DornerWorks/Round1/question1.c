#include <stdio.h>
#include <string.h>

void reverse_string(char* str){
    char* start = str;
    char* back = str + strlen(str) -1;
    
    while(start < back){
        char temp = *start;
        *start = *back;
        *back = temp;
        start++;
        back--;
    }
    printf("%s\n", str);
}


int main() {
    char text[]= "Hello, World!";
    reverse_string(text);
    return 0;
}