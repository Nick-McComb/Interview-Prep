/*
Problem 2.3 — Producer / Consumer (VERY IMPORTANT)

This is directly relevant to camera pipelines.

Scenario:

Producer thread → generates frames

Consumer thread → processes frames

❓ Task:

Implement a thread-safe queue:

template<typename T>
class SafeQueue {
public:
    void push(T value);
    T pop(); // waits if empty
};

Use:

std::mutex

std::condition_variable

🔥 Key behaviors:

pop() should block if queue is empty

Avoid busy waiting

🔥 Follow-ups Apple LOVES:

What happens if producer is faster than consumer?

How do you prevent memory blowup?

Answer:

bounded queue

drop frames (VERY camera-relevant)
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <optional>

template<typename T>
class SafeQueue {
private:
    std::queue<T> q;
    std::mutex mtx;
    std::condition_variable cv;

public:
    // Push a new item into the queue
    void push(T value) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            q.push(std::move(value));
        }
        cv.notify_one(); // wake up one waiting consumer
    }

    // Pop an item; block if empty
    T pop() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return !q.empty(); }); // wait until not empty
        T value = std::move(q.front());
        q.pop();
        return value;
    }

    // Optional: check size (not thread-safe for strict correctness)
    size_t size() {
        std::lock_guard<std::mutex> lock(mtx);
        return q.size();
    }
};

SafeQueue<int> queue;
std::mutex mtx;

void producer() {
    for (int i = 0; i < 10; i++) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            std::cout << "Produced: " << i << "\n";
        }
        queue.push(i);
        //std::this_thread::sleep_for(std::chrono::milliseconds(100)); // simulate work
        //std::cout << "Produced: " << i << "\n";
        //queue.push(i);
    }
}

// Consumer thread → processes "frames"
void consumer() {
    for (int i = 0; i < 10; i++) {
        int value = queue.pop(); // blocks if empty
        {
            std::lock_guard<std::mutex> lock(mtx);
            std::cout << "Consumed: " << value << "\n";
        }
        //std::cout << "Consumed: " << value << "\n";
    }
}

int main(){
    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();
    
    return 0;
}