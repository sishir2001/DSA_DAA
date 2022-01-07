// find the squareRoot floor of the given number 
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

ll squareRoot(ll x);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll T,x;
    cin >> T;
    while(T){
        cin >> x;
        cout << squareRoot(x) <<"\n";
        T--;
    }
    return 0;
}

ll squareRoot(ll x){

    // * T(n) = O(logn)
    // * S(n) = O(1)
    // ? binary search from 0 to floor(n/2)

    if(x < 0)
        return -1;
    if(x == 0 || x == 1)
        return x;
    ll l = 0,r = x/2,res = 0;
    while(l <= r){
        ll m = (l+r)/2;
        ll lb = m*m,ub = (m+1)*(m+1);
        if(x == ub){
            res = m+1;
            break;
        }
        else if(x >= lb && x < ub){
            res = m;
            break;
        }
        else if(x > lb)
            l = m+1;
        else if(x < lb)
            r = m-1;
    }
    return res;
}