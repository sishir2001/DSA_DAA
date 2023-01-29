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

pair<string,ll> min_edges(list<ll> *g,int V){
	// !TLE
	// @param V : vertices
	// !T(N) = O(V+E)
	vector<string> path(V+1,to_string(V));
	v_ll distance(V+1,1e9);
	v_int visited(V+1,0);
	queue<ll> q;

	q.push(V);
	visited[V] = 1;
	distance[V] = 1;
	while(!q.empty()){
		ll f = q.front();q.pop();

		if(f == 1)
			break;

		// bool isBreak = false;
		for(auto v : g[f]){

			if(!visited[v]){
				visited[v] = 1;
				path[v] = to_string(v)+ " " + path[f];
				q.push(v);
			}
			if(distance[v] > distance[f]+1)
				distance[v] = distance[f]+1;

			// if(v == 1){
			// 	isBreak = true;
			// 	break;
			// }

		}

		// if(isBreak)
		// 	break;
	}

	return make_pair(path[1],distance[1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif

    ll V,E,x,y;
    cin >> V >> E;

    list<ll> *g = new list<ll>[V+1];
    // undirected graph
    
    FOR(i,E,0){
    	cin >> x >> y;
    	g[x].PB(y);
    	g[y].PB(x);
    }

    pair<string,ll> res = min_edges(g,V);
    if(res.second == (int)1e9){
    	cout << "IMPOSSIBLE\n";
    }
    else{
    	cout << res.second<< "\n";
    	cout << res.first << "\n";
    }
    return 0;
}
