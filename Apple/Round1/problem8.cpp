
#include <iostream>
#include <vector>


std::vector<std::vector<int>> rotate_ninety(std::vector<std::vector<int>> image){
    std::vector<std::vector<int>> new_image{};
    int width = image[0].size();
    for(int i = 0; i< width; ++i){
        std::vector<int> row{};
        for(int size = image.size() -1; size >= 0; --size)
            {
                row.push_back(image[size][i]);
            }
        new_image.push_back(row);
    }
    return new_image;
}


int main(){
    std::cout<< "Hello World!\n";
    std::vector<std::vector<int>> image = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    std::vector<std::vector<int>> new_image = rotate_ninety(image);
    for(auto vec: new_image){
        for(auto val: vec){
            std::cout<<val;
        }
        std::cout<<'\n';
    }
    return 0;
}