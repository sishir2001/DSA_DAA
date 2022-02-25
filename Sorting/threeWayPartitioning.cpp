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

void printArray(ll *nums,ll n);
ll shiftPivotToEnd(ll *nums,ll n,ll p);
void threeWayPartition(ll *nums,ll n,ll p);
void EfficientThreeWayPartioning(ll *nums,ll n,ll p);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    ll T,n,p;
    cin >> T;
    while(T){
        cin >> n >> p;
        ll *a = new ll[n];
        FOR(i,n){
            cin >> a[i];
        }
        EfficientThreeWayPartioning(a,n,p);
        printArray(a,n);

        delete []a;
        T--;
    }
    return 0;
}

ll shiftPivotToEnd(ll *nums,ll n,ll p){
    // shifting all the elements equal to partition to the right end 
    // modigying the hoare's partition
    ll l = -1,r = n;
    while(true){
        do{
            l++;
        }while(nums[l]!=p && l <= r);

        do{
            r--;
        }while(nums[r]==p && r >= l);
        if(l >= r)
            return r;
        swap(nums[r],nums[l]);
    }
    // should not come here
}
void threeWayPartition(ll *nums,ll n,ll p){

    // !T(N) = O(n)
    // !S(N) = O(1)

    ll i = -1,r = shiftPivotToEnd(nums,n,p);

    FOR_less_or_equal(j,r,0){
        if(nums[j] < p){
            i++;
            swap(nums[i],nums[j]);
        }
    }
    ll k = i+1;
    FOR_less(j,n,r+1){
        swap(nums[k++],nums[j]);
    }

}

void printArray(ll *nums,ll n){
    cout << "\n";
    FOR(i,n){
        cout << nums[i] <<" ";
    }
}

void EfficientThreeWayPartioning(ll *nums,ll n,ll p){
    // ! using dutch-national flag algorithm 
    // ! T(N) = O(N)
    // ! S(N) = O(1)

    ll l = 0,mid = 0,r = n-1;
    while(mid <= r){
        if(nums[mid] < p){
            // shift to the left of the array
            if(mid != l)
                swap(nums[mid],nums[l]);
            mid++;
            l++;
        }
        else if(nums[mid] == p){
            // increase the size of the window 
            mid++;
        }
        else{
            // shift the element to the right 
            swap(nums[r],nums[mid]);
            r--;
        }
    }
}