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

ll find_set(v_ll &parent,ll i){
	if(parent[i] == -1)
		return i;
	parent[i] = find_set(parent,parent[i]);
	return parent[i];
}

ll union_set(v_ll &parent,v_ll &rank,ll i,ll j,ll count){
	// !T(N) = O(1) on average ,for rank based union
	ll s1 = find_set(parent,i),s2 = find_set(parent,j);
	if(s1 != s2){
		count--;
		if(rank[s1] >= rank[s2]){
			rank[s1] += rank[s2];
			parent[s2] = s1;
		}
		else{
			rank[s2] += rank[s1];
			parent[s1] = s2;
		}
	}
	return count;
}

ll solve(vector<v_ll> &nums,ll n,ll m){
	// n : rows , m : cols
	// T(N) = O(n*m)
	v_ll parent(n*m,-1),rank(n*m,1),rows(n,-1),cols(m,-1);
	ll count = n*m;
	FOR(i,n,0){
		FOR(j,m,0){
			ll idx = m*i+j;
			if(nums[i][j] == 0){
				count --;
				parent[idx] = -2;
			}
			else{
				// check rows
				if(rows[i] != -1){
					// can communicate
					int root_idx = m*i+rows[i];
					count = union_set(parent,rank,idx,root_idx,count);
				}
				else{
					rows[i] = j;
				}

				// check cols
				if(cols[j] != -1){
					int root_idx = m*cols[j] + j;
					count = union_set(parent,rank,idx,root_idx,count);
				}
				else{
					cols[j] = i; 
				}
			}
		}
	}
	return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif

    ll T,n,m;
    cin >> T;
    while(T){
    	cin >> n >> m;
    	// create a matrix
    	vector<v_ll> nums(n,v_ll(m,0));
    	FOR(i,n,0){
    		FOR(j,m,0){
    			cin >> nums[i][j];
    		}
    	}

    	// calculate no of groups of towers
    	deb(solve(nums,n,m));

        T--;
    }
    return 0;
}
