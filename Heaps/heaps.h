#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> nums;
    void heapify(int i) {
        // !T(N) = O(logN)
        cout << i << "\n";
        if (i >= this->nums.size())
            return;
        int c1 = 2 * i, c2 = 2 * i + 1, mn_idx = i;
        if (c1 < this->nums.size() && this->nums[c1] < this->nums[mn_idx]) {
            mn_idx = c1;
        } else if (c2 < this->nums.size() &&
                   this->nums[c2] < this->nums[mn_idx]) {
            mn_idx = c2;
        }
        if (mn_idx != i) {
            swap(this->nums[mn_idx], this->nums[i]);
            this->heapify(mn_idx);
        }
        return;
    }

 public:
    MinHeap() { this->nums.push_back(-1); }

    void push(int num) {
        // !T(N) = O(H) --> O(logN)
        // !S(N) = O(1)
        this->nums.push_back(num);
        int n = this->nums.size();
        int curr = n - 1, parent = (n - 1) / 2;
        while (parent > 0 && this->nums[parent] > this->nums[curr]) {
            swap(this->nums[parent], this->nums[curr]);
            curr = parent;
            parent = parent / 2;
        }
        return;
    }
    void pop() {
        // pop the min element from heap
        int last = this->nums.size() - 1;
        swap(this->nums[1], this->nums[last]);
        this->nums.pop_back();
        this->heapify(1);
    }

    void print_array() {
        int n = this->nums.size();
        for (int i = 1; i < n; i++) cout << this->nums[i] << " ";
        cout << "\n";
    }
    bool isEmpty() { return this->nums.size() == 1; }
};