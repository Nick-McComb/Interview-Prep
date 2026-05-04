/*18. Sliding Window Maximum

Given array + window size k,
return max of every window.

Concepts:

deque
O(n)*/
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

vector<int> maxWindows(vector<int> v, int k) {
    if (k > v.size() || k == 0) {
        return {};
    }
    //{1,3,2,7,8,4,2}
    deque<int> d; //[0]
    vector<int> max_values;

    for (int i = 0; i < v.size(); i++) {

        
        while (!d.empty() && d.front() <= i - k) {
            d.pop_front();
        }

        
        while (!d.empty() && v[d.back()] < v[i]) {
            d.pop_back();
        }

        d.push_back(i);

        
        if (i >= k - 1) {
            max_values.push_back(v[d.front()]);
        }
    }

    return max_values;
}


int main(){
    vector<int> m = maxWindows({1,3,2,7,8,4,2}, 3);
    for(const auto v : m){
        cout<< v << endl;
    }
}