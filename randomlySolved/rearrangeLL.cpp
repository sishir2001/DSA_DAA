#include<iostream>

class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class LinkedList{
    public:
        Node* head;
        Node* tail;
        LinkedList(int data){
            this->head = new Node(data);
            this->tail = this->head;
        }
        void append(int data){
            // just changing the tail pointer .
            this->tail->next = new Node(data);
            this->tail = this->tail->next;
        }
        void printLL(){
            Node * curr = this->head;
            while(curr != NULL){
                std::cout<<curr->data<<" ";
                curr = curr->next;
            }
        }
        Node* newLL(){
            Node *newHead = this->tail,*newTail = this->head;
            newHead->next = newTail;
            this->head = this->head->next;
            Node *curr = this->head,*prev = NULL;
            while(this->head->next != NULL){
                // updating the tail
                while(curr->next != NULL){
                    prev = curr;
                    curr = curr->next;
                }
                this->tail = prev;
                prev->next = NULL;
                Node* temp1 = curr;
                curr = NULL;
                delete temp1;
                newTail->next = this->tail;
                newTail = newTail->next;
                newTail->next = this->head;
                newTail = newTail->next;
                this->head = this->head->next;

                curr = this->head;
                prev = NULL;
            }
            return newHead;
        
        }
};

int main(){
    LinkedList *newList = new LinkedList(1);
    newList->append(2);
    newList->append(3);
    newList->append(4);
    newList->append(5);
    newList->printLL();
    Node* rearrangeList = newList->newLL();
    return 0;
    
}
