// link : https://www.geeksforgeeks.org/copy-set-bits-in-a-range/

#include<iostream>
using namespace std;

int copySetBitsRange(int x,int y,int l,int r){
    // T(n) = O(n)
    // cout << x << y << l << r <<"\n";
    int a = 1<<(l-1),res = 0;
    for(int i = l;i<=r;i++){
        res = res + (a&y);
        // cout <<"res : "<< res << "\n";
        a = a << 1;
    }
    return res^x;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y,l,r;
    cin >> x >> y >> l >> r;
    cout << copySetBitsRange(x,y,l,r);
    return 0;
}