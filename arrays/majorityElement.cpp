// find the majority element in an array 
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

int majorityElement(int *a,int n);

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
        cout << majorityElement(a,n) << "\n";
        T--;
    }
    return 0;
}

int majorityElement(int *a,int n){
    // @param a : pointer to a heap array
    // @param n : size of the array
    // *T(n) = O(n)
    // *S(n) = O(1)
    
    // an element occuring more that n/2 times 
    int threshhold = n/2 +1 ; // integer division + 1 

    // ? Finding the candidate for majority element , default a[0]
    int majority = 0,count = 1;
    FOR_custom_less(i,n,1){
        if(a[majority] == a[i])
            count ++;
        else
            count --;
        if(count == 0){
            majority = i;
            count = 1;
        }
    }

    // counting the frequency of the candidate 
    int maj_count = 0;
    FOR(i,n){
        if(a[majority] == a[i])
            maj_count++;
    }
    return (maj_count >= threshhold)?majority : -1;
}