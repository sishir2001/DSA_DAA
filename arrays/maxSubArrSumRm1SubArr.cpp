//! maximum subarray sum possible after removing atmost one subarr
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

ll maxSubArrSum(ll *nums,ll n);
ll kadaneMaxSubArr(ll *nums,ll l,ll r);
ll kadaneMinSubArr(ll *nums,ll l,ll r);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll T,n;
    cin >> T;
    while(T){
        cin >> n;
        ll *a = new ll[n];
        FOR(i,n){
            cin >> a[i];
        }
        // cout <<"maxSubArrSum : "<<"\n";
        // cout << maxSubArrSum(a,n) <<"\n";
        cout << maxSubArrSum(a,n) <<"\n";
        delete []a;
        T--;
    }
    return 0;
}


ll maxSubArrSum(ll *nums,ll n){
    // !T(N) = O(n)
    // !S(N) = O(1)
    // finding the left most positive elements and right most positive elements indexes
    ll l = -1,r = -1,sum = 0,minSubSum;
    // left most positive element 
    FOR(i,n){
        if(nums[i] >= 0){
            l = i;
            break;
        }
    }
    // right most positive element
    FOR_REV(i,n){
        if(nums[i] >= 0){
            r = i;
            break;
        }
    }
    deb2(l,r);
    if(l == -1 && r == -1){
        // all are -ve numbers
        return kadaneMaxSubArr(nums,0,n-1);
    }
    ll maxSumSubArr = kadaneMaxSubArr(nums,l,r);
    // finding sum
    FOR_less_or_equal(i,r,l){
        sum += nums[i];
    }
    deb(sum);
    minSubSum = kadaneMinSubArr(nums,l,r);
    ll remMaxSumSubArr = (minSubSum < 0)?sum-minSubSum:sum;
    return max(remMaxSumSubArr,maxSumSubArr);
}

ll kadaneMaxSubArr(ll *nums,ll l,ll r){
    // !T(N) = O(N)
    // !S(N) = O(1)
    // finding the maxSubArrSum
    ll sum = nums[l],maxSum = nums[l];
    FOR_less_or_equal(i,r,l){
        sum = max(sum+nums[i],nums[i]);
        maxSum = max(maxSum,sum);
    }
    deb(maxSum);
    return maxSum;
}
ll kadaneMinSubArr(ll *nums,ll l,ll r){
    // !T(N) = O(N)
    // !S(N) = O(1)
    // finding the minSubArrSum
    ll sum = nums[l],minSum = nums[l];
    FOR_less_or_equal(i,r,l){
        sum = min(sum+nums[i],nums[i]);
        minSum = min(minSum,sum);
    }
    deb(minSum);
    return minSum;
}