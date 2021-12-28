// reading and writing the from a file 
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

void testingBuiltInInt(int32_t x);
void testingBuiltInLL(ll x);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ! for reading from the files 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    ll T,n;
    cin >> T;
    while(T){
        cin >> n;
        testingBuiltInLL(n);
        T--;
    }
    return 0;
}

void testingBuiltInInt(int32_t x){

    deb(x);
    // ! these functions are only for int type
    cout << __builtin_clz(x) << "\n"; // no of zeroes at the start of bit representation
    cout << __builtin_ctz(x) << "\n";// no of zeroes at the end of bit representation
    cout << __builtin_popcount(x) << "\n";// no of ones in the bit representation
    cout << __builtin_parity(x) << "\n";// no of ones in the bit representation % 2

}
void testingBuiltInLL(ll x){

    deb(x);
    // ! these functions are only for int type
    cout << __builtin_clzll(x) << "\n"; // no of zeroes at the start of bit representation
    cout << __builtin_ctzll(x) << "\n";// no of zeroes at the end of bit representation
    cout << __builtin_popcountll(x) << "\n";// no of ones in the bit representation
    cout << __builtin_parityll(x) << "\n";// no of ones in the bit representation % 2

}