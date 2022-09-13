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
        FOR(i,n,0){
            cin >> a[i];
        }
        Node *root = build_bst(a,n);
        inorder_traversal_bst(root);
        root = insert_iterative(root,5);
        NXT_LINE;
        levelorder_traversal_newLine(root);
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

