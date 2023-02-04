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

bool detectCycleDFS(Graph &graph,v_int &visited,int source);
void detectCycle(Graph &graph);


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while(T){
        T--;
    }
    return 0;
}

bool detectCycleDFS(Graph &graph,v_int &visited,int source){
	// using dfs to detect the backedge in the directed graphs

}
void detectCycle(Graph &graph,int V){
	// @param V : vertices in graph
	// create a vector visited , that denotes the status of the node
	// 0 - node is not visited
	// 1 - dfs is in progress
	// 2 - dfs completed
	v_int visited(V,0);

	//use the multisource dfs , for diconnected graph components
	FOR(i,V,0){
		if(!visited[i] && detectCycleDFS(graph,visited,i)){
			cout << "CYCLE EXISTS !! ";
			return;
		}
	}
	cout << "CYCLE DOES NOT EXISTS";
	return;
}
