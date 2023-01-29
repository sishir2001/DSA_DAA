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

typedef map<ll,v_ll> Graph;

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

bool dfs(Graph &graph,v_ll &visited,ll parent,ll source,ll score){
	// true : not bipartate graph
	visited[source] = score;
	// visiting neigbhours
	for(auto ngbr : graph[source]){
		// recursively checking bipartate graph
		if(visited[source] == 0 && dfs(graph,visited,source,ngbr,3-score)){
			return true;// 
		}
		else if(ngbr != parent && score == visited[ngbr])
			return true; // neigbours having same color
	}
	return false;
}

bool is_bipartate_graph(Graph &graph,ll V){
	// using dfs
	// 0 - not visited,1 - visited(1), 2 - visited(2)
	v_ll visited(V,0);
	ll score = 1;
	FOR(i,V,0){
		if(visited[i] == 0 && dfs(graph,visited,i,i,score)){
			return false;
		}
	}
	return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    ll T,V,E;
    cin >> T;
    while(T){
    	cin >> V >> E;
    	// V : vertices and E : edges
    	Graph graph; // undirected graph
    	FOR(i,E,0){
    		ll x,y;
    		cin >> x >> y;
    		// undirected graph
    		graph[x].PB(y);
    		graph[y].PB(x);
    	}
    	bool is_bipartate = is_bipartate_graph(graph,V);
    	deb(is_bipartate);
        T--;
    }
    return 0;
}
