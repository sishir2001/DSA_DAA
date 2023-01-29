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

typedef map<ll,v_ll> Graph;

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

bool bfs(Graph &graph,v_ll &visited,ll i){
	visited[i] = 1;
	queue<p_ll> q;
	p_ll p;
	p.first = i;//self
	p.second = i; // parent
	q.push(p);

	while(!q.empty()){
		p_ll f = q.front();q.pop();
		for(auto v : graph[f.first]){
			if(!visited[v]){
				visited[v] = 1;
				p.first = v;
				p.second = f.first;
				q.push(p);
			}
			else if(f.second != v){
				return true; // cycle exists
			}
		}
	}
	return false;
}

bool detect_cycle(Graph &graph,ll V){
	v_ll visited(V,0);
	FOR(i,V,0){
		if(!visited[i] && bfs(graph,visited,i)){
			return true;
		}
	}
	return false;
}

void print_graph(Graph &graph){
	Graph::iterator it;
	for(it = graph.begin();it != graph.end();it++){
		cout << it->first << " : ";
		for(auto v : it->second){
			cout << v << " ";
		}
		NXT_LINE;
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    ll T,V,E;
    cin >> T;
    while(T){
    	cin >> V >> E; // no of bidirectional edges in the graph
    	Graph graph;
    	FOR(i,E,0){
    		ll x,y;
    		cin >> x >> y;
    		graph[x].PB(y);
    		graph[y].PB(x);
    	}
    	print_graph(graph);
    	bool res = detect_cycle(graph,V);
    	deb(res);
        T--;
    }
    return 0;
}
