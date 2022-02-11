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

void unionSortedArrays(ll *a,ll n,ll *b,ll m);

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
        unionSortedArrays(a,n,b,m);
        delete []a;
        delete []b;
        T--;
    }
    return 0;
}

void unionSortedArrays(ll *a,ll n,ll *b,ll m){
    // !T(N) = O(N+M)
    // !S(N) = O(1)

    ll recentAns = LLONG_MIN,i = 0,j = 0;
    while(i < n && j < m){
        if(a[i] == b[j]){
            if(recentAns == LLONG_MIN || recentAns != a[i]){
                recentAns = a[i];
                cout << recentAns << " ";
            }
            i++;
            j++;
        }
        else if(a[i] < b[j]){
            if(recentAns == LLONG_MIN || recentAns != a[i]){
                recentAns = a[i];
                cout << recentAns << " ";
            }
            i++;
        }
        else{
            if(recentAns == LLONG_MIN || recentAns != b[j]){
                recentAns = b[j];
                cout << recentAns << " ";
            }
            j++;
        }
    }
    while(i < n){
        if(recentAns == LLONG_MIN || recentAns != a[i]){
            recentAns = a[i];
            cout << recentAns << " ";
        }
        i++;
    }
    while(j < m){
        if(recentAns == LLONG_MIN || recentAns != b[j]){
            recentAns = b[j];
            cout << recentAns << " ";
        }
        j++;
    }
    cout << "\n";
}