// check if the array can be divided into three parts of equal sum
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

bool isSumDivThree(vi nums);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool t = true,f = false;
    deb2(t,f);
    int T,x,n;
    vi nums; // vector
    cin >> T;
    while(T){
        cin >> n;
        FOR(i,n){
            cin >> x;
            nums.PB(x);
        }
        cout << isSumDivThree(nums)<<"\n";
        nums.clear();
        T--;
    }
    return 0;
}

bool isSumDivThree(vi nums){
    // * T(n) = O(n) : two traversals of array
    // * S(n) = O(1) 

    int n = nums.size(),sum = 0;

    FOR(i,n)
        sum += nums[i];

    if(sum%3 != 0)
        return false;

    int x = sum/3,count = 0,checkSum = 0;
    FOR(i,n){
        if(checkSum > x)
            return false;
        if(checkSum == x){
            count++;
            checkSum = 0;
        }
        checkSum+=nums[i];
    } 
    if(checkSum == x)
        count++;
    return count == 3;
}