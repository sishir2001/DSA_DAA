// given an unsorted array , find the peak elements
// Peak element - not smaller than its neigbours 
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

ll peakElement(vll nums);
ll peakElement1(vll nums);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T,n;
    cin >> T;
    while(T){
        cin >> n;
        vll nums(n); // vector
        FOR(i,n){
            cin >> nums[i];
        }
        cout << peakElement(nums)<<"\n";
        cout << peakElement1(nums)<<"\n";
        cout <<"\n";
        nums.clear();
        T--;
    }
    return 0;
}

ll peakElement1(vll nums){
    // ! Efficient Solution
    // *T(n) = O(logN)
    // *S(n) = O(1)
    // ? similar to binary search

    ll l = 0,r = nums.size()-1;
    while(l <= r){
        ll m = (l+r)/2;
        if((m == 0 || nums[m] >= nums[m-1]) && (m == nums.size()-1 || nums[m] >= nums[m+1]))
            return nums[m];
        else if(m > 0 && nums[m] <= nums[m-1]) 
            r = m-1;
        else if(m > 0 && nums[m] <= nums[m+1]) 
            l = m+1;
    }
    return -1;//! this will not be executed
}
ll peakElement(vll nums){
    // ! Naive Solution
    // *T(n) = O(n)
    // *S(n) = O(1)

    ll n = nums.size();
    if(n == 1 || nums[0] >= nums[1])
        return nums[0];
    if(nums[n-1] >= nums[n-2])
        return nums[n-1];
    ll prevDiff = nums[1]-nums[0],currDiff = 0;
    FOR_custom_less(i,n-1,1){
        currDiff = nums[i+1]-nums[i];
        if(prevDiff >= 0 && currDiff <= 0)
            return nums[i];
        prevDiff = currDiff;
    }
    return -1;//! this will not be executed
}