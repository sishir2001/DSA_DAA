// find the max sum of K consecutive elements 
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

int maxSumKConsecEle(vi nums,int k);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,x,n,k;
    vi nums; // vector
    cin >> T;
    while(T){
        cout << "n and k : ";
        cin >> n >> k;
        FOR(i,n){
            cin >> x;
            nums.PB(x);
        }
        cout << maxSumKConsecEle(nums,k) << "\n";
        nums.clear();
        T--;
    }
    return 0;
}


int maxSumKConsecEle(vi nums,int k){
    // *T(n) = O(n)
    // *S(n) = O(1)

    int max_sum = 0,sum = 0,size = nums.size();
    // calculating the sum for first k elements
    FOR(i,k){
        sum += nums[i];
    }
    max_sum = sum;
    // now using window sliding technique to calculate the rest with window size being 3
    FOR_custom_less(i,size,k){
        // starting with k
        sum = sum + nums[i] - nums[i-k];
        max_sum = max(max_sum,sum);
    }
    return max_sum;
}