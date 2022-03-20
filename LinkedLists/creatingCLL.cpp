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

struct Node {
    int data;
    Node *next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

void printCLL(Node *head){
    // printing the circular linked list 
    if(!head)
        return;

    Node *curr = head;
    do{
        cout << curr->data << " " ;
        curr = curr->next;
    }while(curr!=head);
    cout <<"\n";
}

Node *insertBeginNaive(Node *h,int data){
    // ! Naive insertion in circular linked list
    // !T(N) = O(N)
    // !S(N) = O(1)

    Node *temp = new Node(data);
    if(!h){
        temp->next = temp;
        return temp;
    }

    Node *curr = h;
    while(curr->next != h){
        curr = curr->next;
    }
    temp->next = curr->next; // head
    curr->next = temp;
    return temp; // temp is the new head
}

Node *insertBeginOpt(Node *h,int data){
    // !T(N) = O(1)
    // !S(N) = O(1)

    Node *temp = new Node(data);
    if(!h){
        temp->next = temp;
        return temp;
    }
    temp->next = h->next;
    h->next = temp;
    swap(h->data,temp->data);
    return h;
}

Node *insertEndNaive(Node *h,int data){
    // !T(N) = O(N)
    // !S(N) = O(1)

    Node *temp = new Node(data);
    if(!h){
        temp->next = temp;
        return temp;
    }
    Node *curr = h;
    while(curr->next != h){
        curr = curr->next;
    }
    temp->next = h;
    curr->next = temp;
    return h;

}
Node *insertEndOpt(Node *h,int data){
    // !T(N) = O(1)
    // !S(N) = O(1)
    Node *temp = new Node(data);
    if(!h){
        temp->next = temp;
        return temp;
    }
    temp->next = h->next;
    h->next = temp;
    swap(h->data,temp->data);
    h = temp;
    return h;
    

}

Node *deleteHeadNaive(Node *h){
    // !T(N) = O(N)
    // !S(N)= O(1)

    // @ to optimisize it we need to maintain a tail pointer
    if(!h)
        return NULL;
    if(h->next == h){
        // single node 
        delete h;
        return NULL;
    }
    Node *curr = h;
    do{
        curr = curr->next;
    }while(curr->next != h);

    curr->next = h->next;// curr->next will be the new head
    delete h;
    return curr->next;
}

Node *deleteHeadOpt(Node *h){
    // !T(N) = O(1)
    // !S(N) = O(1)

    if(!h)
        return NULL;
    if(h->next == h){
        delete h;
        return NULL;
    }
    // Swapping the data in the adjacent node 
    Node *temp = h->next;
    swap(h->data,temp->data);
    h->next = temp->next;
    delete temp;
    return h;
}

Node *deleteKCLL(Node *h,int k){
    // !T(N) = O(K)
    // !S(N) = O(1)
    // k <= Length(CLL)
    if(k == 1)
        return deleteHeadOpt(h);
    Node *prev = h,*curr = h->next;
    int count = 2;
    while(curr != h){
        if(count == k){
            // should delete the node 
            prev->next = curr->next;
            delete curr;
            return h;
        }
        count++;
        prev = curr;
        curr = curr->next;
    }
    return h; // passed on out of bound k 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // creating a new node 
    // for adding last node , we just need the tail node 
    Node *head = insertBeginOpt(NULL,30);
    head = insertBeginOpt(head,20);
    head = insertBeginOpt(head,10);
    head = insertBeginOpt(head,5);
    printCLL(head);
    head = insertEndOpt(head,40);
    head = insertEndOpt(head,50);
    printCLL(head);
    head = deleteHeadNaive(head);
    head = deleteHeadOpt(head);
    head = deleteHeadOpt(head);
    printCLL(head);
    head = deleteKCLL(head,1);
    printCLL(head);

    return 0;
}
