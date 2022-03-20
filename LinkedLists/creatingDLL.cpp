// doubly linked-list 
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

// struct for doubly linked list 
struct Node{

    int data;
    Node *prev;
    Node *next;
    Node (int d){
        data = d;
        prev = NULL;
        next = NULL;
    }
};

void printDLL(Node *head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

void printReverseDLL(Node *head){
    // going to the last node 
    while(head->next){
        head = head->next;
    }
    // printing in reverse now 
    while(head){
        cout << head->data << " ";
        head = head->prev;
    }
    cout << "\n";
}

Node *insertBegin(Node *h,int data){
    // !T(N) = O(1)
    // !S(N) = O(1)

    // Allocation of memory for new node
    Node *temp = new Node(data);
    temp->next = h;
    if(h){
        // h != null
        h->prev = temp;
    }
    return temp;
}

Node *insertEnd(Node *h,int data){
    // !T(N) = O(N)
    // !S(N) = O(1)

    Node *temp = new Node(data);
    if(!h)
        return temp;
    
    Node *curr = h;
    // traverse the DLL
    while(curr->next){
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;
    return h;
}

Node *reverseDLL(Node *h){
    // !T(N) = O(N)
    // !S(N) = O(1)

    if(!h)
        return NULL;
    Node *r = NULL,*p = NULL;
    while(h){
        r = h;
        h = h->next;
        if(h)
            h->prev = NULL;
        r->next = p;
        if(p)
            p->prev = r;
        p = r;
    }
    return r;
}

Node *deleteHead(Node *h){
    // !T(N) = O(1)
    // !S(N) = O(1)
    if(!h)
        return NULL;
    Node *temp = h->next;
    if(temp)
        temp->prev = NULL;
    h->next = NULL;
    delete h;
    return temp;
}

Node *deleteTail(Node *h){
    // ! T(N) = O(N)
    // !S(N) = O(1)

    if(!h)
        return NULL;
    if(!h->next){
        // only single node 
        delete h;
        return NULL;
    }

    Node *curr = h;
    while(curr->next){
        curr = curr->next;
    }

    Node *prev = curr->prev;
    prev->next = NULL;
    curr->prev = NULL;
    delete curr;
    return h;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // creating a doubly LL of three nodes
    // Node *head = new Node(10);
    // Node *temp1 = new Node(20);
    // Node *temp2 = new Node(30);

    // head->next = temp1;
    // temp1->prev = head;
    // temp1->next = temp2;
    // temp2->prev = temp1;
    
    Node *head = insertBegin(NULL,30);
    head = insertBegin(head,20);
    head = insertBegin(head,10);
    printDLL(head);
    printReverseDLL(head);

    head = insertEnd(head,40);
    printDLL(head);
    
    head = reverseDLL(head);
    printDLL(head);

    head = deleteHead(head);
    printDLL(head);

    head = deleteTail(head);
    printDLL(head);

    return 0;
}
