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
typedef pair<l,l> p_l;
typedef pair<ul,ul> p_ul;
typedef pair<ll,ll> p_ll;
typedef pair<ull,ull> p_ull;
typedef pair<int,int> p_int;
typedef pair<uint,uint> p_uint;

#define F first;
#define S second;
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

bool binarySearch(ll *A,ll l,ll r,ll f);
bool find3Numbers(ll *A,ll n,ll X);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll T,n,x;
    cin >> T;
    bool t = true,f = false;
    deb2(t,f);
    while(T){
        cin >> n >> x;
        ll *a = new ll[n];
        FOR(i,n){
            cin >> a[i];
        }
        cout << find3Numbers(a,n,x) << "\n";
        delete []a;
        T--;
    }
    return 0;
}

bool binarySearch(ll *A,ll l,ll r,ll f){
    if(f < A[l] || f > A[r])
        return false;
    while(l <= r){
        ll m = (l+r)/2;
        if(A[m] == f)
            return true;
        else if(A[m] > f)
            r = m-1;
        else
            l = m+1;
    }
    return false;
}

bool find3Numbers(ll *A,ll n,ll X){
    sort(A,A+n);
    FOR(i,n-2){
        for(ll j = i+1;j<n-1;j++){
            ll f = X - A[i]-A[j],l = j+1,r = n-1;
            if(binarySearch(A,l,r,f))
                return true;
        }
    }
    return false;
}
