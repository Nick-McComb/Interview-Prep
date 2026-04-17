#include <stdio.h>
#include <string.h>
#include <stdint.h>

void *memmove_safe(void *dest, const void *src, size_t n){
    
    if (dest == src || n == 0) {
        return dest;
    }

    uint8_t* d = (uint8_t*)dest;
    const uint8_t* s = (const uint8_t*)src;
    
    

    if(dest < src){
        for(size_t i = 0; i<n; i++){
            d[i] = s[i];
        }
    }
    else if(dest > src){
        for(size_t i = n; i>0; i--){
            d[i-1] = s[i-1];
        }
    }
}