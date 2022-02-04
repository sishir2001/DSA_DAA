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

ll maxSumSubarr(ll *nums,ll n);
ll minInRange(ll *nums,ll l,ll r);
ll kadaneMaxSumSubArr(ll *nums,ll l,ll r);

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
        cout << maxSumSubarr(a,n) <<"\n";
        delete []a;
        T--;
    }
    return 0;
}



// ! Wrong answer 

ll maxSumSubarr(ll *nums,ll n){
    // find the right most index of +ve integer
    ll r = -1,l = 0,sum = nums[0],maxSum = nums[0];
    FOR_REV(i,n){
        if(nums[i] >= 0){
            r = i;
            break;
        }
    }
    if(r == -1){
        // no positive elements
        return kadaneMaxSumSubArr(nums,0,n-1);
    }
    // find the left bound of the range for the maxSumSubarr
    FOR_less_or_equal(i,r,1){
        if(sum+nums[i] >= nums[i])
            sum += nums[i];
        else{
            l = i;
            sum = nums[i];
        }
        maxSum = max(maxSum,sum);
    }
    deb2(l,r);
    // finding the min -ve element in the range
    ll minEle = minInRange(nums,l,r);
    deb(minEle);
    return (minEle < 0)?max(maxSum,sum-minEle):maxSum;
}
ll kadaneMaxSumSubArr(ll *nums,ll l,ll r){
    // !T(n) = O(n)
    // !S(n) = O(1)
    // normal kadane's algorithm
    ll sum = nums[l],maxSum = nums[l];
    FOR_less_or_equal(i,r,l){
        sum = max(sum+nums[i],nums[i]);
        maxSum = max(maxSum,sum);
    }
    return maxSum;
}
ll minInRange(ll *nums,ll l,ll r){
    // !T(n) = O(n)
    // !S(n) = O(1)
    ll minEle = nums[l];
    FOR_less_or_equal(i,r,l+1){
        minEle = min(minEle,nums[i]);
    }
    return minEle;
}