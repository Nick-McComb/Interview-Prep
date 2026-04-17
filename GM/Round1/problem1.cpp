/*
valid Parentheses

Problem

Determine if a string containing ()[]{} is valid.

Input: "()[]{}"
Output: true

Input: "(]"
Output: false
*/

#include <iostream>
#include <string>
#include <print>
#include <stack>
#include <unordered_map>


bool valid_par(const std::string & s){
    std::stack<char> buffer{};
    std::string open = "({[";
    std::string close = ")}]";
    std::unordered_map<char, char> map{
        {')','('},
        {'}','{'},
        {']','['}
    };
    for(auto & c: s){
        //std::cout<< c << '\n';
        if(open.find(c) != std::string::npos){
            buffer.push(c);
            
        }
        else if(close.find(c) != std::string::npos){
            
            //std::cout<< buffer.top();
            if(buffer.empty()){ return false; }
            if(map[c] == buffer.top()){
                buffer.pop();
            }
            else{ return false;}
        }
    }
    return buffer.empty();
}

int main(){
    const std::string input1 = "()[]{}";
    const std::string input2 = "([]";
    std::cout << valid_par(input1) << '\n';
    std::cout << valid_par(input2) << std::endl;

    return 0;
}

