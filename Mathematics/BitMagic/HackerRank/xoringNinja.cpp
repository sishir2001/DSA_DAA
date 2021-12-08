
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

typedef long l;
typedef vector<int> v_l;
l mod = 1000000007;

int xoringNinja(v_l vect){
    // T(n) = O(2^n*log(n))
    int n = vect.size();
    int j = pow(2,n)-1; 
    int sum = 0;
    // cout << "j : "<<j<<"\n";
    for(int i = 1;i<=j;i++){
        int k = i,a = 1,res = 0,b = 0;
        while(a <= k){
            if((a&k) == a){
                // bth bit is set 
                res = res^vect[b];
            }
            b++;
            a = a << 1;
        }
        // cout << "res : "<<res<<"\n";
        sum += (res % mod);
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x;
    cin >> t;
    while(t--){
        cin >> n;
        v_l vect;
        for(int i = 0;i<n;i++){
            cin >> x;
            vect.push_back(x);
        }
        cout << xoringNinja(vect)<<"\n";
        vect.clear();
    }
    return 0;
}