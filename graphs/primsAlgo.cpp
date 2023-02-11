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

    	
struct Pn{
	int wgt,u,v;
};

struct ComparePN{
	bool operator()(Pn const &a,Pn const &b){
		return a.wgt > b.wgt;
	}
};

int mnWeight(Graph &vertex,Graph &weight,int V){
	// taking 0 as default source
	int res = 0;
	v_int inMST(V,0);
	priority_queue<Pn,vector<Pn>,ComparePN> pq;
	inMST[0] = 1;
	Pn node; // global node for pushing into pq;

	// add the ngbrs of 0
	FOR(i,vertex[0].size(),0){
		node.wgt = weight[0][i];
		node.u = 0;
		node.v = vertex[0][i];
		pq.push(node);
	}


	while(!pq.empty()){
		Pn t = pq.top();pq.pop();
		if(inMST[t.v])
			continue; // already in MST
		inMST[t.v] = 1; // adding the node to MST
		res += t.wgt;

		// adding t.v ngbrs to pq
		FOR(i,vertex[t.v].size(),0){
			if(inMST[vertex[t.v][i]]){
				continue; // node already in MST
			}
			node.wgt = weight[t.v][i];
			node.u = t.v;
			node.v = vertex[t.v][i];
			pq.push(node);
		}
	}
	return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    // prims algo - greedy algo to find minimum spanning tree (mst)
    // MST can be found for weighted undirected graph
    int V,E,T; // V-Vertices E-Edges
    cin >> T;
    while(T--){
	    cin >> V >> E ; // no of vertices for Graph
	    Graph vertex,weight;
	    // I - wgt,u,v
	    FOR(i,E,0){
	    	int w,u,v;
	    	cin >>  u >> v >> w;

	    	vertex[u].PB(v);
	    	weight[u].PB(w);

	    	vertex[v].PB(u);
	    	weight[v].PB(w);
	    }
	    // calculate the minimum weight to connect all the graphs
	    cout << mnWeight(vertex,weight,V) << "\n";
    }
    return 0;
}
