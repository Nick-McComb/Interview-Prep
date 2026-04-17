/*
integer palindrome check
*/
#include <stdio.h>
#include <stdbool.h>

bool is_pal(int n){
    int copy = n;
    int flipped = 0;
    while(copy){
        flipped *= 10;
        flipped += copy % 10;
        copy = copy / 10;
    }
    return flipped == n;
}


int main(){
    int test1 = 1234; //false
    int test2 = 1221; //true
    int test3 = 12321;//true
    int test4 = 1; //true
    printf("%d", is_pal(test1));
    printf("%d", is_pal(test2));
    printf("%d", is_pal(test3));
    printf("%d", is_pal(test4));
    return 0;
}