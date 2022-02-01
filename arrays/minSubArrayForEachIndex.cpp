#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v_ll;
typedef vector<int> v_int;

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

ll* minSubArraySumForEachIndex(ll *a,ll n);
void printArray(ll *a,ll n);
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
        ll *res = minSubArraySumForEachIndex(a,n);
        printArray(res,n);
        delete []a;
        T--;
    }
    return 0;
}

ll* minSubArraySumForEachIndex(ll *a,ll n){
    // ! T(n) = O(n)
    // ! S(n) = O(n)
    
    // @param a : long long pointer to the array passed 
    // @param n : size of the array passed

    ll *res = new ll[n];
    res[n-1] = a[n-1];
    ll minSum = a[n-1],sum = a[n-1];
    FOR_custom_more_or_equal_desc(i,n-2){
        sum = min(sum+a[i],a[i]);
        minSum  = min(minSum,sum);
        res[i] = minSum;
    }
    return res;
}

void printArray(ll *a,ll n){
    // ! T(n) = O(n)
    // ! S(n) = O(1)

    // @param a : long long pointer to the array passed 
    // @param n : size of the array passed

    cout << "\n";
    FOR(i,n){
        cout << a[i] <<" ";
    }
    cout << "\n";
}