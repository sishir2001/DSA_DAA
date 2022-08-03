#include <iostream>
using namespace std;

template <typename T>
class Queue_arr {
    T *arr;
    int max_capacity, size, front, rear;

 public:
    Queue_arr(int n) {
        this->arr = new T[n];
        this->max_capacity = n;
        this->front = this->size = 0;
        this->rear = -1;
    }
    void push(T data) {
        if ((this->rear + 1) % this->max_capacity != this->front ||
            this->rear == -1) {
            // we can push
            this->rear = (this->rear + 1) % this->max_capacity;
            this->arr[this->rear] = data;
            this->size++;
        }
    }
    T pop() {
        if (this->size == 0)
            return (T)NULL;
        this->size--;
        int res = this->arr[this->front];
        this->front = (this->front + 1) % this->max_capacity;
        if (this->size == 0) {
            this->front = 0;
            this->rear = -1;
        }
        return res;
    }
    void print_queue() {
        if (this->size == 0)
            return;
        for (int i = this->front; i % this->max_capacity != this->rear; i++) {
            cout << this->arr[i] << " ";
        }
        cout << this->arr[this->rear] << "\n";
    }
};

