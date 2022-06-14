#include <iostream>
using namespace std;

template <typename T>
class Vector {
    T *x;
    int capacity, last_index = 0;

 public:
    Vector(int n) {
        // @n : capacity of the vector
        this->x = new T[n];
        this->capacity = n;
    }
    ~Vector() {
        delete[] this->x;
        this->x = NULL;
    }
    void Push_Back(const T value) {
        if (this->last_index == this->capacity) {
            // !T(N) = O(N)
            // TODO : create a dynamic array with 2X capacity
            this->capacity *= 2;
            T *y = new T[this->capacity];
            // TODO : copy all the elements from x to y
            for (int i = 0; i < last_index; i++) {
                y[i] = this->x[i];
            }
            y[last_index++] = value;
            delete[] this->x;
            this->x = y;
            y = NULL;
        } else {
            // !T(N) = O(1)
            // TODO: assign the value
            this->x[this->last_index++] = value;
        }
    }
    void Pop_Back() {
        // !T(N) = O(N)
        // removing the last element
        if (this->last_index > 0) {
            this->x[last_index - 1] = 0;
            last_index--;
        }
    }
    T front() const { return this->x[0]; }
    T back() const { return this->x[this->last_index - 1]; }
    T At(const int i) const { return this->x[i]; }
    int size() const { return this->last_index; }
    int get_capacity() const { return this->capacity; }
    T operator[](const int i) { return this->x[i]; }
    void Print() const {
        for (int i = 0; i < last_index; i++) cout << this->x[i] << " ";
        cout << "\n";
    }
};