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

class Doubly_ll;
class Node{
	int data;
	Node *next,*prev;
	public:
		Node(){
			this->data = 0;
			this->next = this->prev = NULL;
		}
		Node(int data){
			this->data = data;
			this->next = this->prev = NULL;
		}
	friend class Doubly_ll;
};

class Doubly_ll{
	Node *head,*tail;
public:
	Doubly_ll(){
		this->head = this->tail = NULL;
	}

	Node *front(){
		return this->head;
	}

	Node *back(){
		return this->tail;
	}

	void push_front(int data){
		Node *t = new Node(data);
		if(!this->head){
			// list is empty
			this->head = this->tail = t;
		}
		else{
			t->next = this->head;
			this->head->prev = t;
			this->head = t;
		}
		t = NULL;
	}

	void pop_front(){
		if(!this->head)
			return;

		if(this->head == this->tail){
			// 1 node list
			this->tail = NULL;
			delete this->head;
			this->head = NULL;
			return ;
		}
		Node *t = this->head;
		this->head = this->head->next;
		this->head->prev = NULL;
		t->next = NULL;
		delete t;
		t = NULL;
		return ;
	}

	void push_back(int data){
		Node *t = new Node(data);
		if(!this->tail){
			// list is empty
			this->head = this->tail = t;
		}
		else{
			this->tail->next = t;
			t->prev = this->tail;
			this->tail = t;
		}
		t = NULL;
	}

	void pop_back(){
		if(!this->tail)
			return;
		if(this->head == this->tail){
			// 1 node list
			this->head = NULL;
			delete this->tail;
			this->tail = NULL;
			return;
		}
		Node *t = this->tail;
		this->tail = this->tail->prev;
		this->tail->next = NULL;
		t->prev = NULL;
		delete t;
		t = NULL;
		return;
	}

	void print_dll(){
		Node *curr = this->head;
		while(curr){
			cout << curr->data << " ";
			curr = curr->next;
		}
		NXT_LINE;
	}

	void print_reverse_dll(){
		Node *curr = this->tail;
		while(curr){
			cout << curr->data << " ";
			curr = curr->prev;
		}
		NXT_LINE;
	}

	void reverse_dll(){
		// !T(N) = O(N)
		// !S(N) = O(1)
		Node *l = this->head,*r = this->tail;
		while(l != r){
			swap(l->data,r->data);
			l = l->next;
			r = r->prev;
		}
		return;
	}

	void reverse_dll_1(){
		if(!this->head || !this->head->next)
			return;
		Node *curr = this->head;
		this->tail = this->head;
		while(curr->next){
			swap(curr->next,curr->prev);
			curr = curr->prev;
		}
		swap(curr->next,curr->prev);
		this->head = curr;
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
    	Doubly_ll *l = new Doubly_ll();
        T--;
    }
    return 0;
}
