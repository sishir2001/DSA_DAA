// find the maximum no of cuts to a rope 

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
// typedef vector<ll> v_ll;

#define mod 1000000007 // 1e9+7
#define deb(x) cout << #x << " = "<<x<<"\n" // for debugging
#define deb2(x,y) cout << #x << " = "<<x << " , " << #y << " = " << y <<"\n" // for debugging 
#define FOR(a,n) for(int (a) = 0;(a) < (n);(a)++) // regular for loop

int ropeCutting(int n,int a,int b,int c){

    // I think this is the naive solution 
    // Will be a recursion tree
    // !T(n) = ?
    // !S(n) = ?
    if(n == 0)
        return 0;
        
    int mi = min(a,b,c); // mi : minimum
    if(n < 0 || n < mi)
        return -1;
    
    int rem = n % mi; // rem : remainder 
    if(rem == 0)
        return n/mi;
    
    int res_a = ropeCutting(n-a,a,b,c);
    int res_b = ropeCutting(n-b,a,b,c);
    int res_c = ropeCutting(n-c,a,b,c);

    int res = max(res_a,res_b,res_c); // res : result 
    if(res == -1)
        return -1;
    return res+1;// +1 for current cutting of the rope
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,n,a,b,c;
    cin >> T;

    while(T){
        cin >> n >> a >> b >> c;
        cout << ropeCutting(n,a,b,c)<<"\n";
        
        T--;
    }
    return 0;
}
