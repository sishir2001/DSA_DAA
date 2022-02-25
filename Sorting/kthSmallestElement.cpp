// find the kth smallest element
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

ll kthSmallest(ll *nums,ll n,ll k);
ll lumutoPartition(ll *nums,ll l, ll r);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll T,n,k;
    cin >> T;
    while(T){
        cin >> n >> k;
        ll *a = new ll[n];
        FOR(i,n){
            cin >> a[i];
        }
        cout << kthSmallest(a,n,k)<<"\n";
        delete []a;
        T--;
    }
    return 0;
}

ll kthSmallest(ll *nums,ll n,ll k){
    // we need to find element in k-1 index when the array is sorted.
    // We use lumoto partition and take decision on the p returned by the partition
    ll l = 0,r = n-1;
    while(l <= r){
        ll p = lumutoPartition(nums,l,r);
        if(p == k-1){
            return nums[p];
        }
        else if(p < k-1){
            l = p+1;
        }
        else
            r = p-1;
    }
    return -1;// ! shouldnt be executed
}

ll lumutoPartition(ll *nums,ll l, ll r){
    ll pivot = nums[r],i = l-1;
    FOR_less(j,r,l){
        if(nums[j] < pivot){
            i++;
            swap(nums[j],nums[i]);
        }
    }
    i++;
    swap(nums[i],nums[r]);
    return i;
}