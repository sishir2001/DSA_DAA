// find whether the given sum exits for a sum of subarray 
// the array is of non-negative integers and unsorted 
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

#define PB push_back // for vector
#define PPB pop_back // for vector
#define mod 1000000007 // 1e9+7
#define deb(x) cout << #x << " = "<<x<<"\n" // for debugging
#define deb2(x,y) cout << #x << " = "<<x << " , " << #y << " = " << y <<"\n" // for debugging 
#define FOR(a,end) for(int (a) = 0;(a) < (end);(a)++) // regular for loop
#define FOR_desc(a,end) for(int (a) = (end)-1;(a) >= 0;(a)--) // regular for loop decreasing
#define FOR_custom_more_desc(a,start) for(int (a) = (start);(a) > 0;(a)--) 
#define FOR_custom_more_or_equal_desc(a,start) for(int (a) = (start);(a) >= 0;(a)--) 
#define FOR_custom_less(a,end,start) for(int (a) = (start);(a) < (end);(a)++) // regular for loop
#define FOR_custom_less_or_equal(a,end,start) for(int (a) = (start);(a) <= (end);(a)++) // regular for loop

bool isSumInSubArr(vi nums,int sum);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool t = true,f = false;
    deb2(t,f);
    int T,x,n,sum;
    vi nums; // vector
    cin >> T;
    while(T){
        cout << "n and sum : ";
        cin >> n >> sum;
        FOR(i,n){
            cin >> x;
            nums.PB(x);
        }
        cout << isSumInSubArr(nums,sum)<<"\n";
        nums.clear();
        T--;
    }
    return 0;
}


bool isSumInSubArr(vi nums,int sum){
    // ! there is no particular window size 
    // *T(n) = O(n)
    // *S(n) = O(1)
    // bool res = false;
    int s = nums[0],size = nums.size(),l = 0,h = 1; // l : low , h : high 
    while( l <= h && h < size){

        if(s == sum || nums[h] == sum){
            return true;
        }

        else if(l == h && nums[h] == s)
            h++;
        else if(s < sum){
            s += nums[h];
            h++;
        }
        else if(s > sum){
            s = s - nums[l];
            l++;
        }

    }
    if( s == sum){
        return true;
    }
    return false;
}