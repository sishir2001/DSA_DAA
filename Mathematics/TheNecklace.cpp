// Circular permutations : (n-1)!/2
// no of trailing zeroes doesnt change if we divide by 2

// *T(n) = O(log5(n))
// *S(n) = O(1)

#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T,n;
    cin >> T;
    
    while(T){
        cin >> n;
        ll x = 5,res = 0,N = n-1;
        while(N >= x){
            res += N/x;
            x *= 5;
        }
        cout << res << "\n";

        T--;
    }
    return 0;
}
