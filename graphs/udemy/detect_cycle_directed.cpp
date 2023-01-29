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

typedef map<ll, v_ll> Graph;

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

void print_vector(v_ll &nums);

bool dfs(Graph &graph, v_ll &traversed, v_ll &visited, ll i) {
    visited[i] = traversed[i] = 1;

    // deb(i);
    // print_vector(visited);
    // print_vector(traversed);

    // traversing the neighbours
    for (auto ngbr : graph[i]) {
        // if(traversed[ngbr] || (!visited[ngbr] &&
        // dfs(graph,traversed,visited,ngbr))) 	return true;
        if (!visited[ngbr] && dfs(graph, traversed, visited, ngbr))
            return true;  // cycle exists
        else if (traversed[ngbr])
            return true;  // cycle exists
    }

    traversed[i] = 0;  // bactracking step
    return false;
}

bool detect_cycle(Graph &graph, ll V) {
    v_ll visited(V + 1, 0);
    v_ll traversed(V + 1, 0);
    // using dfs for detecting cycle in directed graph
    FOR(i, V + 1, 0) {
        if (!visited[i] && dfs(graph, traversed, visited, i))
            return true;
    }
    return false;
}

void print_graph(Graph &graph) {
    Graph::iterator it;
    for (it = graph.begin(); it != graph.end(); it++) {
        cout << it->first << " : ";
        for (auto v : it->second) {
            cout << v << " ";
        }
        NXT_LINE;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll T, V, E;
    cin >> T;
    while (T) {
        cin >> V >> E;  // V:nodes and E:edges
        Graph graph;
        FOR(i, E, 0) {
            ll x, y;
            cin >> x >> y;
            // building a directed graph
            graph[x].PB(y);
        }
        // print_graph(graph);
        // NXT_LINE;
        bool res = detect_cycle(graph, V);
        deb(res);
        NXT_LINE;
        T--;
    }
    return 0;
}

void print_vector(v_ll &nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    NXT_LINE;
}
