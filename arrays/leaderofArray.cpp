// find the leader elements of the array
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

void leaderElementsArray(int *a,int n);

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
        leaderElementsArray(a,n);
        delete[] a;
        T--;
    }
    return 0;
}

void leaderElementsArray(int *a,int n){
    // !T(N) = O(n)
    // !S(N) = O(1)
    // @param a : pointer to heap allocated array
    // @param n : size of the array
    int rMax = INT_MIN;
    FOR_desc(i,n){
        if(a[i] > rMax){
            cout << a[i] <<" ";
            rMax = a[i];
        }
    }
}
