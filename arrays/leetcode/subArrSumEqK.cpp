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

int subArrSum(v_int nums,int k);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T,n,k;
    cin >> T;
    while(T){
        cin >> n >> k;
        v_int nums(n); // vector
        FOR(i,n){
            cin >> nums[i];
        }
        cout << subArrSum(nums,k)<<"\n";
        nums.clear();
        T--;
    }
    return 0;
}

int subArrSum(v_int nums,int k){
    // ! TIME LIMIT EXTENDED
    // @param nums: vector
    // @param k: target value

    int n = nums.size(),count = 0,sum = 0;
    v_int suffixSum(n);
    FOR(i,n){
        sum = sum+nums[i];
        if(sum == k)
            count ++;
    }
    suffixSum[0] = sum;
    FOR_less(i,n,1){
        suffixSum[i] = suffixSum[i-1] - nums[i-1];
    }

    FOR_less(i,n,1){
        int sum = suffixSum[i];
        FOR_REV_great_or_equal(j,i,n-1){
            if(sum == k)
                count++;
            sum = suffixSum[i]-suffixSum[j];
        }
    }
    return count;
}
