// count the frequency of the given number in a sorted array
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

ll countFreqR(vll arr,ll x,ll l,ll r);
ll countFreqI(vll arr,ll x);
ll firstOccurence(vll arr,ll x);
ll lastOccurence(vll arr,ll x);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll T,n,x;
    cin >> T;
    while(T){
        cin >> n >> x;
        vll nums(n); // vector
        FOR(i,n){
            cin >> nums[i];
        }
        cout << countFreqR(nums,x,0,n-1) << " ";
        cout << countFreqI(nums,x) << "\n";
        nums.clear();
        T--;
    }
    return 0;
}

ll countFreqR(vll arr,ll x,ll l,ll r){
    // *T(n) = O(logN)
    // *S(n) = O(logN)
    if(l > r)
        return 0;
    ll m = (l+r)/2;
    if(x < arr[m])
        return countFreqR(arr,x,l,m-1);
    else if(x > arr[m])
        return countFreqR(arr,x,m+1,r);
    else
        return 1 + countFreqR(arr,x,l,m-1) + countFreqR(arr,x,m+1,r);
}
ll firstOccurence(vll arr,ll x){
    // returns the index of first occurence of the element
    ll n = arr.size();
    ll l = 0,r = n-1;
    while(l <= r){
        ll m = (l+r)/2;
        if(x < arr[m])
            r = m-1;
        else if(x > arr[m])
            l = m+1;
        else{
            if(m == 0 || arr[m-1]!=arr[m])
                return m;
            else
                r = m-1;
        }
    }
    return -1;
}
ll lastOccurence(vll arr,ll x){
    // returns the index of last occurence of the element
    ll n = arr.size();
    ll l = 0,r = n-1;

    while(l <= r){
        ll m = (l+r)/2;
        if(x < arr[m])
            r = m-1;
        else if(x > arr[m])
            l = m+1;
        else{
            if(m == n-1 || arr[m+1]!=arr[m])
                return m;
            else
                l = m+1;
        }
    }
    return -1;
}
ll countFreqI(vll arr,ll x){
    // *T(n) = O(logn)
    // *S(n) = O(1)
    // counting the occurence of an element iteratively 
    ll firstIndex = firstOccurence(arr,x);
    if(firstIndex == -1)
        return 0;
    return lastOccurence(arr,x)-firstIndex +1;
}