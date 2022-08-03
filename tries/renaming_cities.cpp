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
	ll count; // for assigning purpose
	TrieNode(){
		isEnd = false;
		count = 0;
		for(int i = 0;i < 26;i++){
			child[i] = NULL;
		}
	}
};

void print_all_words(TrieNode *root,string res);
void assign_railway_codes(vector<string> &nums);
void modified_insert(TrieNode *root,string s);

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
    	FOR(i,n,0){
    		cin >> nums[i];
    	}
    	assign_railway_codes(nums);
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

void assign_railway_codes(vector<string> &nums){
	// !T(N) = O(N*WordLength)
	ll n = nums.size();
	TrieNode *root = new TrieNode();
	FOR(i,n,0){
		modified_insert(root,nums[i]);
	}
}

void modified_insert(TrieNode *root,string s){
	TrieNode *curr = root;
	string res = "";
	bool is_print = false;
	ll n = s.length();
	FOR(i,n,0){
		ll idx = s[i]-'a';
		if(!is_print)
			res = res + s[i];
		if(!curr->child[idx]){
			// create and link the child node
			curr->child[idx] = new TrieNode();
			curr->child[idx]->count = 1;
			if(!is_print)
				is_print = true;
		}
		curr = curr->child[idx];
	}
	if(is_print || (!is_print && !curr->isEnd)){
		// got unique word
		cout << res << "\n";
	}
	else if(!is_print){
		// did not get a unique word
		curr->count++;
		cout << res << " " << curr->count << "\n";
	}
	curr->isEnd = true;
}
