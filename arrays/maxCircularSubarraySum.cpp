// find the maximum of circular subarray 
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


int maxSubArraySum(int *a,int n);
int maxCircularSubarraySum(int *a,int n);

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
        cout << maxCircularSubarraySum(a,n)<<"\n";
        T--;
    }
    return 0;
}

int maxSubArraySum(int *a,int n){
    // normal implementation of kadane's algorithm 
    int sum = a[0],max_sum = a[0];
    FOR_custom_less(i,n,1){
        sum = max(sum+a[i],a[i]);
        max_sum = max(sum,max_sum);
    }
    return max_sum;
}
int maxCircularSubarraySum(int *a,int n){
    // @param a : pointer to a heap array
    // @param n : size of the array
    // *T(n) = O(n)
    // *S(n) = O(1)

    int normal_sum = maxSubArraySum(a,n);
    if(normal_sum < 0) // ! important line of the algorithm , when all elements of an array are -ve
        return normal_sum;
    
    // inverting the array to find the max of only circular sub array
    int arr_sum = 0;
    FOR(i,n){
        arr_sum += a[i];
        a[i]= -a[i];
    }
    int maxOnlyCircularSubarray = maxSubArraySum(a,n)+ arr_sum;
    return max(maxOnlyCircularSubarray,normal_sum);
}