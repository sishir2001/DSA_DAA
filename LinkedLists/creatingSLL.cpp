#include<bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long l;
typedef unsigned long ul;
typedef long long ll;
typedef unsigned long long ull;

typedef vector<l> v_l;
typedef vector<ul> v_ul;
typedef vector<ll> v_ll;
typedef vector<ull> v_ull;
typedef vector<int> v_int;
typedef vector<uint> v_uint;
typedef pair<l,l> p_l;
typedef pair<ul,ul> p_ul;
typedef pair<ll,ll> p_ll;
typedef pair<ull,ull> p_ull;
typedef pair<int,int> p_int;
typedef pair<uint,uint> p_uint;

#define F first;
#define S second;
#define PB push_back // for vector
#define PPB pop_back // for vector
#define mod 1000000007 // 1e9+7
#define deb(x) cout << #x << " = "<<x<<"\n" // for debugging
#define deb2(x,y) cout << #x << " = "<<x << " , " << #y << " = " << y <<"\n" // for debugging 
#define FOR(a,end) for(int (a) = 0;(a) < (end);(a)++) // regular for loop
#define FOR_REV(a,start) for(int (a) = (start)-1;(a) >= 0;(a)--) // regular for loop decreasing
#define FOR_less(a,end,start) for(int (a) = (start);(a) < (end);(a)++) // regular for loop
#define FOR_REV_great(a,end,start) for(int (a) = (start);(a) > (end);(a)--) // regular for loop
#define FOR_less_or_equal(a,end,start) for(int (a) = (start);(a) <= (end);(a)++) // regular for loop
#define FOR_REV_great_or_equal(a,end,start) for(int (a) = (start);(a) >= (end);(a)--) // regular for loop

struct  Node
{
    int data; // here data can be of any type 
    Node *next ; // pointer that points to the next address of Node , self-referential pointer
    // contructor - by default everything is public in struct
    Node(int x){
        data = x;
        next = NULL;
    }
};

// struct  Single_LL
// {
//     // this is a struct that stores head and tail pointers of a linked list
//     Node *head;
//     Node *tail;

//     Single_LL(Node *h,Node *t){
//         head = h;
//         tail = t;
//     }
// };

void RecursivePrintSLL(Node *h){
    // !T(N) = O(N)
    // !S(N) = O(N) -> auxilliary space

    if(!h){
        cout << "\n";
        return ;
    }
    cout << h->data <<" ";
    h = h->next;
    RecursivePrintSLL(h); // tail recursion can be avoided 
}

void printSLL(Node *h){
    // h here and head in the main function are different
    while(h){
        cout << h->data << " ";
        h = h->next;
    }
    cout << "\n";
}
 
Node *insertBegin(Node *h,int x){
    // !T(N) = O(1)
    // !S(N) = O(1)

    Node *temp = new Node(x);
    if(!h){
        return temp;
    }
    temp->next = h;
    h = temp;
    return h;

}
 
Node *insertEnd(Node *h,int x){
    // !T(N) = O(N)
    // !S(N) = O(1)

    Node *temp = new Node(x);
    if(!h){
        return temp;
    }
    // traverse the linked list
    Node *curr = h;
    while(curr->next){
        curr = curr->next;
    }
    curr->next = temp;
    return h;
}

Node* insertAtAnyPos(Node *head,int pos,int data){

    // !T(N) = O(N)
    // !S(N) = O(1)

    Node *temp = new Node(data);
    int currPos = 2;

    if(!head && pos > 1)
        return NULL;

    if(pos == 1){
        temp->next = head;
        head = temp;
        return head;
    }

    Node *prev = head,*curr = head->next;

    while(curr){
        if(pos == currPos){
            // need to insert at pos
            temp->next = curr;
            prev->next = temp;
            return head;
        }
        currPos +=1;
        prev = curr;
        curr = curr->next;
    }

    // explicitly for adding at the end
    if(pos == currPos){
        temp->next = NULL;
        prev->next = temp;
    }

    return head;
}

int searchLinkedList(Node *head,int key){

    // ! T(N) = O(N)
    // ! S(N) = O(1)

    int index = 1;
    while(head){
        if(key == head->data)
            return index;
        index += 1;
        head = head->next;
    }
    return -1;
}

Node *deleteHead(Node *head){
    if(!head)
        return NULL;
    Node *temp = head->next;
    delete head; // avoiding the memory leaks 
    return temp;
}

Node *deleteTail(Node *head){
    if(!head){
        return NULL;
    }
    // ! need to explicitly handle this case to handle null pointer reference on prev pointer
    if(!head->next){
        // only one node
        delete head;
        return NULL;
    }

    Node *prev = NULL,*curr = head;
    while(curr->next){
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL; 
    delete curr;
    return head;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // we need to allocate the struct in heap , dynamic allocation
    Node *head = insertBegin(NULL,30);
    // Single_LL *ll = new Single_LL(head,head);
    head = insertBegin(head,20);
    // ll->head = head;
    
    head = insertBegin(head,10);
    // ll->head = head;
    printSLL(head);

    // inserting at the end 
    head = insertEnd(head,40);
    printSLL(head);

    head = deleteHead(head);
    printSLL(head);

    head = deleteTail(head);
    printSLL(head);


    head = insertAtAnyPos(head,3,200);
    printSLL(head);

    cout << searchLinkedList(head,30) << "\n";

    return 0;
}