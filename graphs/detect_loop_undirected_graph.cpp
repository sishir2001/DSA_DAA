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

void add_edge(v_int adj[], int i, int j);
void print_graph(v_int adj[], int v);

bool dfs_rec(v_int adj[], vector<bool> &visited, vector<bool> &rec_stack,
             int s);
bool is_loop(v_int adj[], int v);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int v = 6;
    v_int adj[v];
    add_edge(adj, 0, 1);
    add_edge(adj, 2, 1);
    add_edge(adj, 2, 3);
    add_edge(adj, 5, 3);
    add_edge(adj, 3, 4);
    add_edge(adj, 4, 5);
    print_graph(adj, v);

    bool loop = is_loop(adj, v);
    deb(loop);
    return 0;
}

void add_edge(v_int adj[], int i, int j) {
    // directed graph
    adj[i].PB(j);
}
void print_graph(v_int adj[], int v) {
    FOR(i, v, 0) {
        cout << i << " : ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        NXT_LINE;
    }
}

bool dfs_rec(v_int adj[], vector<bool> &visited, vector<bool> &rec_stack,
             int s) {
    // !T(N) = O(V+E)
    visited[s] = true;
    rec_stack[s] = true;
    for (auto i : adj[s]) {
        if (!visited[i] && dfs_rec(adj, visited, rec_stack, i))
            return true;
        else if (rec_stack[i])
            return true;
    }
    rec_stack[s] = false;
    return false;
}
bool is_loop(v_int adj[], int v) {
    vector<bool> visited(v, false), rec_stack(v, false);
    FOR(i, v, 0) {
        if (!visited[i] && dfs_rec(adj, visited, rec_stack, i))
            return true;
    }
    return false;
}