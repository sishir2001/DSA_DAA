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

#define PB push_back // for vector
#define PPB pop_back // for vector
#define mod 1000000007 // 1e9+7
#define deb(x) cout << #x << " = "<<x<<"\n" // for debugging
#define deb2(x,y) cout << #x << " = "<<x << " , " << #y << " = " << y <<"\n" // for debugging 
#define FOR(a,end) for(int (a) = 0;(a) < (end);(a)++) // regular for loop
#define FOR_REV(a,start) for(int (a) = (start)-1;(a) >= 0;(a)--) // regular for loop decreasing
#define FOR_less(a,end,start) for(int (a) = (start);(a) < (end);(a)++) // regular for loop
#define FOR_REV_great(a,end,start) for(int (a) = (start);(a) > (end);(a)--) // regular for loop
#define FOR_less_or_equal(a,end,start) for(int (a) = (start);(a) <= (end);(a)++) // regular for loop
#define FOR_REV_great_or_equal(a,end,start) for(int (a) = (start);(a) >= (end);(a)--) // regular for loop

ll countFrequencies(v_ll nums,ll k);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll T,n,k;
    cin >> T;
    while(T){
        cin >> n>>k;
        v_ll nums(n); // vector

        FOR(i,n){
            cin >> nums[i];
        }

        cout << countFrequencies(nums,k)<<"\n";
        nums.clear();
        T--;
    }
    return 0;
}

ll countFrequencies(v_ll nums,ll k){
    // use hashing to count the frequencies 
    ll n = nums.size(),count = 0;
    ll threshhold = n/k;
    unordered_map<int,int> mp;
    // traversing through the array
    FOR(i,n){
        mp[nums[i]]++;
    }
    // traversing through the map
    for(auto x : mp){
        // if(x.second >= threshhold)
        //     count ++;
        cout << x.first << " "<<x.second <<"\n";
    }
    return count;
}