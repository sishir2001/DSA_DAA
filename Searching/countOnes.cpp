// * count ones in a sorted binary array 
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

ll countOnes(vll arr);

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
        cout << countOnes(nums)<<"\n";
        nums.clear();
        T--;
    }
    return 0;
}

ll countOnes(vll arr){

    // *T(n) = O(logn)
    // *S(n) = O(1)

    ll n = arr.size();
    ll l = 0,r = n-1;
    while(l <= r){
        if(arr[l] == 1 && arr[r] == 1)
            return 1 + r - l;
        if(arr[r]!=1)
            return 0;
        ll m = (l+r)/2;
        if(arr[m] == 1)
            l = m-1;
        else if(arr[m] == 0)
            l = m+1;
    }
    return 0;// never addressed
}