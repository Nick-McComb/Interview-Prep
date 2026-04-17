#include <iostream>
#include <unordered_map>

//Input:  "abcabcbb"

int longsub(const std::string& s){
    std::unordered_map<char, int> lastseen{};
    int left = 0;
    int max_len = 0;

    for(int right = 0; right < s.size(); right++){
        char c = s[right];
        if(lastseen.count(c) && lastseen[c] >= left){
            left = lastseen[c] +1;
        }
        lastseen[c] = right;
        max_len = std::max(max_len, right - left +1);

    }
    return max_len;
}




int main(){
    std::cout << "hello world!\n";
    return 0;
}