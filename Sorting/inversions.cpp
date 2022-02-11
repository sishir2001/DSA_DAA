// ? count no of inversions in an array
// * inversion if : i < j and a[i] > a[j]
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

ll countInversions1(ll *a,ll n);
ll countInversionsMergeSort(ll *a,ll l,ll r);
ll countInversionsMerge(ll *a,ll l,ll m,ll r);

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
        // bool check = countInversions1(a,n) == countInversionsMergeSort(a,0,n-1);
        // cout << check <<"\n";
        cout << countInversionsMergeSort(a,0,n-1) <<"\n";
        delete []a;
        T--;
    }
    return 0;
}

ll countInversions1(ll *a,ll n){
    // !T(N) = O(N^2)
    // !S(N) = O(1)
    // * improvement to bubble sort

    ll count = 0;
    FOR_less(i,n,1){
        ll j = i;
        while(j > 0 && a[j-1] > a[j]){
            swap(a[j-1],a[j]);
            ++count;
            --j;
        }
    }
    return count;
}

ll countInversionsMergeSort(ll *a,ll l,ll r){
    // !T(N) = O(NlogN);
    // !S(N) = O(N);
    // * updation mergeSort to count the inversion

    if(l >= r)
        return 0;
    
    ll m = l + (r - l)/2;
    ll leftCount = countInversionsMergeSort(a,l,m);
    ll rightCount = countInversionsMergeSort(a,m+1,r);
    ll count = countInversionsMerge(a,l,m,r);
    return leftCount+rightCount+count;
}
ll countInversionsMerge(ll *a,ll l,ll m,ll r){
    // return the count of inversion while merging
    ll n1 = m - l+1,n2 = r-m,i = 0,j = 0,k = l,count = 0;
    ll *left = new ll[n1],*right = new ll[n2];
    // copying the elements to left and right
    FOR_less_or_equal(i,m,l){
        left[i-l] = a[i];
    }
    FOR_less_or_equal(i,r,m+1){
        right[i - m - 1] = a[i];
    }

    // merging two arrays
    while(i < n1 && j < n2){
        if(left[i] <= right[j])
            a[k++] = left[i++];
        else{
            count = count + n1 - i;
            a[k++] = right[j++];
        }
    }
    while(i < n1)
        a[k++] = left[i++];

    while(j < n2)
        a[k++] = right[j++];
    return count;
}