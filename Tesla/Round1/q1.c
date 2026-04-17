#include <stdint.h>
#include <stdio.h>
#include <string.h>

//reverse a string



void reverse_string(char* string){
    char* lp = string;
    char* rp = string + strlen(string) -1;
    //printf("%d", strlen(string));
    while(lp < rp){
        char temp = *lp;
        *lp = *rp;
        *rp = temp;
        lp++;
        rp--;
    }
}

int main(){
    char istring[] = "Hellod"; 
    reverse_string(istring); // converts char[] to char* at the first char of the string
    printf("%s", istring);
    return 0;
}
