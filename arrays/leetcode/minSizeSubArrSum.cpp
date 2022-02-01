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
#define FOR_desc(a,end) for(int (a) = (end)-1;(a) >= 0;(a)--) // regular for loop decreasing
#define FOR_custom_more_desc(a,start) for(int (a) = (start);(a) > 0;(a)--) 
#define FOR_custom_more_or_equal_desc(a,start) for(int (a) = (start);(a) >= 0;(a)--) 
#define FOR_custom_less(a,end,start) for(int (a) = (start);(a) < (end);(a)++) // regular for loop
#define FOR_custom_less_or_equal(a,end,start) for(int (a) = (start);(a) <= (end);(a)++) // regular for loop

int minSubArrLen(int target,v_int nums);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T,n,target;
    cin >> T;
    while(T){
        cin >> n >> target;
        v_int nums(n); // vector
        FOR(i,n){
            cin >> nums[i];
        }
        cout << minSubArrLen(target,nums) << "\n";
        nums.clear();
        T--;
    }
    return 0;
}

int minSubArrLen(int target,v_int nums){
    // !T(N) = O(N) - O(N^2)
    // !S(N) = O(1)

    // @param nums : int vector 
    // @param target : subArrSum >= target 
    int n = nums.size(),l = 0,prev_r = 0,curr_r = 1,minLen = INT_MAX,sum = nums[0];

    // first element of the vector
    if(nums[0] >= target){
        return 1;
    }
    while(l <= curr_r && curr_r < n){
        if(nums[curr_r] == target){
            return 1;
        }
        if(prev_r != curr_r){
            sum = sum+nums[curr_r];
        }
        if(sum == target){
            minLen = min(minLen,curr_r-l+1);
            prev_r = curr_r++;
        }
        else if(sum < target){
            prev_r = curr_r++;
        }
        else if(sum > target){
            minLen = min(minLen,curr_r-l+1);
            sum = sum-nums[l++];
            prev_r = curr_r;
        }
    }
    return (minLen == INT_MAX)?0:minLen;
}