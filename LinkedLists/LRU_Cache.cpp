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

class LRU_Cache;
class Node{
	int data;
	Node *next,*prev;
	public:
		Node(int data){
			this->data = data;
			this->next = this->prev = NULL;
		}
		~Node(){
			// type of recursion
	        if (this->next) {
	            delete this->next;  // kind of a recursive call
	        }
		}
	friend class LRU_Cache;
};

class LRU_Cache{
	int total_capacity,current_capacity;
	Node *head,*tail;
	map<int,Node*> m;
public:
	LRU_Cache(int x){
		this->current_capacity = 0;
		this->total_capacity = x;
		this->head = this->tail = NULL;
	}

    ~LRU_Cache() {
        // destructor
        delete this->head;
        this->head = NULL;
    }

	Node *front(){
		return this->head;
	}

	Node *back(){
		return this->tail;
	}

	bool search(int data){
		// !T(N) = O(1)
		// !S(N) = O(1)

		bool res = true;
		if(this->m.find(data) == this->m.end())
			res = false;
		return res;
	}

	void push_front(int data){
		// !T(N) = O(1)
		// !S(N) = O(1)

		Node *t = new Node(data);

		// adding to map
		this->m[data] = t;

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
		return;
	}

	void pop_back(){
		// !T(N) = O(1)
		// !S(N) = O(1)

		Node *t = this->tail;
		// erase in map
		this->m.erase(t->data);
		this->tail = this->tail->prev;
		this->tail->next = NULL;
		t->prev = NULL;
		delete t;
		t = NULL;
		return;
	}

	void push(int data){
		// !T(N) = O(1)
		// !S(N) = O(total_capacity)

		// search for the data 
		if(!this->search(data)){
			cout << "MISS : ";
			// miss
			this->push_front(data);
			this->current_capacity++;
			if(this->current_capacity > this->total_capacity){
				this->pop_back();
				this->current_capacity--;
			}
		}
		else{
			// hit 
			cout << "HIT  : ";
			// rearranging of the node to head

			Node *t = this->m[data];
			Node *prev = t->prev,*next = t->next;

			// hit already the recent
			if(!prev)
				return;

			// removing the links at normal position
			t->next = t->prev = NULL;
			prev->next = next;
			if(next)
				next->prev = prev;
			else{
				// updation of tail pointer
				// next  == NULL;
				this->tail = prev;
			}
			// pushing the node at front
			t->next = this->head;
			this->head->prev = t;
			this->head = t;
			t = NULL;
		}
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
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    int T,n,capacity;
    cin >> T;
    while(T){
    	cin >> capacity >> n;
    	LRU_Cache *l = new LRU_Cache(capacity);
    	FOR(i,n,0){
    		int x;
    		cin >> x;
    		deb(x);
    		l->push(x);
    		l->print_dll();
    	}
    	// need to delete the LRU_Cache
    	delete l;
        T--;
    }
    return 0;
}
