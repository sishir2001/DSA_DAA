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

struct TrieNode{
	TrieNode* child[2];
	bool isEnd;
	TrieNode(){
		isEnd = false;
		for(int i = 0;i < 2;i++){
			child[i] = NULL;
		}
	}
};

void print_matrix(vector<v_ll> &matrix);
void print_vector(v_ll &nums);
void print_all(TrieNode *root,v_ll &res);
ll count_distinct_rows(vector<v_ll> &matrix);


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    ll T, n, m;
    cin >> T;
    while (T) {
        cin >> n >> m;
        // n rows and m cols
        vector<v_ll> matrix(n, v_ll(m, 0));  // 2d matrix
        FOR(i, n, 0) {
            FOR(j, m, 0) { cin >> matrix[i][j]; }
        }

        ll res = count_distinct_rows(matrix);
        deb(res);
        matrix.clear();
        T--;
    }
    return 0;
}

void print_matrix(vector<v_ll> &matrix){
    ll n = matrix.size(),m = matrix[0].size();
    FOR(i,n,0){
        FOR(j,m,0){
            cout << matrix[i][j] << " ";
        }
        NXT_LINE;
    }
}

ll count_distinct_rows(vector<v_ll> &matrix){
	// !T(N) = O(M*N)
	// !S(N) = O(M)

	// !creating a tree node
	TrieNode *root = new TrieNode();
	ll n = matrix.size(),m = matrix[0].size(),count = 0;

	FOR(i,n,0){
		bool is_unique = false;
		TrieNode *curr = root;
		FOR(j,m,0){
			TrieNode *child_node = curr->child[matrix[i][j]];
			if(!child_node){
				// create a new node and attach
				is_unique = true;
				child_node = new TrieNode();
				curr->child[matrix[i][j]] = child_node;
			}
			curr = child_node;
		}
		curr->isEnd = true;
		if(is_unique)
			count++;
	}
	// v_ll res;
	// print_all(root,res);
	return count;
}

void print_all(TrieNode *root,v_ll &res){
	if(!root)
		return;
	if(root->isEnd)
		print_vector(res);
	FOR(i,2,0){
		if(root->child[i]){
			res.PB(i);
			print_all(root->child[i],res);
			res.PPB();
		}
	}
	return;
}

void print_vector(v_ll &nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    NXT_LINE;
}
