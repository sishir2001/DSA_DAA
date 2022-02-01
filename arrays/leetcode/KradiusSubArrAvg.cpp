#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v_ll;
typedef vector<int> v_int;

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

v_int getAverages(v_int nums,int k);
void printVector(v_int nums);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T,n,k;
    cin >> T;
    while(T){
        cin >> n >> k;
        v_int nums(n); // vector
        FOR(i,n){
            cin >> nums[i];
        }
        v_int res = getAverages(nums,k);
        printVector(res);
        nums.clear();
        T--;
    }
    return 0;
}

v_int getAverages(v_int nums,int k){
    // @param nums : vector 
    // @param k : radius 
    if(k == 0)
        return nums;
    int n = nums.size(),x = 2*k+1;
    v_int res(n,-1);
    if(x > n)
        return res;
    
    int l = 0,r = x-1,sum = 0,i = k;
    FOR(j,x){
        sum = sum + nums[j];
    }
    while(r < n){
        if(l != 0 && r != x-1)
            sum = sum - nums[l-1] + nums[r];
        
        res[i] = sum/x;
        i++;
        r++;
        l++;
    }
    return res;
}

void printVector(v_int nums){
    int n = nums.size();
    FOR(i,n){
        cout << nums[i] <<" ";
    }
    cout <<"\n";
}