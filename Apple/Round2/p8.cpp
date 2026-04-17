/*
Problem — Longest Substring Without Repeating Characters

Given a string s, return the length of the longest substring that contains no repeating characters.

Examples
Input:  "abcabcbb"
Output: 3
Explanation: "abc"

Input:  "bbbbb"
Output: 1
Explanation: "b"

Input:  "pwwkew"
Output: 3
Explanation: "wke"
*/
#include <iostream>
#include <unordered_map>

int longestSub(const std::string & s){

    std::unordered_map<char,int> last_seen{};
    int left = 0;
    int maxlen =0;

    for(int right = 0; right < s.size(); right++){
        char c = s[right];

        if(last_seen.count(c) && last_seen[c] >= left){
            left = last_seen[c] + 1;
        }

        last_seen[c]= right;
        maxlen = std::max(maxlen, right - left + 1);
    }
    return maxlen;
}


int main(){
    std:: cout << longestSub("abcabcbb") << '\n';

    return 0;
}