/*
Input:  intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
*/
#include <iostream>
#include <vector>

std::vector<std::vector<int>> mergeInterval(std::vector<std::vector<int>>& interval){
    
    if(interval.empty()){ return {};}
    
    std::vector<std::vector<int>> result{};

    result.push_back(interval[0]);
    
    //{{1,3},{2,6},{8,10},{15,18}}
    for(int i = 1; i < interval.size(); i++){
        std::vector<int>& vec = result.back();
        if(interval[i][0] <= vec[1]){
            vec[1] = std::max(interval[i][1], vec[1]);
        }
        else{
            result.push_back(interval[i]);
        }
    }
    return result;
}


int main(){
    std::cout<< "Hello world!\n";
    std::vector<std::vector<int>> intervals{{1,3},{2,6},{8,10},{15,18}};
    auto output = mergeInterval(intervals);
    for(auto& vec: output){
        
        std::cout <<'[' << vec[0] << ',' <<  vec[1] << "]\n";
        
    }
    return 0;
}