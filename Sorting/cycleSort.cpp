// implementing cycle sort 
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
typedef pair<l,l> p_l;
typedef pair<ul,ul> p_ul;
typedef pair<ll,ll> p_ll;
typedef pair<ull,ull> p_ull;
typedef pair<int,int> p_int;
typedef pair<uint,uint> p_uint;

#define F first;
#define S second;
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

void cycleSort(ll *nums,ll n);
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
        cycleSort(a,n);
        printArray(a,n);

        delete []a;
        T--;
    }
    return 0;
}

void cycleSort(ll *nums,ll n){
    // !T(n) = O(n^2)
    // !S(n) = O(1)

    // useful for no of swaps to check to be a sorted array
    ll i = 0,item = nums[0];
    while(i < n){
        ll count = 0;
        FOR(j,n){
            if(nums[j] < item && i != j)
                count ++;
        }
        if(nums[i] == nums[count]){
            i = count+1;
            if(i != n){
                item = nums[i];
            }
        }
        else{
            i = count;
            if(i != n){
                ll k = nums[i];
                nums[i] = item;
                item = k;
            }
        }
        printArray(nums,n);
    }
}

void printArray(ll *nums,ll n){
    cout << "\n";
    FOR(i,n)
        cout << nums[i] << " ";
}