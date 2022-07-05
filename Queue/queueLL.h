#include <iostream>
using namespace std;

template <typename T>
class Queue_LL;

template <typename T>
class Node {
    T data;
    Node<T> *next;

    friend class Queue_LL<T>;

 public:
    Node<T>(T data) {
        this->data = data;
        this->next = NULL;
    }
    Node<T>(T data, Node<T> *next) {
        this->data = data;
        this->next = next;
    }
};

template <typename T>
class Queue_LL {
    Node<T> *front, *rear;

 public:
    Queue_LL() { this->front = this->rear = NULL; }
    void push(T data) {
        if (!this->front) {
            // no nodes till now
            this->front = new Node<T>(data);
            this->rear = this->front;
        } else {
            Node<T> *n = new Node<T>(data);
            this->rear->next = n;
            this->rear = n;
            n = NULL;
        }
    }
    T pop() {
        if (!this->front)
            return (T)NULL;
        if (this->front == this->rear) {
            // single node
            T res = this->front->data;
            this->rear = NULL;
            delete this->front;
            this->front = NULL;
            return res;
        }
        Node<T> *n = this->front;
        this->front = this->front->next;
        n->next = NULL;
        int res = n->data;
        delete n;
        return res;
    }
    void print_queue() {
        Node<T> *curr = this->front;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
    }
    T front_element() {
        if (!this->front)
            return (T)NULL;
        return this->front->data;
    }
    T rear_element() {
        if (!this->rear)
            return (T)NULL;
        return this->rear->data;
    }
};