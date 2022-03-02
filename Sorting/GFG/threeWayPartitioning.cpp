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

void threeWayPartioning(v_ll &nums,ll a,ll b);
void printVector(v_ll nums);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    ll T,n,a,b;
    cin >> T;
    while(T){
        cin >> n >> a >> b;
        v_ll nums(n); // vector
        FOR(i,n){
            cin >> nums[i];
        }

        threeWayPartioning(nums,a,b);
        printVector(nums);
        nums.clear();
        T--;
    }
    return 0;
}

void threeWayPartioning(v_ll &nums,ll a,ll b){
    // @param a : left-bound of the range
    // @param b : right-bound of the range
    ll n = nums.size();
    ll l = 0,r = n-1,m = 0;
    while(m <= r){
        if(nums[m] < a){
            // less than the range
            if(l != m)
                swap(nums[l],nums[m]);
            l++;
            m++;
        }
        // in the range
        else if(nums[m] >=a && nums[m] <= b)
            m++;

        // > than the range
        else{
            swap(nums[m],nums[r]);
            r--;
        } 
    }
}
void printVector(v_ll nums){
    ll n = nums.size();
    cout << "\n";
    FOR(i,n){
        cout << nums[i] << " ";
    }
}