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
    Node *head, *tail;

 public:
    List() {
        this->head = NULL;
        this->tail = NULL;
    }
    List(int data) {
        this->head = new Node(data);
        this->tail = this->head;
    }

    ~List() {
        // destructor
        delete this->head;
        this->head = NULL;
    }

    Node *begin() { return this->head; }
    void set_begin(Node *head) { this->head = head; }
    Node *back() { return this->tail; }
    void set_back(Node *tail) { this->tail = tail; }

    void push_front(int data) {
        Node *n = new Node(data);
        if (!this->head) {
            // head and tail are null
            this->head = n;
            this->tail = n;
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
        Node *n = new Node(data);
        if (!this->head) {
            // head and tail are null
            this->head = n;
            this->tail = n;
        } else {
            this->tail->next = n;
            this->tail = n;
        }
    }

    void pop_front() {
        if (!this->head)
            return;
        else if (!this->head->next) {
            // only single node ,
            this->tail = NULL;
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
            this->tail = NULL;
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
            this->tail = prev;
            this->tail->next = NULL;
            delete curr;
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

    int middle_ll(){
        // !T(N) = O(N)
        // !S(N) = O(1)
        // using fast and slow pointer
        if(!this->head)
            return 0;
        if(!this->head->next)
            return head->data;

        Node *slow = head,*fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    List *reverse_list(List *l) {
        // !T(N) = O(N)
        Node *curr = l->begin(), *rev_head = NULL, *rev_tail = NULL,
             *p = l->begin();
        List *r_l = new List();
        while (curr) {
            curr = curr->next;
            p->next = rev_head;
            if (!rev_head) {
                rev_tail = p;
            }
            rev_head = p;
            p = curr;
        }
        r_l->set_begin(rev_head);
        r_l->set_back(rev_tail);
        return r_l;
    }

    void print_list() {
        Node *curr = this->head;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
    }

    void sorted_insert(int x){
        // !T(N) = O(N)
        // !S(N) = O(1)

        Node *t = new Node(x);
    	if(!this->head){
            this->head = t;
            t = NULL;
            return;
        }

    	if(x <= this->head->data){
    		t->next = this->head;
    		this->head =t;
    		t = NULL;
    		return;
    	}
    	Node *curr = this->head;
        Node *prev = NULL;
    	while(curr && x > curr->data){
    		prev = curr;
    		curr = curr->next;
    	}
    	t->next = curr;
    	prev->next = t;
    	t = prev = curr = NULL;
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
    	List *l = new List();
    	l->sorted_insert(5);
        l->sorted_insert(40);
        l->sorted_insert(15);
        l->sorted_insert(50);
        l->sorted_insert(0);
    	l->print_list();
        int middle = l->middle_ll();
        deb(middle);
        T--;
    }
    return 0;
}
