#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>


template<typename T>
class SafeQueue{
    private:
        std::queue<T> q;
        std::mutex mtx;
        std::condition_variable cv;
        const size_t MAX_SIZE = 5;
        bool done = false;
    public:
        void push(T value){
            
            std::lock_guard<std::mutex> lock(mtx);
            if(q.size() >= MAX_SIZE){
                q.pop();
                std::cout << "Dropped frame\n";
            }
            q.push(std::move(value));            
            cv.notify_one();
        }

        T pop(){
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this](){return !q.empty() || done;}); //wait until q is not empty
            if(q.empty()){std::cout<< "All products consumed!\n"; return 0;}
            T value = q.front();
            q.pop();
            return value;
        }
        void setDone(){
            std::lock_guard<std::mutex> lock(mtx);
            done = true;
            cv.notify_all();
        }
};


SafeQueue<int> q;
std::mutex mtx;


void producer(){
    for(int i =0; i<10; i++){
        //std::this_thread::sleep_for(std::chrono::milliseconds(30));
        q.push(i);
        std::cout<< "Produced: "<< i << '\n';
    }
    q.setDone();
}

void consumer(){
    for(int i =0; i<10; i++){
        std::cout<< "Consumed: "<< q.pop() << '\n';
    }
}

int main(){

    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();
    return 0;
}