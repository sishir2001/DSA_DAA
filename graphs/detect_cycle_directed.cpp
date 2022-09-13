// detect cycle in directed graphs using kahn's algorithm
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

void add_edge(vector<v_int> &adj, int i, int j);
void remove_edge(vector<v_int> &adj, int i, int j);
void print_graph(vector<v_int> &adj, int v);

bool is_cycle(vector<v_int> &adj);

int main() {
    // !Well suited for sparse graphs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    int v = 4;
    vector<v_int> adj(v);
    add_edge(adj, 0, 1);
    add_edge(adj, 0, 2);
    add_edge(adj, 1, 2);
    add_edge(adj, 2, 3);
    
    print_graph(adj, v);
    bool res = is_cycle(adj),t = true,f = false;
    deb2(t,f);
    deb(res);
    return 0;
}

void add_edge(vector<v_int> &adj, int i, int j){
    adj[i].PB(j);
}

void print_graph(vector<v_int> &adj, int v){
    FOR(i, v, 0) {
        cout << i << " : ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        NXT_LINE;
    }
}

void remove_edge(vector<v_int> &adj, int u, int v){
    // using erase function to remove and edge
    // !T(N) = O(V)
    // !S(N) = O(1)
    int i = 0;
    for(;i < adj[u].size();i++){
        if(adj[u][i] == v)
            break;
    }
    if(i != adj[u].size()){
        v_int::iterator it = adj[u].begin()+i;
        adj[u].erase(it);
    }
    return;
}

bool is_cycle(vector<v_int> &adj){
	// kahn's algorithm 
	int count = 0,V = adj.size();

	// counting the indegree of each node
	v_int indegree(V,0);
	FOR(u,V,0){
		for(auto v : adj[u])
			indegree[v]++;
	}

	// pushing 0 indegree nodes to queue
	queue<int> q;
	FOR(u,V,0){
		if(indegree[u] == 0)
			q.push(u);
	}

	// modified bfs to count all jobs that are ready to executed
	while(!q.empty()){
		int f = q.front();q.pop();
		count++;
		for(auto v : adj[f]){
			indegree[v]--;
			if(indegree[v] == 0)
				q.push(v);
		}
	}
	return count != V;
}
