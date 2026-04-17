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
#include <unordered_map>
#include <vector>
#include <string>
#include <expected>

using namespace std;

constexpr std::expected<std::tuple<int, int>,std::string> TwoSum(std::vector<int> v, int target){
    std::unordered_map<int, int> difference = {};
    for(size_t i =0; auto val: v){
        if(difference.contains(target-val)){
            return std::tuple{difference[target-val], i};
        }
        difference[val] = i;
        i++;
    }
    return std::unexpected("NO VALUE FOUND");
}

int main(){
    std::cout << "Hello World\n";

    std::vector<int> test_vector{2,3,11,15,7};
    constexpr int target = 9;
    
    auto test = TwoSum(test_vector, target);
    if(test.has_value()){
        auto [a,b] = *test;
        std::cout << a << ' ' << b;
    }
    else{
        std::cout << test.error() << "\n";
    }

    return 0;
}