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
    Node *next,*prev;

 public:
    Node(int d) : data(d), next(NULL),prev(NULL) {}  // new type of initialization
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
        this->head->prev = this->head;
    }
    // ~List() {
    //     // destructor
    //     delete this->head;
    //     this->head = NULL;
    // }

    void print_cdll(){
    	if(!this->head)
    		return;
    	Node *curr = this->head;
    	while(curr->next != this->head){
    		cout << curr->data << " ";
    		curr = curr->next;
    	}
    	cout << curr->data << "\n";
    	return;
    }

    void print_reverse_cdll(){
    	if(!this->head)
    		return;
    	Node *curr = this->head->prev;
    	while(curr != this->head){
    		cout << curr->data << " ";
    		curr = curr->prev;
    	}
    	cout << curr->data << "\n";
    	return;
    }

    void push_back(int data){
    	// !T(N) = O(1)
    	// !S(N) = O(1)
    	Node *t = new Node(data);
    	if(!this->head){
    		// create a node
    		this->head = t;
    		this->head->next = this->head;
    		this->head->prev = this->head;
    		return;
    	}
    	Node *tail = this->head->prev;
    	tail->next = t;
    	t->prev = tail;
    	t->next = this->head;
    	this->head->prev = t;
    	t = tail = NULL;
    	return;
    }

    void pop_back(){
    	// !T(N) = O(1)
    	// !S(N) = O(1)

    	if(!this->head)
    		return;
    	if(this->head->next == this->head){
    		// single doubly circular linked list
    		this->head->prev = this->head->next = NULL;
    		delete this->head;
    		this->head = NULL;
    		return;
    	}

    	Node *tail = this->head->prev;
    	Node *prev = tail->prev;
    	tail->prev = NULL;
    	prev->next = tail->next;
    	tail->next = NULL;
    	this->head->prev = prev;
    	delete tail;
    	tail = NULL; 
    	return;
    }

    void pop_front(){
    	// !T(N) = O(1)
    	// !S(N) = O(1)
    	if(!this->head)
    		return;
    	if(this->head->next == this->head){
    		// single doubly circular linked list
    		this->head->prev = this->head->next = NULL;
    		delete this->head;
    		this->head = NULL;
    		return;
    	}
    	Node *tail = this->head->prev,*t = this->head;
    	this->head = this->head->next;
    	tail->next = this->head;
    	this->head->prev = tail;
    	t->next = t->prev = NULL;
    	delete t;
    	t = NULL;
    	return ;
    }

    void push_front(int data){
    	// !T(N) = O(1)
    	// !S(N) = O(1)

    	Node *t = new Node(data);
    	if(!this->head){
    		this->head = t;
    		this->head->next = this->head->prev = this->head;
    		return;
    	}
    	Node *tail = this->head->prev;
    	tail->next = t;
    	t->prev = tail;
    	t->next = this->head;
    	this->head->prev = t;
    	this->head = t;
    	t = tail = NULL;
    	return;
    }

    void remove(int pos){
    	// @param pos : position of the element to be deleted
    	if(pos == 1)
    		return this->pop_front();
    	if(!this->head || (this->head->next == this->head && pos > 1))
    		return;
    	int curr_pos = 2;
    	Node *curr = this->head->next;
    	while(curr != this->head && curr_pos <= pos){
    		if(curr_pos == pos){
    			// delete the current node
    			Node *prev = curr->prev,*next = curr->next;
    			prev->next = curr->next;
    			next->prev = prev;
    			curr->next = curr->prev = NULL;
    			delete curr;
    			prev = next = curr = NULL;
    			break;
    		}
    		curr_pos++;
    		curr = curr->next;
    	}
    	return;
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
    	List *l = new List(1);
    	l->print_cdll();
    	l->print_reverse_cdll();
    	l->push_back(2);
    	l->push_back(3);
    	l->push_back(4);
    	l->print_cdll();
    	l->print_reverse_cdll();
    	l->push_front(0);
    	l->print_cdll();
    	l->print_reverse_cdll();
    	l->pop_back();
    	l->print_cdll();
    	l->print_reverse_cdll();
    	l->pop_front();
    	l->print_cdll();
    	l->print_reverse_cdll();
    	l->remove(1);
    	l->print_cdll();
    	l->print_reverse_cdll();
    	l->pop_front();
    	l->print_cdll();
    	l->remove(4);
    	l->print_cdll();
        T--;
    }
    return 0;
}
