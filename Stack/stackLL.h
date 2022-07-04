#include <iostream>
using namespace std;

// *forward declaration
template <typename T>
class Stack;

template <typename T>
class Node {
    T data;
    Node<T> *next;
    friend class Stack<T>;  // * Stack<T> can access the private and protected
                            // members of the Node class
 public:
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
    Node(T data, Node<T> *next) {
        this->data = data;
        this->next = next;
    }
};

template <typename T>
class Stack {
    Node<T> *head;

 public:
    Stack() { this->head = NULL; }
    void push(T data) {
        // !T(N) = O(1)
        Node<T> *n = new Node<T>(data);
        n->next = head;
        head = n;
        n = NULL;
    }
    void pop() {
        // !T(N) = O(1)
        if (this->is_empty())
            return;
        Node<T> *n = this->head;
        this->head = this->head->next;
        delete n;
        n = NULL;
    }
    bool is_empty() { return this->head == NULL; }
    T top() {
        if (this->is_empty())
            return;
        return this->head->data;
    }
    void print_stack() {
        // !T(N) = O(N)
        // print the linked list
        Node<T> *curr = this->head;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
        return;
    }
};
