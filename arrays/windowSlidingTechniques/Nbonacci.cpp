// print the first m numbers of Nbonacci numbers 
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

void Nbonacci(int n,int m);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,n,m;
    cin >> T;
    while(T){
        cout << "n and m :";
        cin >> n >> m;
        Nbonacci(n,m);
        cout << "\n";
        T--;
    }
    return 0;
}

// void printVector(vi nums){
//     int size = nums.size();
//     cout << "\n";
//     FOR(i,size){
//         cout << nums[i] <<" ";
//     }
// }
void Nbonacci(int n,int m){
    // * T(n) = O(m)
    // * S(n) = O(n) : auxilliary space taken by vector
    // * [0,n-2] numbers are always 0
    // * nth and n-1 th are always 1 
    vi nums;
    FOR(i,n-1){
        // from 0 to n-2
        cout << 0 << " ";
        nums.PB(0);
    } 
    cout << 1 << " ";
    nums.PB(1); // n-1 
    cout << 1 << " ";
    nums.PB(1); // n
    FOR_custom_less(i,m,n+1){
        int element = nums[n]*2 - nums[0]; // same as window sliding technique
        cout << element << " ";
        nums.PB(element);
        nums.erase(nums.begin());
    }
    // printVector(nums);
    nums.clear();
}