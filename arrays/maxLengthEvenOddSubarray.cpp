// find the max_length of subarray having alternating even odd elements
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
// typedef vector<ll> v_ll;

#define mod 1000000007 // 1e9+7
#define deb(x) cout << #x << " = "<<x<<"\n" // for debugging
#define deb2(x,y) cout << #x << " = "<<x << " , " << #y << " = " << y <<"\n" // for debugging 
#define FOR(a,end) for(int (a) = 0;(a) < (end);(a)++) // regular for loop
#define FOR_desc(a,end) for(int (a) = (end)-1;(a) >= 0;(a)--) // regular for loop decreasing
#define FOR_custom_more_desc(a,start) for(int (a) = (start);(a) > 0;(a)--) 
#define FOR_custom_more_or_equal_desc(a,start) for(int (a) = (start);(a) >= 0;(a)--) 
#define FOR_custom_less(a,end,start) for(int (a) = (start);(a) < (end);(a)++) // regular for loop
#define FOR_custom_less_or_equal(a,end,start) for(int (a) = (start);(a) <= (end);(a)++) // regular for loop

int maxLenghtEvenOddSubArray(int *a,int n);

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
        cout << maxLenghtEvenOddSubArray(a,n)<<"\n";
        T--;
    }
    return 0;
}

int maxLenghtEvenOddSubArray(int *a,int n){
    // @param a : pointer to an array (pass by reference)
    // @param n : size of the array
    // *S(n) = O(1)
    // *T(n) = O(n)
    int prev = (a[0]&1),curr = -1,max_length = 1,count = 1;
    FOR_custom_less(i,n,1){
        curr = (a[i]&1);
        if(curr != prev)
            count++;
        else
            count = 1;
        prev = curr;
        max_length = max(max_length,count);
    }
    return max_length;
}