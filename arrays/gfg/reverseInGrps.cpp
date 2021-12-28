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

void reverseInGroup(vi &nums,int n,int k);
void reverse(vi &nums,int l,int r);
void printVector(vi &nums,int n);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,x,n,k;
    vi nums; // vector
    cin >> T;
    while(T){
        cout << "n and k : ";
        cin >> n >> k;
        FOR(i,n){
            cin >> x;
            nums.PB(x);
        }
        cout << "Before : " ;
        printVector(nums,nums.size());

        reverseInGroup(nums,nums.size(),k);

        cout << "After : " ;
        printVector(nums,nums.size());
        nums.clear();
        T--;
    }
    return 0;
}

void printVector(vi &nums,int n){
    FOR(i,n){
        cout << nums[i] << " ";
    }
    cout << "\n";
}

void reverseInGroup(vi &nums,int n,int k){
    int l = 0,r = k-1;
    while(r < n){
        reverse(nums,l,r);
        l+=k;
        r+=k;
    }
    if(l < n){
        reverse(nums,l,n-1);
    }
}
void reverse(vi &nums,int l,int r){
    while(l < r){
        swap(nums[l],nums[r]);
        l++;
        r--;
    }
}