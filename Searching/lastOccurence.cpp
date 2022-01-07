// find the last occurence of an element in a sorted array
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

ll lastOccurence(vll nums,ll x){
    ll n = nums.size();
    ll l = 0,r = n-1;
    while(l <= r){
        ll m = (l+r)/2;
        if(nums[m] < x)
            l = m+1;
        else if(nums[m] > x)
            r = m-1;
        else{
            if(m == n-1 || nums[m+1]!=nums[m])
                return m;
            else
                l = m+1;
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T,n,x;
    cin >> T;
    while(T){
        // cout << "n and x :";
        cin >> n >> x;
        vll nums(n); // vector
        FOR(i,n){
            cin >> nums[i];
        }
        cout << lastOccurence(nums,x)<<"\n";
        nums.clear();
        T--;
    }
    return 0;
}
