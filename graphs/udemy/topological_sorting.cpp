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

void topological_sorting_bfs(Graph &graph,ll V);
void topological_sorting_dfs(Graph &graph,ll i,v_ll &incount,v_ll &visited);
void dfs(Graph,ll V);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
      Graph graph;

      // read graph
      ll V,E;
      cin >> V >> E; // vertices and edges
      FOR(i,E,0){
      	ll x,y;
      	cin >> x >> y;

      	// directed graph
      	graph[x-1].push_back(y-1);
      }

      // topological_sorting_bfs(graph,V);
      dfs(graph,V);

    return 0;
}

void topological_sorting_bfs(Graph &graph,ll V){
	// Using BFS
	// @param graph : DAG

	v_ll incount(V,0);
	// calculate incoming count for each vertex
	FOR(i,V,0){
		// visit ngbrs
		for(auto ngbr : graph[i]){
			incount[ngbr]++;
		}
	}

	queue<ll> q;
	// insert vertices with 0 incount
	FOR(i,V,0){
		if(!incount[i]){
			q.push(i);
		}
	}

	while(!q.empty()){
		ll f = q.front();q.pop();

		// visit ngbrs and decrease incount
		for(auto ngbr : graph[f]){
			incount[ngbr]--;
			if(!incount[ngbr]){
				q.push(ngbr);
			}
		}
		cout << f+1 << " ";
	}
	return;
}

void topological_sorting_dfs(Graph &graph,ll i,v_ll &incount,v_ll &visited){
	cout << i+1 << " ";
	visited[i] = 1;
 	for(auto ngbr : graph[i]){
		incount[ngbr]--;
		if(!incount[ngbr]){
			topological_sorting_dfs(graph,ngbr,incount,visited);
		}
	}
	return;
}

void dfs(Graph graph,ll V){
	// using dfs for topological sorting 

	// calculate incount
	v_ll incount(V,0),visited(V,0);
	FOR(i,V,0){
		for(auto ngbr : graph[i]){
			incount[ngbr]++;
		}
	}

	// call for dfs on node with incount = 0
	FOR(i,V,0){
		if(!visited[i] && !incount[i]){
			topological_sorting_dfs(graph,i,incount,visited);
		}
	}
}
