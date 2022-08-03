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

struct TrieNode{
	TrieNode *child[26];
	bool isEnd;
	TrieNode(){
		isEnd = false;
		for(int i = 0;i < 26;i++){
			child[i] = NULL;
		}
	}
};

void insert(TrieNode *root,string s);
bool search(TrieNode *root,string s);
void remove(TrieNode *root,string s,int i);
void print_all_words(TrieNode *root,string res);
void auto_complete(TrieNode *root,string s);

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
    	vector<string> nums(n,"");
    	string s;
    	FOR(i,n,0){
    		cin >> nums[i];
    	}
    	cin >> s;
    	// inserting the words in trie
    	TrieNode *root = new TrieNode();
    	FOR(i,n,0){
    		insert(root,nums[i]);
    	}
    	auto_complete(root,s);
    	// print_all_words(root,"");
        T--;
    }
    return 0;
}

void print_all_words(TrieNode *root,string res){
	if(!root)
		return;
	if(root->isEnd)
		cout << res << "\n";

	FOR(i,26,0){
		if(root->child[i]){
			res.push_back(char(i+'a'));
			print_all_words(root->child[i],res);
			res.pop_back();
		}
	}
	return;
}

void insert(TrieNode *root,string s){
	// traverse the string and root
	int n = s.length();
	if(!root){
		// create a node 
		root = new TrieNode();
	}

	TrieNode *curr = root;
	for(int i = 0;i < n;i++){
		int idx = s[i]-'a';
		if(!curr->child[idx]){
			// create a new child node and link it
			curr->child[idx] = new TrieNode();
		}
		curr = curr->child[idx];
	}
	curr->isEnd = true;
}

bool search(TrieNode *root,string s){
	// !T(N) = O(s.length())
	// !S(N) = O(1)

	if(s == "" || !root)
		return false;
	int n = s.length();
	TrieNode *curr = root;
	FOR(i,n,0){
		int idx = s[i]-'a';
		if(!curr->child[idx])
			return false;
		curr = curr->child[idx];
	}
	return curr->isEnd;
}

void remove(TrieNode *root,string s,int i){
	// !T(N) = O(s.length())
	// !S(N) = O(s.length())

	if(!root || i >= s.length())
		return;
	int idx = s[i]-'a';
	TrieNode *child_node = root->child[idx];
	if(i != s.length()-1)
		remove(child_node,s,i+1);

	else{
		// count the children that are not null
		int count = 0;
		FOR(i,26,0){
			if(child_node->child[i] != NULL){
				count++;
				break;
			}
		}

		if(count != 0){
			// there are children 
			child_node->isEnd = false;
		}
		else{
			// * deleting the memory of the child node
			root->child[idx] = NULL;
			delete child_node;
			child_node = NULL;
		}
	}
	return;
}

void auto_complete(TrieNode *root,string s){
	// TODO : traverse the string 
	TrieNode *curr = root;
	FOR(i,s.length(),0){
		int idx = s[i]-'a';
		if(!curr->child[idx])
			return;
		curr = curr->child[idx];
	}
	// printing all the words under current root
	print_all_words(curr,s);
}
