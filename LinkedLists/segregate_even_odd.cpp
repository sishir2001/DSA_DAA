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
    }

    ~List() {
        // destructor
        delete this->head;
        this->head = NULL;
    }

    Node *begin() { return this->head; }
    void set_begin(Node *head) { this->head = head; }

    void push_front(int data) {
        Node *n = new Node(data);
        if (!this->head) {
            // head and tail are null
            this->head = n;
        } else {
            n->next = this->head;
            this->head = n;
        }
    }

    int search(int data) {
        // 0-indexing
        int idx = 0;
        Node *curr = this->head;
        while (curr) {
            if (data == curr->data)
                return idx;
            curr = curr->next;
            idx++;
        }
        return -1;
    }

    void push_back(int data) {
    	// !T(N) = O(N)
    	// !S(N) = O(1)
    	Node *t = new Node(data),*curr = this->head;
    	while(curr->next){
    		curr = curr->next;
    	}
    	curr->next = t;
    	t = NULL;
    }

    void pop_front() {
        if (!this->head)
            return;
        else if (!this->head->next) {
            // only single node ,
            delete this->head;
            this->head = NULL;
        } else {
            Node *temp = this->head;
            this->head = this->head->next;
            temp->next = NULL;
            delete temp;
            temp = NULL;
        }
    }
    void pop_back() {
        if (!this->head)
            return;
        else if (!this->head->next) {
            // single node
            delete this->head;
            this->head = NULL;
        } else {
            // > 1 node
            // TODO : loop till the prev_last node
            Node *prev = NULL, *curr = this->head;
            while (curr->next) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;
            delete curr;
            curr = NULL;
        }
    }

    void insert(int data, int pos) {
        if (pos == 0) {
            this->push_front(data);
            return;
        }
        // 1->2->3->4
        Node *curr = this->head->next, *prev = this->head;
        int curr_pos = 1;
        Node *temp = new Node(data);
        while (curr) {
            if (curr_pos == pos) {
                temp->next = curr;
                prev->next = temp;
            }
            prev = curr;
            curr = curr->next;
            curr_pos++;
        }
        if (curr_pos == pos) {
            prev->next = temp;
        }
        return;
    }
    void remove(int pos) {
        if (pos == 0)
            this->pop_front();
        int curr_pos = 1;
        Node *curr = this->head->next, *prev = this->head;
        while (curr) {
            if (curr_pos == pos) {
                prev->next = curr->next;
                curr->next = NULL;
                delete curr;
                curr = NULL;
                return;
            }
            prev = curr;
            curr = curr->next;
            curr_pos++;
        }
    }

    void reverse_list() {
    	Node *temp = this->head;
    	Node *curr = temp,*prev = NULL;
    	while(temp){
    		temp = temp->next;
    		curr->next = prev;
    		prev = curr;
    		curr = temp;
    	}
    	this->head = prev;
    	prev = curr= NULL;
    	return;
    }

    void print_list() {
        Node *curr = this->head;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
    }

    void segregate_even_oddd(){
    	// !T(N) = O(N)
    	// !S(N) = O(1)
    	// !relative ordering of even and odd should be maintained
    	Node *curr = this->head,*prev = NULL,*odd_head = NULL,*odd_tail = NULL,*even_head = NULL;
    	while(curr){
    		if((curr->data&1) == 0){
    			// even
    			if(!even_head)
    				even_head = curr;
    			prev = curr;
    			curr = curr->next;
    		}
    		else{
    			// odd
    			if(!prev){
    				if(!odd_tail){
    					odd_head = odd_tail = curr;
    				}
    				else{
    					odd_tail->next = curr;
    					odd_tail = curr;
    				}
    			}
    			else{
    				// changing the link
    				prev->next = curr->next;
    				if(!odd_tail){
    					odd_head = odd_tail = curr;
    				}
    				else{
    					odd_tail->next = curr;
    					odd_tail = curr;
    				}
    			}
    			curr = curr->next;
    			odd_tail->next = NULL;
    		}
    	}
    	// linking both the chains
    	if(!even_head){
    		// no even list
    		this->head = odd_head;
    	}
    	else{
    		prev->next = odd_head;
    		this->head = even_head;
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
    	l->push_back(2);
    	l->push_back(3);
    	l->push_back(4);
    	l->push_back(5);
    	l->push_back(6);
    	l->push_back(8);
    	l->push_back(7);
    	l->print_list();
    	l->segregate_even_oddd();
    	l->print_list();
        T--;
    }
    return 0;
}
