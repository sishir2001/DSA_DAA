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
typedef map<int,v_int> Graph;

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


void findOrderDFS(Graph &graph,v_int &visited,v_int &order,int src);
v_int findOrder(Graph &graph,int V);
Graph getTranspose(Graph &graph);
void printStronglyConnectedDFS(Graph &transposed,v_int &visited,int src);
void printStronglyConnectedComponents(Graph &transposed,v_int &order,int V);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    Graph graph;
    int V,E;
    cin >> V >> E;

    FOR(i,E,0){
    	int u,v;
    	cin >> u >> v;
    	graph[u].PB(v);
    }

    // find the order of traversal
    v_int order = findOrder(graph,V);

    // get tranpose of a graph
    Graph transposed = getTranspose(graph);

    // perform DFS according to the order obtained
    printStronglyConnectedComponents(transposed,order,V);
    return 0;
}

void findOrderDFS(Graph &graph,v_int &visited,v_int &order,int src){
	visited[src] = 1;
	// visit the ngbrs
	for(auto ngbr : graph[src]){
		if(!visited[ngbr]){
			findOrderDFS(graph,visited,order,ngbr);
		}
	}
	order.PB(src);
}

v_int findOrder(Graph &graph,int V){
	v_int visited(V,0),order;
	// multisource dfs
	FOR(i,V,0){
		if(!visited[i]){
			findOrderDFS(graph,visited,order,i);
		}
	}
	return order;
}

Graph getTranspose(Graph &graph){
	// get the transpose of a graph
	Graph transposed;
	for(auto u : graph){
		for(auto v : u.second){
			transposed[v].PB(u.first);
		}
	}
	return transposed;
}

void printStronglyConnectedDFS(Graph &transposed,v_int &visited,int src){
	// print the order
	visited[src] = 1;
	cout << src << " ";
	// visit the ngbrs
	for(auto ngbr : transposed[src]){
		if(!visited[ngbr]){
			printStronglyConnectedDFS(transposed,visited,ngbr);
		}
	}
}
void printStronglyConnectedComponents(Graph &transposed,v_int &order,int V){
	// multisource dfs but with the order
	v_int visited(V,0);
	int size = order.size();
	for(int i = size-1;i >= 0;i--){
		if(!visited[order[i]]){
			printStronglyConnectedDFS(transposed,visited,order[i]);
			NXT_LINE;
		}
	}
	return;
}
