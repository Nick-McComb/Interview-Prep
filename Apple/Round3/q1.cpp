/*
Contains Duplicate
Easy
Topics
Company Tags
Hints
Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.

Example 1:

Input: nums = [1, 2, 3, 3]

Output: true

Example 2:

Input: nums = [1, 2, 3, 4]

Output: false
*/

// edge cases: 
// if list is empty return false
// if one element in list then return false


// 1. create map
// 2. loop thru the list
// 3. check if the item is in map
// if it is return true 
// else add it to the map and continue

#include <unordered_map>
#include <vector>
#include <iostream>

bool hasDuplicate(const std::vector<int> & nums){
    if(nums.size() < 2){
        return false;
    }

    std::unordered_map<int, int> seen{};

    for(const auto & n : nums){
        if(seen.contains(n)){
            return true;
        }
        seen[n] = 1;
    }
    return false;
}


int main(){
    const std::vector<int> nums {1, 2, 3, 4};
    std::cout<<"This function has duplicate values : " <<hasDuplicate(nums)<< '\n';
}

