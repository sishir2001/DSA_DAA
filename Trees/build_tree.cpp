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

// preorder build
Node *preorder_build(v_ll &nums, int *i);
Node *levelorder_build(v_ll &nums);
void preorder_traversal(Node *root);
void inorder_traversal(Node *root);
void postorder_traversal(Node *root);
void levelorder_traversal(Node *root);
int height_of_tree(Node *root);

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
        Node *root = levelorder_build(nums);
        nums.clear();
        T--;
    }
    return 0;
}

class Node {
 public:
    int data;
    Node *right, *left;
    Node(int data) {
        this->data = data;
        this->right = this->left = NULL;
    }
};

Node *preorder_build(v_ll &nums, int *i) {
    // * preorder build of a tree root-left-right
    if (*i == nums.size() || nums[*i] == -1)
        return NULL;
    Node *root = new Node(nums[*i]);
    *i += 1;
    root->left = preorder_build(nums, i);
    *i += 1;
    root->right = preorder_build(nums, i);
    return root;
}

void preorder_traversal(Node *root) {
    // * left root right
    if (!root) {
        return;
    }
    cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(Node *root) {
    // * left root right
    if (!root) {
        return;
    }
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}

void postorder_traversal(Node *root) {
    // * left right root
    if (!root)
        return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->data << " ";
}

void levelorder_traversal(Node *root) {
    // * we need breadth search
    // we iterate over a queue
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        // pushing the children of the front of queue
        if (!q.front()) {
            q.pop();
            NXT_LINE;
            if (!q.empty())
                q.push(NULL);
            continue;
        }
        Node *front = q.front();
        q.pop();
        if (front->left)
            q.push(front->left);
        if (front->right)
            q.push(front->right);
        cout << front->data << " ";
    }
}

Node *levelorder_build(v_ll &nums) {
    // iterative approach using queue
    if (nums.size() == 0 || nums[0] == -1)
        return NULL;
    int i = 0;
    Node *root = new Node(nums[0]);
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *curr = q.front();
        i++;
        curr->left = nums[i] == -1 ? NULL : new Node(nums[i]);
        i++;
        curr->right = nums[i] == -1 ? NULL : new Node(nums[i]);
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
        q.pop();
    }
    return root;
}

int height_of_tree(Node *root) {
    if (!root)
        return 0;
    return max(height_of_tree(root->left), height_of_tree(root->right)) + 1;
}