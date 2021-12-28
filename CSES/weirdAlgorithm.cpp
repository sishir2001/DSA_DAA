#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v_ll;
typedef vector<int> v_int;

#define mod 1000000007 // 1e9+7
#define deb(x) cout << #x << " = "<<x<<"\n" // for debugging
#define deb2(x,y) cout << #x << " = "<<x << " , " << #y << " = " << y <<"\n" // for debugging 
#define FOR(a,end) for(int (a) = 0;(a) < (end);(a)++) // regular for loop
#define FOR_desc(a,end) for(int (a) = (end)-1;(a) >= 0;(a)--) // regular for loop decreasing
#define FOR_custom_more_desc(a,start) for(int (a) = (start);(a) > 0;(a)--) 
#define FOR_custom_more_or_equal_desc(a,start) for(int (a) = (start);(a) >= 0;(a)--) 
#define FOR_custom_less(a,end,start) for(int (a) = (start);(a) < (end);(a)++) // regular for loop
#define FOR_custom_less_or_equal(a,end,start) for(int (a) = (start);(a) <= (end);(a)++) // regular for loop

void weirdAlgorithm(ll n);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    weirdAlgorithm(n);

    return 0;
}

void weirdAlgorithm(ll n){
    while(n != 1){
        cout << n << " ";
        if((n&1) == 1){
            // odd 
            n = 3*n+1;
        }
        else{
            // even 
            n = n/2;
        }
    }
    cout << n << "\n";
}
