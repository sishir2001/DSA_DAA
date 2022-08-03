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
	bool isEnd;
	map<char,TrieNode*> m; // map instead of array
	TrieNode(){
		isEnd = false;
	}
};

void modified_insert(TrieNode *root,string s);
void assign_username(vector<string> &nums);

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
    	assign_username(nums);
        T--;
    }
    return 0;
}

void modified_insert(TrieNode *root,string s){
	// Traverse the string 
	ll n = s.length();
	TrieNode *curr = root;
	FOR(i,n,0){
		if(curr->m.find(s[i]) == curr->m.end()){
			// create a node and link it 
			curr->m[s[i]] = new TrieNode();
		}
		curr = curr->m[s[i]];
	}

	bool is_unique = false;
	if(curr->isEnd){
		// not unique , need to make is unique
		for(int i = 0;i < 10;i++){
			char x = char(i+48);
			if(curr->m.find(x) == curr->m.end()){
				// found 
				curr->m[x] = new TrieNode();
				curr->m[x]->isEnd = true;
				cout << s << x << "\n";
				return;
			}
		}
	}
	else{
		// unique
		is_unique = true;
		curr->isEnd = true;
	}
	if(is_unique)
		cout << s << "\n";
	else{
		cout << "No unique username found \n";
	}
}
void assign_username(vector<string> &nums){
	ll n = nums.size();
	TrieNode *root = new TrieNode();
	FOR(i,n,0){
		modified_insert(root,nums[i]);
	}
}
