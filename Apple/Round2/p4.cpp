#include <iostream>
#include <thread>
#include <mutex>

std::atomic<int> counter = 0;
//std::mutex mtx;

void increment() { 
    for (int i = 0; i < 1000; i++) {
        //std::lock_guard<std::mutex> lock(mtx); //lock guard mutex approach
        counter++; 
    } 
}

int main(){
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout<< counter << std::endl;
    return 0;
}