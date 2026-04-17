#include <iostream>
using namespace std;
// n = 10 

int func(uint32_t n){
    if (!n){
        return;
    }
    int prev_prev_value =0;
    int prev_value =1; 
    int curr_value = 0;
    
    cout << prev_prev_value << endl;
        
    if(n >=1){
        cout << prev_value << endl; // 1
        for(int i = 2; i < n; i++){ //4 - > 10
            curr_value = prev_prev_value + prev_value; // curr = 3
            cout << curr_value << endl;
            prev_prev_value = prev_value; //2
            prev_value = curr_value; //3
        }
    }   
}

// 0, 1, 1, 2, 3