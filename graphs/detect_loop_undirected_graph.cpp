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

bool has_cycle_dfs(vector<v_int> &adj,vector<bool> &visited,int s,int p);
void has_cycle_bfs(vector<v_int> &adj);
bool has_cycle_bfs_helper(vector<v_int> &adj,vector<bool> &visited,int s);
void has_cycle(vector<v_int> &adj);

int main() {
    // !Well suited for sparse graphs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    int v = 5;
    vector<v_int> adj(v);
    add_edge(adj, 0, 1);
    add_edge(adj, 1, 2);
    add_edge(adj, 1, 4);
    add_edge(adj, 2, 3);
    add_edge(adj, 3, 4);
    print_graph(adj, v);
    has_cycle(adj);
    has_cycle_bfs(adj);
    return 0;
}

void add_edge(vector<v_int> &adj, int i, int j){
    adj[i].PB(j);
    adj[j].PB(i);
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

    for(i = 0;i < adj[v].size();i++){
        if(adj[v][i] == u)
            break;
    }
    if(i != adj[v].size()){
        v_int::iterator it = adj[v].begin()+i;
        adj[v].erase(it);
    }
}

bool has_cycle_dfs(vector<v_int> &adj,vector<bool> &visited,int s,int p){
    for(auto v : adj[s]){
        if(v == p)
            continue;
        if(visited[v]){
            return true;
        }
        visited[v] = true;
        bool res = has_cycle_dfs(adj,visited,v,s);
        if(res)
            return true;
    }
    return false;
}

void has_cycle(vector<v_int> &adj){
    int V = adj.size();
    vector<bool> visited(V,false);
    FOR(i,V,0){
        if(!visited[i]){
            visited[i] = true;
            bool res = has_cycle_dfs(adj,visited,i,i);
            if(res){
                cout << "true\n";
                return;
            }
        }
    }
    cout << "false\n";
    return;
}

void has_cycle_bfs(vector<v_int> &adj){
    int V = adj.size();
    vector<bool> visited(V,false);
    FOR(i,V,0){
        if(!visited[i]){
            visited[i] = true;
            bool res = has_cycle_bfs_helper(adj,visited,i);
            if(res){
                cout << "true\n";
                return;
            }
        }
    }
    cout << "false\n";
    return;
}

bool has_cycle_bfs_helper(vector<v_int> &adj,vector<bool> &visited,int s){
    queue<int> q,pq;
    q.push(s);
    q.push(-1);
    int p = s;

    while(!q.empty()){
        int f = q.front(),count = 0;
        q.pop();

        if(f == -1){
            if(!pq.empty()){
                p = pq.front();pq.pop();
            }
            continue;
        }
        for(auto v : adj[f]){
            if(v == p){
                continue;
            }
            if(visited[v]){
                return true;
            }

            visited[v] = true;
            q.push(v);
            count++;
        }
        if(count > 0){
            q.push(-1);
            pq.push(f);
        }
    }
    return false;
}
