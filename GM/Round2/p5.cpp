#include <iostream>
#include <vector>



std::vector<int> productExceptSelf(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> product(n,1);


    int left = 1;
    for(int i = 0 ; i<n; i++){
        product[i] = left;
        left *= nums[i];
    }
    int right = 1;
    for(int i = n-1; 0 <= i; i--){
        product[i] *= right;
        right *= nums[i];
    }

    return product;
}

int main(){
    std::vector<int> Input{1, 2, 3, 4};
    auto Output= productExceptSelf(Input);
    for(auto& i: Output){
        std::cout << i << ' ';
    }
}