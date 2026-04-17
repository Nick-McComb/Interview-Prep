/*
Check to see how many 3 letter palindromes are in a string without using repeats 

"aaa" = 1
"abcda" = 1
"aaaabc" = 2
*/

#include <iostream>
#include <string>
#include <unordered_map>
int ThreePal(const std::string & s){
    std::unordered_map<char, int>dict{};
    for(auto c : s){
        dict[c]++;    
    }
    
    int duplicates = 0;
    int singles = 0;
    for(auto& [key, value] : dict){
        //std::cout<< key << ' ' << value << '\n';
        duplicates += value/2; 
        singles += value % 2; // 1 or 0
        
    }

    int total = duplicates*2 + singles;

    return std::min(duplicates, total / 3);
}

int main(){
    
    std::string s1 = "aaa";
    std::string s2 = "abcda";
    std::string s3 = "aaaabc";
    std::string s4 = "aaaaab";
    std::cout << ThreePal(s1) << '\n';
    std::cout << ThreePal(s2) << '\n';
    std::cout << ThreePal(s3) << '\n';
    std::cout << ThreePal(s4) << std::endl;

    return 0;
}