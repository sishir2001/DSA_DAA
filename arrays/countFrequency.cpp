// find frequencies of all the elements in a sorted array 
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

void printFrequency(int *a,int n){
    // @param a: pointer to an heap allocated array
    // @param n: size of the array
    // *T(n) = O(n)
    // *S(n) = O(1)

    int count = 1,i=1;
    for(;i<n;i++){
        if(a[i-1] == a[i])
            count++;
        else{
            cout << a[i-1] << ":" << count << "\n";
            count = 1;
        }
    }
    cout << a[i-1] << ":" << count << "\n";
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
        printFrequency(a,n);
        delete[] a; // ! deallocating the heap space to the array
        T--;
    }
    return 0;
}
