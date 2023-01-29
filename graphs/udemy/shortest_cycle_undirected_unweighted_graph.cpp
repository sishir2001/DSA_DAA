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

ll dfs(Graph &graph,v_ll &visited,v_ll &callstack,ll source,ll parent,ll count){
	visited[source] = 1;
	callstack[source] = count;

	ll mn = LLONG_MAX;

	// visiting the neigbours
	for(auto ngbr : graph[source]){
		if(ngbr == parent)
			continue;
		if(!visited[ngbr]){
			// recursively calculating the minimum cycle
			mn = min(mn,dfs(graph,visited,callstack,ngbr,source,count+1));
		}
		else if(callstack[ngbr] != 0){
			// there exists a cycle
			mn = min(mn,count-callstack[ngbr]+1);
		}
	}
	callstack[source] = 0;
	return mn;
}

void print_graph(Graph &graph){
	for(auto it : graph){
		cout << it.first << " : ";
		for(auto v : it.second){
			cout << v << " ";
		}
		NXT_LINE;
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    ll V,E;
    cin >> V >> E;
    Graph graph;

    FOR(i,E,0){
    	ll x,y;
    	cin >> x >> y;
    	// undirected graph
    	graph[x].PB(y);
    	graph[y].PB(x);
    }

    // print_graph(graph);

    // find the smallest cycle in the graph if exists
    // doing it using dfs and maintaining a call stack

    ll count = 1,mn = LLONG_MAX;
    v_ll visited(V,0),callstack(V,0);
    FOR(i,V,0){
    	if(!visited[i]){
    		mn = min(mn,dfs(graph,visited,callstack,i,i,count));
    	}
    }
    
    if(mn == LLONG_MAX)
    	mn = -1;// no cycle exists
    deb(mn);
    return 0;
}
