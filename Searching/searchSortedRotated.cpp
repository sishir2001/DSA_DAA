// search an element in a sorted(ascending) and rotated[0 .. ] -> times of rotation
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v_ll;
typedef vector<int> v_int;

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

ll searchSortedRotated(v_ll nums,ll k);

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
    v_ll nums(n); // vector
        FOR(i,n){
            cin >> nums[i];
        }
        cout << searchSortedRotated(nums,k) <<"\n";
        nums.clear();
        T--;
    }
    return 0;
}
ll searchSortedRotated(v_ll nums,ll k){
    // ! T(N) = O(logn)
    ll l = 0,r = nums.size();
    while(l <= r){
        ll m = (l+r)/2;
        if(nums[m] == k)
            return m;
        else if(nums[m] >= nums[l]){
            // left side is sorted 
            if(k >= nums[l] && k < nums[m])
                r = m-1;
            else 
                l = m+1;
        }
        else{
            // right is sorted
            if(nums[r] <= k && k > nums[m])
                l = m+1;
            else 
                r = m-1;
        }
    }
    return -1;
}