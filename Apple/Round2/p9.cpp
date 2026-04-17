#include <iostream>
#include <list>
#include <unordered_map>


class LRU{
    private:
        int capacity{10};
        std::list<std::pair<int, int>> cache{};
        std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map{};


    public:
        int get(const int & key){
            //not found
            if(!map.count(key)){
                return -1;
            }
            auto it = map[key];
            cache.splice(cache.begin(), cache, it);
            return it->second;
        }

        void put(int key, int value) {
        // If key already exists → update and move to front
        if (map.find(key) != map.end()) {
            auto it = map[key];
            it->second = value;

            cache.splice(cache.begin(), cache, it);
            return;
        }

        // If full → evict LRU (back of list)
        if (cache.size() == capacity) {
            auto lru = cache.back();
            map.erase(lru.first);
            cache.pop_back();
        }

        // Insert new node at front
        cache.emplace_front(key, value);
        map[key] = cache.begin();
    }
};



int main(){
    std::cout<<"Hello world!\n";
    return 0;
}