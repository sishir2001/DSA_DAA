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

void printArray(ll *nums,ll n);
ll *merge(ll *a,ll n,ll *b,ll m);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll T,n,m;
    cin >> T;
    while(T){
        cin >> n >> m;
        ll *a = new ll[n],*b = new ll[m];
        FOR(i,n){
            cin >> a[i];
        }
        FOR(i,m){
            cin >> b[i];
        }

        printArray(merge(a,n,b,m),n+m);
        delete []a;
        delete []b;
        T--;
    }
    return 0;
}

void printArray(ll *nums,ll n){
    FOR(i,n)
        cout << nums[i] <<" ";
    cout << "\n";
}

ll *merge(ll *a,ll n,ll *b,ll m){
    // * merging two sorted arrays
    // !T(N) = O(n+m)
    // !S(N) = O(n+m)

    ll *c = new ll[n+m]; // heap allocated array
    ll i = 0,j = 0,k = 0;

    while(i < n && j < m){
        if(a[i] <= b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while(i < n)
        c[k++] = a[i++];

    while(j < m)
        c[k++] = b[j++];
    
    return c;
}