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

v_int shortestPathDAG(Graph &graph,Graph &wgt,int src,int V);
void print_vector(v_int &nums);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    Graph graph,wgt;
    int V,E,src;
    cin >> V >> E >> src;
    // graph input
    for(int i = 0;i < V;i++){
    	int u,v,w;
    	cin >> u >> v >> w;
    	graph[u].PB(v);
    	wgt[u].PB(w);
    }

    v_int res = shortestPathDAG(graph,wgt,src,V);
    print_vector(res);
    return 0;
}

void print_vector(v_int &nums) {
    for (auto i : nums){
    	if(i == INT32_MAX){
    		cout << "INF" << " ";
    	}
    	else{
    		cout << i << " ";
    	}
    }
    NXT_LINE;
}

v_int shortestPathDAG(Graph &graph,Graph &wgt,int src,int V){
	// use topological sorting to find the shortest distance of every node from the src node
	// T(N) = O(V+E)
	// S(N) = O(V) for use of indegree and queue
	v_int indegree(V,0),dist(V,INT32_MAX);
	dist[src] = 0;
	queue<int> q;

	// calculate indegree for every node
	for(auto u : graph){
		for(auto v : u.second){
			indegree[v]++;
		}
	}

	// push 0 indegree nodes into queue
	FOR(i,V,0){
		if(!indegree[i])
			q.push(i);
	}

	while(!q.empty()){
		int f = q.front();q.pop();
		// traverse ngbrs of f
		FOR(j,graph[f].size(),0){
			int v = graph[f][j],weight = wgt[f][j];
			indegree[v]--;
			if(!indegree[v])
				q.push(v);
			if(dist[f] != INT32_MAX && dist[v] > dist[f] + weight)
				dist[v] = dist[f]+weight;
		}
	}
	return dist;
}
