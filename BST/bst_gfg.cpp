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

class Node {
public:
	int val;
	Node *left,*right;
	Node(int _val){
		this->val = _val;
		this->right = this->left = NULL;
	}
	Node(int _val,Node *_left,Node *_right){
		this->val = _val;
		this->right = _right;
		this->left = _left;
	}
};

void levelorder_traversal_newLine(Node *root);
Node *insert_iterative(Node *root,int val);
Node *insert(Node *root,int val);
Node *build_bst(int *arr,int n);
void inorder_traversal_bst(Node *root);
// find inorder successor 
pair<Node*,int> inorder_successor(Node *root);
// delete a node in BST
Node *delete_node(Node *root,int val);
Node *floor_BST(Node *root,int val);
Node *floor_BST_iterative(Node *root,int val);
Node *ceil_BST(Node *root,int val);
void inorder_traversal_bst_iteratively(Node *root);
Node *insert_ceil(Node *root,int val,v_int &res);
v_int ceiling_left_side(v_int &nums);
v_int ceiling_left_side_set(v_int &nums);
void print_vector(v_int &nums);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    int T,n;
    cin >> T;
    while(T){
        cin >> n;
        int *a = new int[n];
        v_int nums;
        FOR(i,n,0){
            cin >> a[i];
            nums.PB(a[i]);
        }
        v_int res = ceiling_left_side(nums);
        v_int res1 = ceiling_left_side_set(nums);
        print_vector(res);
        print_vector(nums);
        print_vector(res1);
        delete []a;
        T--;
    }
    return 0;
}

void levelorder_traversal_newLine(Node *root){
	if(!root)
		return;
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		Node *f = q.front();q.pop();
		if(!f){
			cout << "\n";
			if(!q.empty()){
				q.push(NULL);
			}
			continue;
		}
		cout << f->val << " ";
		if(f->left)
			q.push(f->left);
		if(f->right)
			q.push(f->right);
	}
	return;
}

Node *insert_iterative(Node *root,int val){
	// ! better than recursive insert in bst
	// !T(N) = O(H)
	// !S(N) = O(!)
	// Iterative insert of node in BST
	if(!root)
		return new Node(val);
	Node *prev = NULL,*curr = root;
	bool left = false,right = false;
	while(curr){
		prev = curr;
		if(val < curr->val){
			left = true;
			right = false;
			curr = curr->left;
		}
		else if(val > curr->val){
			right = true;
			left = false;
			curr = curr->right;
		}
		else{
			right = left = false;
			break;
		}
	}
	if(left){
		prev->left = new Node(val);
	}
	else if(right){
		prev->right = new Node(val);
	}
	return root;
}

Node *insert(Node *root,int val){
	// !T(N) = O(H)
	// !S(N) = O(H)
	// Recursive insert
 	if(!root)
		return new Node(val);
	if(val < root->val)
		root->left = insert(root->left,val);
	else if(val > root->val)
		root->right = insert(root->right,val);
	return root;
}

Node *build_bst(int *arr,int n){
	if(n == 0)
		return NULL;
	Node *root = new Node(arr[0]);
	FOR(i,n,1){
		root = insert(root,arr[i]);
	}
	return root;
}

void inorder_traversal_bst(Node *root){
	if(!root)
		return;
	inorder_traversal_bst(root->left);
	cout << root->val << " ";
	inorder_traversal_bst(root->right);
	return;
}

pair<Node*,int> inorder_successor(Node *root){
	if(!root->left){
		int t = root->val;
		Node *right = root->right;
		root->right = NULL;
		delete root;
		root = NULL;
		return make_pair(right,t);
	}
	pair<Node*,int> left = inorder_successor(root->left);
	root->left = left.first;
	return make_pair(root,left.second);
}

Node *delete_node(Node *root,int val){
	if(!root)
		return NULL;
	if(root->val == val){
		// check the type of node 
		if(!root->left && !root->right){
			// just delete and return NULL
			delete root;
			root = NULL;
		}
		else if(!root->left || !root->right){
			// either one is null
			Node *t = root;
			if(root->left){
				root = root->left;
				t->left = NULL;
			}
			else{
				root = root->right;
				t->right = NULL;
			}
			delete t;
			t = NULL;
		}
		else {
			// both children are present
			pair<Node*,int> succ = inorder_successor(root->right);
			root->right = succ.first;
			root->val = succ.second;
		}
	}
	else if(val < root->val){
		root->left = delete_node(root->left,val);
	}
	else {
		root->right = delete_node(root->right,val);
	}
	return root;
}

Node *floor_BST(Node *root,int val){
	// !T(N) = O(N)
	// !S(N) = O(N) due to recursion
	if(!root)
		return NULL;
	Node *res = NULL;
	if(val == root->val)
		return root;
	else if(val < root->val)
		res = floor_BST(root->left,val);
	else
		res = floor_BST(root->right,val);
	if(!res && val > root->val)
		return root;
	return res;
}

Node *ceil_BST(Node *root,int val){
	// !T(N) = O(N)
	// !S(N) = O(N) due to recursion
	if(!root)
		return NULL;
	Node *res = NULL;
	if(val == root->val)
		return root;
	else if(val < root->val)
		res = ceil_BST(root->left,val);
	else
		res = ceil_BST(root->right,val);
	if(!res && val < root->val)
		return root;
	return res;
}

Node *floor_BST_iterative(Node *root,int val){
	// !T(N) = O(N)
	// !S(N) =O(1)
	Node *floor = NULL,*curr = root;
	while(curr){
		if(curr->val == val){
			floor = curr;
			break;
		}
		else if(val < curr->val){
			curr = curr->left;
		}
		else{
			floor = curr;
			curr = curr->right;
		}
	}
	return floor;
}

void inorder_traversal_bst_iteratively(Node *root){
	// using stack 
	if(!root)
		return;
	stack<Node*> s;
	s.push(root);
	while(!s.empty()){
		Node *t = s.top();
		if(!t){
			s.pop();
			if(!s.empty()){
				t = s.top();s.pop();
				cout << t->val << " ";
				s.push(t->right);
			}
		}
		else{
			s.push(t->left);
		}
	}
	return;
}

Node *insert_ceil(Node *root,int val,v_int &res){
	// T(N) = O(NlogN)
	// S(N) = O(H), height of the BST
	if(!root){
		root = new Node(val);
		res.push_back(-1);
		return root;
	}
	Node *curr = root,*parent = NULL,*ceil = NULL;
	while(curr){
		if(val == curr->val){
			res.push_back(val);
			return root;
		}
		else if(val < curr->val){
			ceil = parent = curr;
			curr = curr->left;
		}
		else{
			parent = curr;
			curr = curr->right;
		}
	}
	if(parent->val < val){
		parent->right = new Node(val);
	}
	else{
		parent->left = new Node(val);
	}
	if(!ceil){
		res.push_back(-1);
	}
	else{
		res.push_back(ceil->val);
	}
	return root;
}

v_int ceiling_left_side(v_int &nums){
	v_int res;
	Node *root = NULL;
	for(auto i:nums){
		root = insert_ceil(root,i,res);
	}
	return res;
}

void print_vector(v_int &nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    NXT_LINE;
}

v_int ceiling_left_side_set(v_int &nums){
	// !T(N) = O(NlogN)
	// S(N) = O(N)
	// using set
	set<int> s;
	v_int res;
	for(auto i : nums){
		set<int>::iterator it = s.lower_bound(i);
		if(it == s.end()){
			res.PB(-1);
		}
		else{
			res.PB(*it);
		}
		s.insert(i);
	}
	return res;

}
