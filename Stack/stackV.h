#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
template <typename T>
class Stack_V {
    vector<T> *v;

 public:
    Stack_V() { v = new vector<T>(); }
    void push(T data) {
        this->v->push_back(data);
        return;
    }
    bool is_empty() { return this->v->size() == 0; }
    void pop() {
        if (!this->is_empty())
            this->v->pop_back();
        return;
    }
    T top() {
        if (this->is_empty()) {
            return this->v[this->v.size() - 1];
        }
    }
    void print_stack() {
        // reverse iterator
        for (auto it = v->rbegin(); it != v->rend(); it++) {
            cout << *it << " ";
        }
        cout << "\n";
        return;
    }
};