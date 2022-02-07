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

void swapVector(v_ll& num1,v_ll& num2);
void printVector(v_ll& num,ll n);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll T,n,m;
    cin >> T;
    while(T){
        cin >> n >> m;
        v_ll nums1(n); // vector
        v_ll nums2(m); // vector
        FOR(i,n){
            cin >> nums1[i];
        }
        FOR(i,m){
            cin >> nums2[i];
        }
        swapVector(nums1,nums2);
        nums1.clear();
        nums2.clear();
        T--;
    }
    return 0;
}



void swapVector(v_ll& num1,v_ll& num2){
    ll m = num1.size() , n = num2.size();
    if(m > n){
        swap(num1,num2);
        swap(m,n);
    }
    printVector(num1,m);
    printVector(num2,n);
}
void printVector(v_ll& num,ll n){
    FOR(i,n)
        cout << num[i] <<" ";
    cout << "\n";
}