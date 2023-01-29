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

typedef map<ll,v_int> Graph;

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

void print_vector(v_ll &nums);

ll helper(Graph &graph,v_ll &visited,v_ll &dp,ll i,ll V){
	visited[i] = 1;
	if(i == V){
		dp[V] = 1;
		return dp[V];
	}
	// visiting ngbrs 
	for(auto ngbr : graph[i]){
		if(visited[ngbr]){
			dp[i] += dp[ngbr];
			dp[i] = dp[i]%mod;
		}
		else{
			// not visited
			dp[i] += helper(graph,visited,dp,ngbr,V);
			dp[i] = dp[i]%mod;
		}
	}
	return dp[i];
}
ll brute_force(Graph &graph,ll i,ll V){
	if(i == V){
		return 1;
	}
	ll ways = 0;
	// visiting ngbrs
	for(auto ngbr : graph[i]){
		ways += brute_force(graph,ngbr,V);
	}
	return ways;
}

// count no of ways to reach from 1 to n in a DAG
ll count_ways(Graph &graph,ll V){
	v_ll visited(V+1,0),dp(V+1,0);
	ll count = helper(graph,visited,dp,1,V);
	// print_vector(visited);
	// print_vector(dp);
	return count;
}

void print_graph(Graph &graph){
	for(auto it : graph){
		cout << it.first << " : ";
		for(auto v : it.second){
			cout << v <<" ";
		}
		NXT_LINE;
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("test_input.txt","r",stdin);
      // freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    ll n,m;
    cin >> n >> m;
    // contruct a graph
    Graph graph;
    FOR(i,m,0){
    	ll a,b;
    	cin >> a >> b;
    	// DAG
    	graph[a].PB(b);
    }
    // cout << "printing graph \n";
    // print_graph(graph);
    // find no of ways to reach from 1 to n
    // can use memorization for improvement in time complexity
    ll count = count_ways(graph,n);
    cout << count << "\n";
    // ll brute = brute_force(graph,1,n);
    // deb(brute);
    return 0;
}

void print_vector(v_ll &nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    NXT_LINE;
}
