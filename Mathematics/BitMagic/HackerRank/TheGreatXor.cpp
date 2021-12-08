// find x^a > x , where 0 < a < x
#include<iostream>
using namespace std;

typedef long l;

l theGreatXOR(l x){
    // !T(n) = O(log(n))
    // we just need to traverse the binary form of x 
    l a = 1,res = 0;
    while(a < x){
        if((a&x) == 0){
            res += a;
        }
        a = a << 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    l q,x;
    cin >> q;
    while(q--){
        cin >> x;
        cout << theGreatXOR(x) << "\n";
    }
    return 0;
}