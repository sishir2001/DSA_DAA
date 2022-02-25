// sort an array of 0s 1s 2s in O(n)
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
ll shiftOneToEnd(ll *nums,ll n);
void Naivesort012(ll *nums,ll n);
void efficientSort012(ll *nums,ll n);

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
        efficientSort012(a,n);
        printArray(a,n);
        delete []a;
        T--;
    }
    return 0;
}

ll shiftOneToEnd(ll *nums,ll n){
    // shifting all the elements equal to partition to the right end 
    // modigying the hoare's partition
    ll l = -1,r = n;
    while(true){
        do{
            l++;
        }while(nums[l]!=1 && l <= r);

        do{
            r--;
        }while(nums[r]==1 && r >= l);
        if(l >= r)
            return r;
        swap(nums[r],nums[l]);
    }
    // should not come here
}
void Naivesort012(ll *nums,ll n){

    // !T(N) = O(n)
    // !S(N) = O(1)

    ll i = -1,r = shiftOneToEnd(nums,n);
    deb(r);
    printArray(nums,n);

    FOR_less_or_equal(j,r,0){
        if(nums[j] < 1){
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

void efficientSort012(ll *nums,ll n){
    // * using dutch-national flag algorithm
    // -> a modified version of hoare's partition
    // maintaining four parts of the section
    ll l = 0,mid = 0,r = n-1;
    while(mid <= r){
        // we only evaluate mid index
        if(nums[mid] == 0){
            swap(nums[mid],nums[l]);
            l++;
            mid++; 
            // ! maintaining the window size of the pivot elements
        }
        else if(nums[mid] == 1){
            mid ++;// ! increasing the window size of the pivot elements
        }
        else{
            swap(nums[mid],nums[r]);
            r--;
        }
    }
}