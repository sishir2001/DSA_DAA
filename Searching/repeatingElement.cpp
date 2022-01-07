// find the only one repeating element in the array whose values are in a range
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

ll repeatingElement1(ll *a,ll n){
    // * T(N) = O(N)
    // * S(N) = O(1)

    // find the maximum value of an element in a
    ll mx = LLONG_MIN;
    FOR(i,n)
        mx = max(mx,a[i]);
    ll maxEle = mx+1;
    // now adding the frequencies of the values
    FOR(i,n){
        if(a[i]/maxEle >= 2)
            return i;
        ll index = a[i]%maxEle;
        a[index]+= maxEle;
    }
    FOR(i,maxEle){
        if(a[i]/maxEle >= 2)
            return i;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll T,n;
    cin >> T;
    while(T){
        cin >> n;
        ll *a = new ll[n];
        FOR(i,n){
            cin >> a[i];
        }
        cout << repeatingElement1(a,n)<<'\n';
        delete []a;
        T--;
    }
    return 0;
}

