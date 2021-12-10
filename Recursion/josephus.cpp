// josephus problem

#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
// typedef vector<ll> v_ll;

#define mod 1000000007 // 1e9+7
#define deb(x) cout << #x << " = "<<x<<"\n" // for debugging
#define deb2(x,y) cout << #x << " = "<<x << " , " << #y << " = " << y <<"\n" // for debugging 
#define FOR(a,n) for(int (a) = 0;(a) < (n);(a)++) // regular for loop

int jos(int n,int k){
    // !T(N) = O(N)
    // !S(N) = O(N)
    // think each sub-problem as different problem 
    if(n == 1)
        return 0;

    return (jos(n-1,k)+k)%n;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,n,k;
    cin >> T;
    while(T){
        cin >> n >> k;
        cout << jos(n,k) << "\n";
        T--;
    }
    return 0;
}
