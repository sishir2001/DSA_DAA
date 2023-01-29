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

void print_graph(vector<v_ll> &graph);
ll dfs(vector<v_ll> &graph,v_ll &visited,ll i);
int astronaut_pairs(vector<v_ll> &graph);
void print_vector(v_ll &nums);
ll count_pairs(v_ll &nums);

int main(){
	// NOT PASSING A TEST CASE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    ll n,pair_size; // n : no of astronauts
    cin >> n >> pair_size;
    vector<v_ll> graph(n);
    FOR(i,pair_size,0){
    	ll x,y ;
    	cin >> x >> y;
    	graph[x].PB(y);
    	graph[y].PB(x);
    }
    // print_graph(graph);
    ll res = astronaut_pairs(graph);
    cout << res << "\n";
    return 0;
}

void print_graph(vector<v_ll> &graph){
	for(auto u : graph){
		for(auto v : u){
			cout << v << " ";
		}
		NXT_LINE;
	}
}

ll dfs(vector<v_ll> &graph,v_ll &visited,ll i){
	if(i >= (ll)graph.size())
		return 0;
	visited[i] = 1;
	ll count = 1;
	for(auto v : graph[i]){
		if(!visited[v]){
			count += dfs(graph,visited,v);
		}
	}
	return count;
}

int astronaut_pairs(vector<v_ll> &graph){
	ll n = graph.size();
	v_ll visited(n,0);
	v_ll count;

	FOR(i,n,0){
		if(!visited[i]){
			count.PB(dfs(graph,visited,i));
		}
	}
	// print_vector(count);
	return count_pairs(count);
}

void print_vector(v_ll &nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    NXT_LINE;
}

ll count_pairs(v_ll &nums){
	ll n = nums.size(),res = 0;
	ll sum = nums[n-1];
	for(ll i = n-2;i >= 0;i--){
		res += nums[i]*sum;
		sum += nums[i];
	}
	return res;
}
