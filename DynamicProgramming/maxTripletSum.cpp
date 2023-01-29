// triplet with condition i < j < k and arr[i] < arr[j] < arr[k]

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

ll maxTripletProduct(v_ll &nums);
void print_vector(v_ll &nums);
void print_matrix(vector<v_ll> &matrix);

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
        // similar to longest increasing subsequence
        v_ll nums(n); // vector
        FOR(i,n,0){
            cin >> nums[i];
        }
        ll res = maxTripletProduct(nums);
        deb(res);
        nums.clear();
        T--;
    }
    return 0;
}

ll maxTripletProduct(v_ll &nums){
	// @params nums : vector of ll
	ll n = nums.size();
	v_ll dp_mx(n,LLONG_MIN),dp_mn(n,LLONG_MAX);
	ll mx = LLONG_MIN;

	for(ll i  = 1;i < n;i++){
		for(ll j = i-1;j >= 0;j--){
			if(nums[i] > nums[j]){
				ll prod = nums[i]*nums[j];
				dp_mn[i] = min(dp_mn[i],prod);
				dp_mx[i] = max(dp_mx[i],prod);
				if(dp_mn[j] != LLONG_MAX)
					mx = max(mx,nums[i]*dp_mn[j]);
				if(dp_mx[j] != LLONG_MIN)
					mx = max(mx,nums[i]*dp_mx[j]);
			}
		}
	}
	return mx == LLONG_MIN?-1:mx;
}

void print_vector(v_ll &nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    NXT_LINE;
}

void print_matrix(vector<v_ll> &matrix){
    ll n = matrix.size(),m = matrix[0].size();
    FOR(i,n,0){
        FOR(j,m,0){
            cout << matrix[i][j] << " ";
        }
        NXT_LINE;
    }
}
