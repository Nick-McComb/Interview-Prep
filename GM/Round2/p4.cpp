/*
valid parenthesis
*/
#include <iostream>
#include <stack>
#include <unordered_map>

// "{]"

int validpar(const std::string& s){
    std::stack<char> keep;
    std::unordered_map<char, char> match {{'}', '{'}, { ']', '['}, { ')', '('}};

    for(auto& c: s){
        if(c == '{' || c == '[' || c == '('){
            keep.push(c);
        }
        else{
            if(keep.empty()){ return false;}
            if(keep.top() != match[c]){
                return false;
            }
            keep.pop();
        }
    }
    return keep.empty();
}



int main(){
    const std::string input1 = "()[]{}";
    const std::string input2 = "([]";
    std::cout << validpar(input1) << '\n';
    std::cout << validpar(input2) << std::endl;

    return 0;
}