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

struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int d){
        data = d;
        prev = NULL;
        next = NULL;
    }
};

void printCDLL(Node *h){
    // traversing the circular-doubly-ll
    if(!h)
        return;
    Node *curr = h;
    do{
        cout << curr->data << " ";
        curr = curr->next;
    }while(curr != h);
    cout << "\n";
}

void printReverse(Node *head){
    if(!head)
        return;
    Node *tail = head->prev,*curr = head->prev;
    do{
        cout << curr->data <<" ";
        curr = curr->prev;
    }while(curr != tail);
    cout << "\n";
}

Node *insertBegin(Node *h,int data){
    // !T(N) = O(1)
    // !S(N) = O(1)

    Node *temp = new Node(data); // CDLL
    if(!h){
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }
    Node *tail = h->prev;

    // inserting a new head
    temp->next = h;
    temp->prev = tail;
    tail->next = temp;
    h->prev = temp;
    h = temp;
    return h;
}

Node *insertEnd(Node *h,int data){

    // !T(N) = O(1)
    // !S(N) = O(1)
    Node *temp = new Node(data); // CDLL
    if(!h){
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }
    Node *tail = h->prev;
    temp->prev = tail;
    temp->next = h;
    h->prev = temp;
    tail->next = temp;
    return h;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Node *head = insertBegin(NULL,30);
    head = insertBegin(head,20);
    head = insertBegin(head,10);
    head = insertEnd(head,40);
    printCDLL(head);
    // printReverse(head);

    return 0;
}
