// find the equilibrium point in an array 
// * equilibrium point = prefix sum == suffix sum
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

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

bool isEquilibriumInVector(vi nums);
bool isEquilibriumInVector1(vi nums);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,x,n;
    bool t = true,f = false;
    deb2(t,f);
    vi nums; // vector
    cin >> T;
    while(T){
        cin >> n;
        FOR(i,n){
            cin >> x;
            nums.PB(x);
        }
        // cout << isEquilibriumInVector(nums)<<"\n";
        cout << isEquilibriumInVector1(nums)<<"\n";
        nums.clear();
        T--;
    }
    return 0;
}

bool isEquilibriumInVector(vi nums){
    // * T(n) = O(n)
    // * S(n) = O(n)
    int n = nums.size(),suffixSum = 0;
    vi prefixSum;
    // calculating the prefix sum
    prefixSum.PB(0);
    FOR_custom_less(i,n,1){
        prefixSum.PB(prefixSum[i-1]+nums[i-1]);
    }
    // calculating the suffix sum
    FOR_desc(i,n){
        if(prefixSum[i] == suffixSum)
            return true;
        suffixSum += nums[i];
    }
    return false;
}

bool isEquilibriumInVector1(vi nums){
    // *T(n) = O(n)
    // *S(n) = O(1)
    int n = nums.size(),prefixSum = 0,suffixSum = 0;
    FOR_desc(i,n)
        suffixSum += nums[i];
    
    FOR(i,n){
        suffixSum = suffixSum - nums[i];
        if(prefixSum == suffixSum)
            return true;
        prefixSum = prefixSum + nums[i];
    }
    return false;
}