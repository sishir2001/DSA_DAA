// positioning elements around a range 
// all the positioned elements needs to be sorted
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

void leftShiftToSort(ll *nums,ll l);
void rightShiftToSort(ll *nums,ll n,ll r);
void positionAroundTheRange(ll *nums,ll n,ll rl, ll rr);
void printArray(ll *nums,ll n);


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll T,n,rl,rr;
    cin >> T;
    while(T){
        cin >> n >> rl >> rr;
        ll *a = new ll[n];
        FOR(i,n){
            cin >> a[i];
        }
        positionAroundTheRange(a,n,rl,rr);
        printArray(a,n);

        delete []a;
        T--;
    }
    return 0;
}

void leftShiftToSort(ll *nums,ll l){
    // maintaining this window to be sorted 
    while(l !=0){
        if(nums[l-1]>nums[l]){
            swap(nums[l-1],nums[l]);
        }
        else
            break;

        l--;
    }
}
void rightShiftToSort(ll *nums,ll n,ll r){
    // maintaining the right window to be sorted 
    while(r != n-1){
        if(nums[r+1] < nums[r]){
            swap(nums[r+1],nums[r]);
        }
        else
            break;
        r++;
    }
}

void positionAroundTheRange(ll *nums,ll n,ll rl,ll rr){
    // ! modification to hoare's partition
    // @param rl : range-left
    // @param rr : range-right

    ll l = 0,mid = 0,r = n-1;
    while(mid <= r){
        if(nums[mid] < rl){
            // smaller than the range
            if(mid != l)
                swap(nums[mid],nums[l]);
            leftShiftToSort(nums,l);
            l++;
            mid++;
        }
        else if(nums[mid] > rr){
            // greater than the range
            swap(nums[mid],nums[r]);
            rightShiftToSort(nums,n,r);
            r--;
        }
        else
            mid++;
    }
}

void printArray(ll *nums,ll n){
    // printing an array
    cout << "\n";
    FOR(i,n){
        cout << nums[i] << " ";
    }
}