/*
3sum
*/
#include <iostream>
#include <vector>
#include <algorithm>



std::vector<std::vector<int>> threeSum(std::vector<int> & vec){
    std::vector<std::vector<int>> pairs{};

    std::sort(vec.begin(), vec.end());

    for(int i =0; i< vec.size(); ++i){
        if(i>0 && vec[i] == vec[i-1]){continue;}
        int left = i + 1;
        int right = vec.size() -1;
        while(left < right){
            int sum = vec[i] + vec[left] + vec[right];
            if(sum == 0){
                pairs.push_back({vec[i],vec[left],vec[right]});

                while(left < right && vec[left] == vec[left+1]){ left++; }
                while(left < right && vec[right] == vec[right-1]){ right--; }
                left++;
                right--;
            }
            else if(sum< 0){
                left++;
            }
            else{
                right--;
            }
        }
    }
    return pairs;
}


int main(){
    std::vector<int> test{-1, 0, 1, 2, -1, -4};
    for(auto& val: test){
        std::cout<< val << '\n';
    }
    auto vecs = threeSum(test);
    for(auto& vec : vecs){
        for(auto& c : vec){
            std::cout<< c << ' ';
        }
        std::cout<< '\n';
    }
    return 0;
}