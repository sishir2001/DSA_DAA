#include<bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long l;
typedef unsigned long ul;
typedef long long ll;
typedef unsigned long long ull;

typedef vector<l> v_l;
typedef vector<ul> v_ul;
typedef vector<ll> v_ll;
typedef vector<ull> v_ull;
typedef vector<int> v_int;
typedef vector<uint> v_uint;

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

double median(ll *a1,ll n1,ll *a2,ll n2);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll T,n1,n2;
    cin >> T;
    while(T){
        cin >> n1 >> n2;
        ll *a1 = new ll[n1],*a2 = new ll[n2];
        FOR(i,n1){
            cin >> a1[i];
        }
        FOR(i,n2){
            cin >> a2[i];
        }

        cout << median(a1,n1,a2,n2) <<"\n";

        delete []a1;
        delete []a2;
        T--;
    }
    return -1.0;
}

double median(ll *a1,ll n1,ll *a2,ll n2){
    if(n1 > n2){
        swap(a1,a2);
        swap(n1,n2);
    }

    ll l = 0,r = n1-1,thresh = (n1+n2+1)/2;
    while(l <= r){
        ll i1 = (l+r)/2;
        ll i2 = thresh - i1;

        ll mn1 = (i1 < n1)?a1[i1]:INT_MAX;
        ll mx1 = (i1 > 0)?a1[i1-1]:INT_MIN;

        ll mn2 = (i2 < n2)?a2[i2]:INT_MAX;
        ll mx2= (i2 > 0)?a2[i2-1]:INT_MIN;

        ll mx = max(mx1,mx2),mn = min(mn1,mn2);
        if(mx <= mn){
            // found the median
            return (((n1+n2)&1) == 0)?(double)(mx+mn)/2:(double)mx/1;
        }
        else if(mx1 > mn2)
            r = i1-1;
        else 
            l = i1+1;
    }
    return 0.0; // ! should never be returned
}