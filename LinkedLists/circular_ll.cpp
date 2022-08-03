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

#define NXT_LINE cout << "\n"
#define EOL      '\n'
#define F first
#define S second
#define PB push_back // for vector
#define PPB pop_back // for vector
#define mod 1000000007 // 1e9+7
#define deb(x) cout << #x << " = "<<x<<"\n" // for debugging
#define deb2(x,y) cout << #x << " = "<<x << " , " << #y << " = " << y <<"\n" // for debugging 
#define FOR(a,end,start) for(int (a) = (start);(a) <(end);(a)++) // regular for loop
#define FOR_REV(a,end,start) for(int (a) = (end)-1;(a) >= (start);(a)--) // regular for loop decreasing

// Forward declaration
class List;
class Node {
    int data;
    Node *next;

 public:
    Node(int d) : data(d), next(NULL) {}  // new type of initialization
    ~Node() {
        if (this->next) {
            delete this->next;  // kind of a recursive call
        }
    }
    friend class List;
};

class List {
    Node *head;

 public:
    List() {
        this->head = NULL;
    }
    List(int data) {
        this->head = new Node(data);
        this->head->next = this->head;
    }

    ~List() {
        // destructor
        delete this->head;
        this->head = NULL;
    }

    void push_back(int data){
    	// !T(N) = O(N)
    	// !S(N) = O(1)
    	Node *t = new Node(data);
    	if(!this->head){
    		// head is null
    		this->head = t;
    		this->head->next = this->head;
    		t = NULL;
    		return;
    	}
    	Node *curr = this->head->next;
    	while(curr->next != this->head){
    		curr = curr->next;
    	}
    	curr->next = t;
    	t->next = this->head;
    	t = NULL;
    	return;
    }

    void pop_front(){
    	// !T(N) = O(N)
    	// !S(N) = O(1)
    	if(!this->head)
    		return;
    	if(this->head->next == this->head){
    		// single node in the ll
    		this->head->next = NULL;
    		delete this->head;
    		this->head = NULL;
    		return;
    	}
    	Node *curr = this->head->next;
    	while(curr->next != this->head){
    		curr = curr->next;
    	}
    	curr->next = this->head->next;
    	Node *t = this->head;
    	this->head = t->next;
    	t->next = NULL;
    	delete t;
    	t = NULL;
    	return;
    }

    void push_front(int data){
    	// !T(N) = O(N)
    	// !S(N) = O(1)
    	Node *t = new Node(data);
    	while(!this->head){
    		this->head = t;
    		this->head->next = this->head;
    		t = NULL;
    		return;
    	}
    	Node *curr = this->head->next;
    	while(curr->next != this->head){
    		curr = curr->next;
    	}
    	curr->next = t;
    	t->next = this->head;
    	this->head = t;
    	t = NULL;
    	return;
    }

    void pop_back(){
    	// taking two pointer approach
    	if(!this->head)
    		return;
    	if(this->head->next == this->head){
    		// only single node
    		this->head->next = NULL;
    		delete this->head;
    		this->head = NULL;
    		return;
    	}
    	Node *curr = this->head->next,*prev = this->head;
    	while(curr->next != this->head){
    		prev = curr;
    		curr = curr->next;
    	}
    	prev->next = this->head;
    	curr->next = NULL;
    	delete curr;
    	curr = NULL;
    	return;
    }

    void remove(int pos){
    	if(!this->head)
    		return;
    	if(pos == 1)
    		return this->pop_front();
    	int curr_pos = 2;
    	Node *prev = this->head,*curr = this->head->next;
    	while(curr != this->head){
    		if(curr_pos == pos){
    			// delete the curr node
    			prev->next = curr->next;
    			curr->next = NULL;
    			delete curr;
    			return;
    		}
    		prev = curr;
    		curr = curr->next;
    		curr_pos++;
    	}
    	return;
    }

    void print_cll(){
    	Node *curr = this->head;
    	do{
    		cout << curr->data << " ";
    		curr = curr->next;
    	}while(curr!=this->head);
    	NXT_LINE;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    int T;
    cin >> T;
    while(T){
    	List *l = new List();
    	l->push_front(1);
    	l->push_back(2);
    	l->push_back(3);
    	l->push_front(0);
    	l->print_cll();
    	l->remove(1);
    	l->print_cll();
        T--;
    }
    return 0;
}
