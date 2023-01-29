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


void topologicalSortDfs(Graph &graph,v_int &visited,v_int &indegree,int src){
	// T(N) = O(V+E)
	// S(N) = O(V+E)
	visited[src] = 1;
	cout << src << " ";
	// visiting the ngbrs
	for(auto ngbr : graph[src]){
		// no need to check for visited as there are no cycles present in the graph
		indegree[ngbr]--;
		if(indegree[ngbr] == 0){
			topologicalSortDfs(graph,visited,indegree,ngbr);
		}
	}
	return;
}

void print_vector(v_int &nums);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    int V,E,x,y;
    Graph graph;
    cin >> V >> E;
    v_int indegree(V,0),visited(V,0);
    FOR(i,E,0){
    	cin >> x >> y;
    	graph[x].PB(y); // directed graph
    }
    // calculate indegree for all the vertices
    for(auto u : graph){
    	for(auto v : u.second ){
    		indegree[v]++;
    	}
    }

    // print_vector(indegree);

    FOR(i,V,0){
    	if(!visited[i] && !indegree[i]){
    		topologicalSortDfs(graph,visited,indegree,i);
    	}
    }

    return 0;
}

void print_vector(v_int &nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    NXT_LINE;
}
