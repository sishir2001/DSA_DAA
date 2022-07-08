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

class Node;

Node *build_bst(v_ll &nums);
Node *insert(Node *root, ll value);
Node *delete_node(Node *root, ll value);
void inorder_traversal(Node *root);
void levelorder_traversal(Node *root);
bool search(Node *root, int value);
int get_min(Node *root);
void print_range(Node *root, int l, int r);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll T, n;
    cin >> T;
    while (T) {
        cin >> n;
        v_ll nums(n);  // vector
        FOR(i, n, 0) { cin >> nums[i]; }
        Node *root = build_bst(nums);
        inorder_traversal(root);
        NXT_LINE;
        deb(search(root, 14));
        root = delete_node(root, 7);
        inorder_traversal(root);
        NXT_LINE;
        root = insert(root, 7);
        inorder_traversal(root);
        NXT_LINE;
        root = delete_node(root, 8);
        inorder_traversal(root);
        NXT_LINE;
        root = insert(root, 8);
        inorder_traversal(root);
        NXT_LINE;
        levelorder_traversal(root);
        print_range(root, 5, 12);
        NXT_LINE;
        nums.clear();
        T--;
    }
    return 0;
}

class Node {
 public:
    ll data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
    Node(int data, Node *left, Node *right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

Node *build_bst(v_ll &nums) {
    // ! T(N) = O(NH)
    if (nums.size() == 0)
        return NULL;
    Node *root = new Node(nums[0]);
    FOR(i, nums.size(), 1) {
        // !T(N) = O(H) , logN <= H <= N
        insert(root, nums[i]);
    }
    return root;
}

Node *insert(Node *root, ll value) {
    // !T(N) = O(H)
    // !S(N) = O(H)
    if (!root) {
        return new Node(value);
    }
    if (root->data >= value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder_traversal(Node *root) {
    if (!root)
        return;
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}

bool search(Node *root, int value) {
    // !T(N) = O(H)
    // !S(N) = O(H)
    if (!root)
        return false;
    if (root->data == value)
        return true;
    bool res = false;
    if (root->data >= value)
        res = search(root->left, value);
    else
        res = search(root->right, value);
    return res;
}

Node *delete_node(Node *root, ll value) {
    // !T(N) = O(H)
    // !S(N) = O(H)
    if (!root)
        return NULL;
    if (root->data == value) {
        if (!root->left && !root->right) {
            // leaf node
            delete root;
            return NULL;
        } else if (!root->left || !root->right) {
            // only one child
            Node *curr = root->left ? root->left : root->right;
            root->left = root->right = NULL;
            delete root;
            root = NULL;
            return curr;
        } else {
            // has both children
            int temp = get_min(root->right);
            root->data = temp;
            root->right = delete_node(root->right, temp);
            return root;
        }
    }
    if (root->data > value) {
        root->left = delete_node(root->left, value);
    } else {
        root->right = delete_node(root->right, value);
    }
    return root;
}

int get_min(Node *root) {
    if (!root->left)
        return root->data;
    return get_min(root->left);
}

void levelorder_traversal(Node *root) {
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        Node *curr = q.front();
        q.pop();
        if (!curr) {
            // null
            if (!q.empty())
                q.push(NULL);
            continue;
        }
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
        cout << curr->data << " ";
    }
    NXT_LINE;
}

void print_range(Node *root, int l, int r) {
    if (!root)
        return;
    if (root->data <= l) {
        // goto right
        if (root->data == l)
            cout << l << " ";
        print_range(root->right, l, r);
    } else if (root->data >= r) {
        // goto left
        if (root->data == r)
            cout << r << " ";
        print_range(root->left, l, r);
    } else {
        // in btwn
        cout << root->data << " ";
        print_range(root->left, l, r);
        print_range(root->right, l, r);
    }
    return;
}