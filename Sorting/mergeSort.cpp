// implementation of mergesort
#include<bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long l;
typedef unsigned long ul;
typedef long long ll;
typedef unsigned long long ull;

typedef vector<l> v_l;
typedef vector<ul> v_ul;
typedef vector<ll> v_ll;
typedef vector<ull> v_ull;
typedef vector<int> v_int;
typedef vector<uint> v_uint;

#define PB push_back // for vector
#define PPB pop_back // for vector
#define mod 1000000007 // 1e9+7
#define deb(x) cout << #x << " = "<<x<<"\n" // for debugging
#define deb2(x,y) cout << #x << " = "<<x << " , " << #y << " = " << y <<"\n" // for debugging 
#define FOR(a,end) for(int (a) = 0;(a) < (end);(a)++) // regular for loop
#define FOR_REV(a,start) for(int (a) = (start)-1;(a) >= 0;(a)--) // regular for loop decreasing
#define FOR_less(a,end,start) for(int (a) = (start);(a) < (end);(a)++) // regular for loop
#define FOR_REV_great(a,end,start) for(int (a) = (start);(a) > (end);(a)--) // regular for loop
#define FOR_less_or_equal(a,end,start) for(int (a) = (start);(a) <= (end);(a)++) // regular for loop
#define FOR_REV_great_or_equal(a,end,start) for(int (a) = (start);(a) >= (end);(a)--) // regular for loop

void mergeSort(ll *nums,ll l,ll r);
void merge(ll *nums,ll l,ll m,ll r);
void printArray(ll *nums,ll n);


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
        mergeSort(a,0,n-1);
        printArray(a,n);

        delete []a;
        T--;
    }
    return 0;
}

void merge(ll *nums,ll l,ll m,ll r){
    // @param arr: pointer to the array
    // @param l: lowest index
    // @param m: mid index
    // @param r: end index

    // ! T(n) = O(n)
    // ! S(n) = O(n)
    // part of mergeSort
    ll n1 = m-l+1,n2 = r-m;

    // only one array
    if(n2 == 0 || n1 == 0)
        return;
    ll *left = new ll[n1],*right = new ll[n2];

    // * setting up the auxiliary space
    FOR_less_or_equal(i,m,l)
        left[i-l] = nums[i];
    FOR_less_or_equal(i,r,m+1)
        right[i-m-1] = nums[i];
    
    // * standard merge of two sorted arrays function
    ll i = 0,j = 0,k = l;
    while(i < n1 && j < n2){
        if(left[i] <= right[j])
            nums[k++] = left[i++];
        else
            nums[k++] = right[j++];
    }

    while(i < n1){
        nums[k++] = left[i++];
    }

    while(j < n2){
        nums[k++] = right[j++];
    }
}

void mergeSort(ll *nums,ll l,ll r){
    // * divide and conquer
    // @param nums : pointer to the array that has to be sorted
    // @param l : lowerBound index
    // @param r : upperBound index

    // !T(n) = O(nlogn)
    // !S(n) = O(n)

    if(l >= r)
        return;
    // dividing the array into two halfes
    ll m = (l+r)/2;
    mergeSort(nums,l,m);
    mergeSort(nums,m+1,r);
    merge(nums,l,m,r);
}

void printArray(ll *nums,ll n){
    FOR(i,n)
        cout << nums[i] <<" ";
    cout << "\n";
}