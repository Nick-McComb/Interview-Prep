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
#include <string>
#include <unordered_map>


int longestSub(const std::string& s){
    std::unordered_map<char, int> lastseen{};
    int left = 0;
    int maxlen = 0;

    for(int right = 0; right < s.size(); right++){
        char c = s[right];
        if(lastseen.count(c) && lastseen[c] >= left){
            left = lastseen[c] + 1;
        }
        lastseen[c] = right;
        maxlen = std::max(maxlen, right - left +1);
    }
    return maxlen;
}

int main(){
    std:: cout << longestSub("pwwkew") << '\n';
    return 0;
}