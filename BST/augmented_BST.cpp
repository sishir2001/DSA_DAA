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
#define FOR(a,end,start) for(ll (a) = (start);(a) <(end);(a)++) // regular for loop
#define FOR_REV(a,end,start) for(ll (a) = (end)-1;(a) >= (start);(a)--) // regular for loop decreasing

class Node{
public:
	int val,l,r;
	Node *left,*right;
	Node (int _val){
		this->val = _val;
		l = r = 0;
		left = right = NULL;
	}
};

Node *insert(Node *root,int _val);
Node *build_augmented_bst(v_ll &nums);
Node *delete_node_bst(Node *root,int _val);
int delete_inorder_successor(Node *root);
Node *search(Node *root,int val);
Node *kth_smallest(Node *root,int k,int add);
void inorder_traversal_bst(Node *root,int add);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    ll T,n,k;
    cin >> T;
    while(T){
        cin >> n >> k;
        v_ll nums(n); // vector
        FOR(i,n,0){
            cin >> nums[i];
        }
        Node *root = build_augmented_bst(nums);
        inorder_traversal_bst(root,0);
        NXT_LINE;
        Node *k_small = kth_smallest(root,k,0);
        if(!k_small){
        	cout << "NULL\n" ;
        }
        else{
        	cout << k_small->val <<"\n";
        }
        nums.clear();
        T--;
    }
    return 0;
}

Node *insert(Node *root,int _val){
	if(!root)
		return new Node(_val);
	if(_val < root->val){
		root->left = insert(root->left,_val);
		root->l++;
	}
	else{
		root->right = insert(root->right,_val);
		root->r++;
	}
	return root;
}

Node *build_augmented_bst(v_ll &nums){
	Node *root = NULL;
	for(auto i : nums){
		root = insert(root,i);
	}
	return root;
}

int delete_inorder_successor(Node *root){
	if(!root->left)
		return root->val;
	return delete_inorder_successor(root->left);
}

Node *delete_node_bst(Node *root,int _val){
	// assuming given _val is present in the BST
	if(!root)
		return NULL;
	if(_val < root->val){
		root->left = delete_node_bst(root->left,_val);
		root->l--;
	}
	else if(_val > root->val){
		root->right = delete_node_bst(root->right,_val);
		root->r--;
	}
	else{
		if(!root->left && !root->right){
			delete root;
			root = NULL;
		}
		else if(!root->left || !root->right){
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
		else{
			root->val = delete_inorder_successor(root->right);
			root->right = delete_node_bst(root->right,root->val);
			root->r--;
		}
	}
	return root;
}

Node *search(Node *root,int val){
	if(!root)
		return NULL;
	if(val == root->val)
		return root;
	else if(val < root->val)
		return search(root->left,val);
	return search(root->right,val);
}

Node *kth_smallest(Node *root,int k,int add){
	// default @param add = 0
	// !T(N) = O(H)
	// !S(N) = O(H)
	if(!root)
		return NULL;
	int curr_pos = add+root->l+1;
	// deb2(add,root->l);
	// deb2(curr_pos,root->val);
	if(curr_pos == k)
		return root;
	else if(curr_pos > k)
		return kth_smallest(root->left,k,add);
	return kth_smallest(root->right,k,curr_pos);
}

void inorder_traversal_bst(Node *root,int add){
	if(!root)
		return;
	inorder_traversal_bst(root->left,add);
	int curr_pos = add+root->l+1;
	cout << curr_pos << ":" << root->val << " ";
	inorder_traversal_bst(root->right,curr_pos);
	return;
}
