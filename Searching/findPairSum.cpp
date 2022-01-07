// given a sum, find pair of elements that are equal to a sum in sorted array
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

bool isPairSumTwo(vll nums,ll sum);
bool isPairSumThree(vll nums,ll sum);
bool binarySearch(vll nums,ll l,ll r,ll x);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    bool t = true,f = false;
    deb2(t,f);
    ll T,n,sum;
    cin >> T;
    while(T){
        cin >> n >> sum;
    vll nums(n); // vector
        FOR(i,n){
            cin >> nums[i];
        }
        cout <<"pair 2 : "<< isPairSumTwo(nums,sum)<<"\n";
        cout <<"pair 3 : "<< isPairSumThree(nums,sum)<<"\n";
        cout << "\n";
        nums.clear();
        T--;
    }
    return 0;
}

bool isPairSumTwoForThree(vll nums,ll l,ll r,ll sum){
    // * T(n) = O(n)
    // * S(n) = O(1)
    // pair of two
    // ! Two pointer approach 
    while(l < r){
        if(nums[l]+nums[r] == sum)
            return true;
        else if(nums[l] + nums[r] < sum)
            l++;
        else 
            r--;
    }
    return false;
}
bool isPairSumTwo(vll nums,ll sum){
    // * T(n) = O(n)
    // * S(n) = O(1)
    // pair of two
    // ! Two pointer approach 

    ll n = nums.size();
    if(n == 1)
        return false;
    ll l = 0,r = n-1;
    while(l < r){
        if(nums[l]+nums[r] == sum)
            return true;
        else if(nums[l] + nums[r] < sum)
            l++;
        else 
            r--;
    }
    return false;
}

bool isPairSumThree(vll nums,ll sum){
    // *T(N)= O(n^2)
    // *S(N)= O(1)
    ll n = nums.size();
    FOR(i,n-2){
        if(isPairSumTwoForThree(nums,i+1,n-1,sum)){
            return true;
        }
    }
    return false;
}

bool binarySearch(vll nums,ll l,ll r,ll x){
    while(l <= r){
        ll m = (l+r)/2;
        if(nums[m] == x)
            return true;
        else if(nums[m] < x)
            l = m+1;
        else r = m-1;
    }
    return false;
}