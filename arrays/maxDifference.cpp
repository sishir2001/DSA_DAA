// Find the max difference in the array while j > i 
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
// typedef vector<ll> v_ll;

#define mod 1000000007 // 1e9+7
#define deb(x) cout << #x << " = "<<x<<"\n" // for debugging
#define deb2(x,y) cout << #x << " = "<<x << " , " << #y << " = " << y <<"\n" // for debugging 
#define FOR(a,end) for(int (a) = 0;(a) < (end);(a)++) // regular for loop
#define FOR_desc(a,end) for(int (a) = (end)-1;(a) >= 0;(a)--) // regular for loop decreasing
#define FOR_custom_less(a,end,start) for(int (a) = (start);(a) < (end);(a)++) // regular for loop
#define FOR_custom_less_or_equal(a,end,start) for(int (a) = (start);(a) <= (end);(a)++) // regular for loop

int maxDifference(int *a ,int n){
    // @param a : pointer to a heap allocated array
    // @param n : size of the array 
    // * S(n) = O(1)
    // * T(n) = O(n)
    int res = INT_MIN,min_index = 0;
    FOR_custom_less(i,n,1){
        res = max(res,a[i]-a[min_index]);
        min_index = (a[i] > a[min_index])?min_index:i;
        // for debugging
        deb(i);
        deb(res);
        deb(min_index);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,n;
    cin >> T;

    while(T){
        cin >> n;
        int *a = new int[n];

        FOR(i,n){
            cin >> a[i];
        }

        cout << maxDifference(a,n);
        delete[] a;
        T--;
    }
    return 0;
}
