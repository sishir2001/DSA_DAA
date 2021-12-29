// !https://www.geeksforgeeks.org/count-frequencies-elements-array-o1-extra-space-time/


// given : unsorted array of n integers that contain integers from 1-n . The elements can be repeated multiple times and some elements in the range can be missing 

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

void printFrequencies(int *arr,int n){
    // the elements will be in [1,n]
    // *T(n) = O(N)
    // *S(n) = O(1)

    // the maximum value a element can have is n , we will add n+1 for every arr[i]-1 th index
    // while traversing through 1 to n , the frequency will the value/n+1
    int m = n+1,index = 0,count = 0;
    // ? traversing the array
    FOR(i,n){
        // !here taking the array values as indexes of the same array and incrementing with m
        index = arr[i]%m -1;
        arr[index]+=m;
    } 
    // going through the range [1,n]

    FOR(i,n){
        count = arr[i]/m;
        cout << count << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("intput.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T,n;
    cin >> T;
    while(T){
        cin >> n;
        int *a = new int[n];
        FOR(i,n){
            cin >> a[i];
        }
        printFrequencies(a,n);
        T--;
    }
    return 0;
}
