/*

Given an array of integers nums and an integer target, return the indices of two numbers that add up to the target.

Example:

nums = [2,7,11,15]
target = 9

Output:

[0,1]

Because:

2 + 7 = 9

*/
#include <iostream>
#include <vector>
#include <unordered_map>

std::tuple<int,int> two_sum(std::vector<int> vec, int target){
    std::unordered_map<int, int> seen{};
    for(int i =0; i<vec.size(); ++i){
        int diff = target-vec.at(i);
        if(seen.contains(diff)){
            return std::tuple(seen[diff], i);
        }
        seen[vec.at(i)] = i;
    }
    return std::tuple(-1,-1);
}

int main(){
    
    std::vector<int> nums = {2,5,11,15};
    int target = 9;
    auto [first,second] = two_sum(nums, target);
    std::cout<<first << ", " << second << std::endl;
    return 0;
}