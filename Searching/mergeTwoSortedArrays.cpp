// merge two sorted arrays without taking any extra space
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
void merge(ll *a1,ll n,ll *a2,ll m);
void printArray(ll *a,ll n);

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
        ll *a1 = new ll[n],*a2 = new ll[m];
        FOR(i,n){
            cin >> a1[i];
        }
        FOR(i,m){
            cin >> a2[i];
        }
        merge(a1,n,a2,m);

        printArray(a1,n);
        printArray(a2,m);

        delete []a1;
        delete []a2;
        T--;
    }
    return 0;
}

void merge(ll *a1,ll n,ll *a2,ll m){
    ll i1 = 0,i2 = 0,k = 0,mx = max(a1[n-1],a2[m-1])+1;

    while(i1 < n && i2 < m){
        ll x1 = a1[i1]%mx,x2 = a2[i2]%mx,x = 0;
        if(x1 <= x2){
            i1++;
            x = x1;
        }
        else{
            i2++;
            x = x2;
        }
        if(k < n){
            a1[k] = x*mx + a1[k]%mx;
            k++;
        }
        else{
            a2[k-n] = x*mx + a2[k-n]%mx;
            k++;
        }
    }
    while(i1 < n){
        ll x = a1[i1++]%mx;
        if(k < n){
            a1[k] = x*mx + a1[k]%mx;
            k++;
        }
        else{
            a2[k-n] = x*mx + a2[k-n]%mx;
            k++;
        }
    }
    while(i2 < m){
        ll x = a2[i2++]%mx;
        if(k < n){
            a1[k] = x*mx + a1[k]%mx;
            k++;
        }
        else{
            a2[k-n] = x*mx + a2[k-n]%mx;
            k++;
        }
    }

    // now retrieving the modified variable
    FOR(i,n){
        a1[i] = a1[i]/mx;
    }
    FOR(i,m){
        a2[i] = a2[i]/mx;
    }


}

void printArray(ll *a,ll n){
    FOR(i,n)
        cout << a[i] <<" ";
    cout << "\n";
}