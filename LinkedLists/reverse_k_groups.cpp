#include <bits/stdc++.h>
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
typedef pair<l, l> p_l;
typedef pair<ul, ul> p_ul;
typedef pair<ll, ll> p_ll;
typedef pair<ull, ull> p_ull;
typedef pair<int, int> p_int;
typedef pair<uint, uint> p_uint;

#define NXT_LINE cout << "\n"
#define EOL      '\n'
#define F        first
#define S        second
#define PB       push_back                         // for vector
#define PPB      pop_back                          // for vector
#define mod      1000000007                        // 1e9+7
#define deb(x)   cout << #x << " = " << x << "\n"  // for debugging
#define deb2(x, y)                                        \
    cout << #x << " = " << x << " , " << #y << " = " << y \
         << "\n"  // for debugging
#define FOR(a, end, start) \
    for (int(a) = (start); (a) < (end); (a)++)  // regular for loop
#define FOR_REV(a, end, start)             \
    for (int(a) = (end)-1; (a) >= (start); \
         (a)--)  // regular for loop decreasing

class Node {
 public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

Node *push_front(Node *head, int x) {
    Node *n = new Node(x);
    if (!head)
        return n;
    n->next = head;
    head = n;
    return head;
}

Node *reverse_k_groups(Node *head, int k);
void print_ll(Node *head);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T, n, k;
    cin >> T;
    while (T) {
        cin >> n >> k;
        // build a linked list
        Node *head = NULL;
        FOR(i, n, 0) {
            int x = 0;
            cin >> x;
            head = push_front(head, x);
        }
        NXT_LINE;
        head = reverse_k_groups(head, k);
        print_ll(head);
        T--;
    }
    return 0;
}

Node *reverse_k_groups(Node *head, int k) {
    // !T(N) = O(N)
    // !S(N) = O(1)
    if (k == 1 || !head || !head->next)
        return head;
    int count = 1;
    Node *r = head, *l = head, *p = head, *prev_tail = NULL, *rev_head = NULL,
         *rev_tail = NULL;

    // getting the k list of nodes
    while (count <= k && r) {
        if (count == k)
            break;
        r = r->next;
        count++;
    }
    if (!r)
        return head;
    // *reverse the linked list
    p = l;
    while (l != r) {
        l = l->next;
        p->next = rev_head;
        if (!rev_head)
            rev_tail = p;
        rev_head = p;
        p = l;
    }
    l = l->next;
    r = r->next;
    count = 1;
    p->next = rev_head;
    rev_head = p;
    head = rev_head;
    prev_tail = rev_tail;
    p = l;
    rev_tail = rev_head = NULL;

    // TODO : need to reverse the left over

    while(r){
        // get k list of elements
        while(count <= k && r){
            if(count == k)
                break;
            count ++;
            r = r->next;
        }
        if(!r){
            prev_tail->next = l;
            return head;
        }
        while(l != r){
            l = l->next;
            p->next = rev_head; // NULL for first time
            if(!rev_head)
                rev_tail = p;
            rev_head = p;
            p = l;
        }
        l = l->next;r = r->next;count = 1;
        p->next = rev_head;
        rev_head = p;
        p = l;
        prev_tail->next = rev_head;
        prev_tail = rev_tail;
        rev_tail = rev_head = NULL;
    }    
    return head;
}

void print_ll(Node *head) {
    Node *curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    NXT_LINE;
}