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

class List;

class Node{
	int data;
	Node *next;
public:
	Node(){
		this->data = 0;
		this->next = NULL;
	}
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
	~Node(){
		// recursively deletes all the linked list
		if(this->next)
			delete this->next;
	}
	friend class List;
};

class List{
	Node *head,*tail;
public:
	List(){
		this->head = NULL;
		this->head = NULL;
	}

	List(int data){
		this->head = new Node(data);
		this->tail = this->head;
	}
	~List(){
		delete this->head;
		this->head = NULL;
	}

	Node *begin(){
		return this->head;
	}

	int begin_value(){
		if(this->head){
			return this->head->data;
		}
		return INT32_MIN;
	}

	Node *end(){
		return this->tail;
	}

	int end_value(){
		if(this->tail){
			return this->tail->data;
		}
		return INT32_MIN;
	}

	void insert_at_begin(int data){
		Node *t = new Node(data);
		t->next = this->head;
		if(!this->head){
			this->tail = t;
		}
		this->head = t;
		t = NULL;
	}

	void append(int data){
		Node *t = new Node(data);
		if(!this->tail){
			this->head = this->tail = t;
		}
		else{
			this->tail->next = t;
			this->tail = this->tail->next;
		}
	}

	void insert_at_pos(int data,int pos){
		// ! T(N) = O(N)
		// ! S(N) = O(1)
		// insert at begining 
		if(pos == 1){
			return this->insert_at_begin(data);
		}

		int curr_pos = 1;
		Node *curr = this->head,*prev = NULL;

		while(curr && curr_pos < pos){
			prev = curr;
			curr = curr->next;
			curr_pos++;
		}
		if(curr_pos == pos && !curr){
			// insert at the last
			return this->append(data);
		}
		if(curr_pos == pos && curr){
			// ! insert in between
			Node *t = new Node(data);
			t->next = curr;
			prev->next = t;
		}
	}

	void print_list(){
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
    int T,pos,data;
    cin >> T;
    while(T){
    	cin >> data >> pos;
    	List *l = new List();
    	l->append(1);
    	l->append(2);
    	l->append(3);
    	l->append(4);
    	l->append(5);
    	l->print_list();
    	l->insert_at_pos(data,pos);
    	l->print_list();
        T--;
    }
    return 0;
}
