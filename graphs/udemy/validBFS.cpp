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
typedef vector<set<ll>> vs_ll;
void print_vector(v_ll &nums);

void validBFS(vs_ll &graph,v_ll &sequence,ll N){
	ll i = 0;
	queue<ll> q;
	
	if(sequence[i] == 1){
		q.push(sequence[i]);
		i++;
	}
	else{
		cout << "No\n";
		return;
	}

	while(i < N && !q.empty()){
		ll f = q.front();q.pop();
		while(i < N && graph[f].find(sequence[i]) != graph[f].end()){
			q.push(sequence[i]);
			i++;
		}
	}

	if(i < N)
		cout << "No\n";
	else
		cout << "Yes\n";
	return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    ll N,x,y;
    cin >> N;
    vs_ll graph(N+1);
    v_ll sequence(N);

    FOR(i,N-1,0){
    	cin >> x >> y;
    	graph[x].insert(y);
    	graph[y].insert(x);
    }

    // for(auto it : graph){
    // 	for(auto itr : it){
    // 		cout << itr << " ";
    // 	}
    // 	NXT_LINE;
    // }

    FOR(i,N,0)
    	cin >> sequence[i];

    // print_vector(sequence);

    validBFS(graph,sequence,N);
    return 0;
}

void print_vector(v_ll &nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    NXT_LINE;
}
