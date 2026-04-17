/*
gas station


gas  =  [1,2,3,4,5]
cost = [3,4,5,1,2]
*/
#include <iostream>

#include <vector>

int Eg(std::vector<int> & gas, std::vector<int> & cost){
    int start = 0;
    int tank = 0;
    int total = 0;

    for(int i = 0; i<gas.size(); ++i){
        int diff = gas[i] - cost[i];
        total += diff;
        tank += diff;
        if(tank < 0){
            start = i + 1;
            tank = 0;
        }
    }
    return total>= 0 ? start : -1;
}



int main(){
    std::cout<<"HELLO WORLD\n";
    std::vector<int> gas =  {1,2,3,4,5};
    std::vector<int> cost = {3,4,5,1,2};
    int start = Eg(gas,cost);
    std::cout << start << std::endl;
    return 0;
}