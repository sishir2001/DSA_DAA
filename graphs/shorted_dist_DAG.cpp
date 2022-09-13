// Find shortest distance from a source in DAG
#include <bits/stdc++.h>
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
typedef pair<l, l> p_l;
typedef pair<ul, ul> p_ul;
typedef pair<ll, ll> p_ll;
typedef pair<ull, ull> p_ull;
typedef pair<int, int> p_int;
typedef pair<uint, uint> p_uint;

#define NXT_LINE cout << "\n"
#define EOL      '\n'
#define F        first
#define S        second
#define PB       push_back                         // for vector
#define PPB      pop_back                          // for vector
#define mod      1000000007                        // 1e9+7
#define deb(x)   cout << #x << " = " << x << "\n"  // for debugging
#define deb2(x, y)                                        \
    cout << #x << " = " << x << " , " << #y << " = " << y \
         << "\n"  // for debugging
#define FOR(a, end, start) \
    for (int(a) = (start); (a) < (end); (a)++)  // regular for loop
#define FOR_REV(a, end, start)             \
    for (int(a) = (end)-1; (a) >= (start); \
         (a)--)  // regular for loop decreasing

void add_edge(vector<vector<p_int>> &adj, int i, int j,int w);
void remove_edge(vector<vector<p_int>> &adj, int i, int j);
void print_graph(vector<vector<p_int>> &adj, int v);


int dfs(vector<vector<p_int>> &adj,int s,int d);
void shortest_dist_DAG(vector<vector<p_int>> &adj,int s);
void shortest_dist_DAG_effe(vector<vector<p_int>> &adj,int s);


int main() {
    // !Well suited for sparse graphs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    int v = 4,s = 1;
    vector<vector<p_int>> adj(v);
    add_edge(adj, 0, 1,1);
    add_edge(adj, 1, 2,3);
    add_edge(adj, 1, 3,2);
    add_edge(adj, 2, 3,4);

    print_graph(adj, v);
    shortest_dist_DAG(adj,s);
    NXT_LINE;
    shortest_dist_DAG_effe(adj,s);
    return 0;
}

void add_edge(vector<vector<p_int>> &adj, int i, int j,int w){
	p_int p(j,w);
    adj[i].PB(p);
}

void print_graph(vector<vector<p_int>> &adj, int v){
    FOR(i, v, 0) {
        cout << i << " : ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << "(" <<adj[i][j].first << "," << adj[i][j].second << ")" << " ";
        }
        NXT_LINE;
    }
}

void remove_edge(vector<vector<p_int>> &adj, int u, int v){
    // using erase function to remove and edge
    // !T(N) = O(V)
    // !S(N) = O(1)
    int i = 0;
    for(;i < adj[u].size();i++){
        if(adj[u][i].first == v)
            break;
    }
    if(i != adj[u].size()){
        vector<p_int>::iterator it = adj[u].begin()+i;
        adj[u].erase(it);
    }
    return;
}

int dfs(vector<vector<p_int>> &adj,int s,int d){
	// No cycles involved
	int mn = INT32_MAX;
	for(auto v : adj[s]){
		if(v.first == d){
			mn = min(mn,v.second);
			continue;
		}
		int res = dfs(adj,v.first,d);
		if(res != -1)
			mn = min(mn,res+v.second);
	}
	return mn == INT32_MAX?-1:mn;
}

void shortest_dist_DAG(vector<vector<p_int>> &adj,int s){
	// Acyclic
	int V = adj.size();
	FOR(u,V,0){
		if(u == s){
			cout << 0 << " ";
		}
		else{
			cout << dfs(adj,s,u) << " ";
		}
	}
	NXT_LINE;
}

void shortest_dist_DAG_effe(vector<vector<p_int>> &adj,int s){
    // using topological sorting 
    // T(N) = O(V+E)
    // S(N) = O(V)
    int V = adj.size();
    v_int dist(V,INT32_MAX),indegree(V,0);
    dist[s] = 0;
    queue<int> q;

    // calculating indegree of each vertex
    FOR(u,V,0){
        for(auto v : adj[u]){
            indegree[v.first]++;
        }
    }

    // enqueuing 0 indegree vertices
    FOR(u,V,0){
        if(indegree[u] == 0)
            q.push(u);
    }

    // finding topological sort
    while(!q.empty()){
        int f = q.front();q.pop();
        for(auto v : adj[f]){
            indegree[v.first]--;
            if(indegree[v.first] == 0)
                q.push(v.first);
            if(dist[f] == INT32_MAX)
                continue;
            if(dist[v.first] > dist[f]+v.second)
                dist[v.first] = dist[f]+v.second;
        }
    }

    // printing the shortest distances in the DAG
    FOR(u,V,0){
        cout << (dist[u] == INT32_MAX?-1:dist[u]) << " ";
    }
    NXT_LINE;
}
