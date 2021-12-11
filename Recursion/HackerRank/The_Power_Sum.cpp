// https://www.hackerrank.com/challenges/the-power-sum/problem?isFullScreen=true
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
// typedef vector<ll> v_ll;

#define mod 1000000007 // 1e9+7
#define deb(x) cout << #x << " = "<<x<<"\n" // for debugging
#define deb2(x,y) cout << #x << " = "<<x << " , " << #y << " = " << y <<"\n" // for debugging 
#define FOR(a,n) for(int (a) = 0;(a) < (n);(a)++) // regular for loop

int powerSum(int x,int n,int i = 1){
    // * T(n) = O(X)
    // * S(n) = O(X^1/n)
    if(x == 0)
        return 1;
    if(x < 0 || (int)pow(i,n) > x)
        return 0;
    int count = 0;
    for(int j = i;(int)pow(j,n) <= x;j++){
        int a = x - (int)pow(j,n);
        count += powerSum(a,n,j+1);
        // deb(count);
    }
    return count ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x,n;
    cin >> x >> n;
    // deb(x);
    // deb(n);
    cout << powerSum(x,n) << "\n";
    return 0;
}
