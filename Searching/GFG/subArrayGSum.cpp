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

v_ll subarraySum(v_ll nums,ll s);
void printVector(v_ll nums);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll T,n,s;
    cin >> T;
    while(T){
        cin >> n >> s;
        v_ll nums(n); // vector
        FOR(i,n){
            cin >> nums[i];
        }
        printVector(subarraySum(nums,s));
        nums.clear();
        T--;
    }
    return 0;
}

v_ll subarraySum(v_ll nums,ll s){
    // ! nums contain all non-negative integers
    // ! not sorted array
    // T(N) = O(n);
    // S(N) = O(1);

    v_ll res;
    ll n = nums.size(),sum = nums[0],l = 0,r = 1;
    while(r < n && l < n){
        if(l > r){
            r = l;
            sum = 0;
        }
        if(sum + nums[r] <= s){
            sum += nums[r];
            if(sum == s){
                res.PB(l+1);
                res.PB(r+1);
                return res;
            }
            r++;
        }
        else
            sum = sum - nums[l++];
    }

    res.PB(-1);
    return res;
}

void printVector(v_ll nums){
    ll n = nums.size();
    FOR(i,n){
        cout <<nums[i]<<" ";
    }
    cout << "\n";
}