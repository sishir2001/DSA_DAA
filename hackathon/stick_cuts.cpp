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
#define FOR(a,end,start) for(ll (a) = (start);(a) <(end);(a)++) // regular for loop
#define FOR_REV(a,end,start) for(ll (a) = (end)-1;(a) >= (start);(a)--) // regular for loop decreasing

void print_vector(v_ll &nums);
v_ll solve(v_ll &nums){
	sort(nums.begin(), nums.end());
	ll n = nums.size();
	v_ll res;
	for(ll i = 0;i < n;i++){
		if(nums[i] != 0){
			res.push_back(n-i);
			ll mn = nums[i];
			for(ll j = i;j < n;j++){
				nums[j] = nums[j]-mn;
			}
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
    ll T,n;
    cin >> T;
    while(T){
        cin >> n;
        v_ll nums(n); // vector
        FOR(i,n,0){
            cin >> nums[i];
        }
        v_ll res = solve(nums);
        print_vector(res);
        nums.clear();
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
