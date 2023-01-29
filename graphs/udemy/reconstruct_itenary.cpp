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
typedef vector<string> v_str;

typedef pair<l,l> p_l;
typedef pair<ul,ul> p_ul;
typedef pair<ll,ll> p_ll;
typedef pair<ull,ull> p_ull;
typedef pair<int,int> p_int;
typedef pair<uint,uint> p_uint;

typedef pair<string,bool> p_sb;
typedef map<string,vector<p_sb>> Graph;

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

void print_graph(Graph &graph){
	for(auto it : graph){
		cout << it.first << " : ";
		for(auto v : it.second){
			// v is a pair
			cout << "( " << v.first << " , " << v.second << " )";
		}
		NXT_LINE;
	}
}

void print_vector(v_str &nums);
v_str lexOrder(v_str &a,v_str &b){
	// compare the vectors lexographically
	ll n = (ll)a.size();
	FOR(i,n,0){
		if(a[i] == b[i])
			continue;
		if(a[i] < b[i])
			return a;
		break;
	}
	return b;
}

v_str dfs(Graph &graph,string source,ll i, ll N){
	v_str res,mn_res;
	res.PB(source);
	ll mn = LLONG_MAX;

	// if not valid iternary send an empty vector
	// if(graph.find(source) == graph.end()){
	// 	return mn_res;// empty vector
	// }
	ll size = (ll)graph[source].size();
	for(ll j = 0;j < size;j++){
		p_sb v = graph[source][j];
		if(!v.second){
			graph[source][j].second = true;
			v_str sub_res = dfs(graph,v.first,i+1,N);
			if(sub_res.size() == 0){
				graph[source][j].second = false;
				continue;
			}
			// check with the current mn_res
			if(mn > sub_res.size()){
				mn = sub_res.size();
				mn_res = sub_res;
			}
			else if(mn == sub_res.size()){
				mn_res = lexOrder(mn_res,sub_res);
			}
		}
	}
	// add mn_res to res
	if(mn_res.size() == 0 && i < N){
		// not a perfect iternary 
		return mn_res;// empty vector
	}
	for(auto s : mn_res){
		res.PB(s);
	}
	// print_vector(res);
	return res;
}

void print_vector(v_str &nums);

int main(){
	// !WRONG ANSWER
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    // contruct a graph
    p_sb p;

    ll T,N;
    string from,to;
    cin >> T;

    while(T){
    	Graph graph;
    	cin >> N;
    	FOR(i,N,0){
    		cin >> from >> to;
    		p.first = to;
    		p.second = false;
    		graph[from].PB(p);
    	}
    	// print_graph(graph);
    	v_str res = dfs(graph,"DEL",0,N);
    	print_vector(res);
        T--;
    }
    return 0;
}

void print_vector(v_str &nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    NXT_LINE;
}
