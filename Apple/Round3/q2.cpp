/*
Concurrency / Real-Time Systems
1. Thread-Safe Queue

Implement a generic thread-safe queue in C++ that supports:

push(T value)
pop()
blocking wait if queue is empty

Requirements:

multiple producers
multiple consumers
use std::mutex + std::condition_variable

Follow-up questions:

How do you shut the queue down safely?
How do you avoid spurious wakeups?
How would you make it bounded?
*/

#include <mutex>
#include <iostream>
#include <queue>
#include <thread>
#include <condition_variable>

template <typename T>
class SafeQueue{
    private:
        std::queue<T> q{};
        std::mutex mtx; //some mutex (not sure how to declare the lock but I know I need something)
        std::condition_variable full;
        std::condition_variable empty;
        int capacity;

    public:
        SafeQueue(int c): capacity(c){}
        void push(T value){
            //need some protection lock
            std::unique_lock<std::mutex> lock(mtx);
            full.wait(lock, [this](){return q.size() < capacity;});
            q.push(value);
            lock.unlock();
            empty.notify_one();
        }
        T pop(){
            std::unique_lock<std::mutex> lock(mtx);
            empty.wait(lock, [this](){ return !q.empty();});
            T value = q.front();
            q.pop();
            lock.unlock();
            full.notify_one();
            return value;
        }
};

SafeQueue<int> qq(10);

void producer_thread(){
    for(int i =0; i< 10; i++){
       qq.push(i); 
       std::cout<<"produced value: " << i<< std::endl;
    }
}
void consumer_thread(){
    for(int i =0; i< 10; i++){
       int v = qq.pop();
       std::cout<< "consumed value: "<< v << std::endl;
    }
}

int main(){
    std::thread t1(producer_thread);
    std::thread t2(consumer_thread);
    t1.join();
    t2.join();
    return 0;
}

