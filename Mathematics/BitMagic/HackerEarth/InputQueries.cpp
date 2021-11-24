// HackerEarth 

#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
ll navieSolution(ll l,ll r,ll k){
    ll m = 0;
    for(ll i = l;i<=r-k+1;i++){
        ll tem = i;
        for(ll j = i+1;j<=i+k-1;j++){
            tem = tem&j;
        } 
        m = max(m,tem);
    }
    return m;
}

ll maxAndSubset(ll l,ll r,ll k){
    // T(n) = O(n)
    if(k == 1)
        return r;
    ll m = 0;
    for(ll i = l;i <= r-k+1;i++){
        m = max(m,(i&(i+k-1)));
    }
    return m;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll q,l,r,k;
    cin >> q;
    while(q--){
        cin >> l >> r >> k;
        cout << maxAndSubset(l,r,k)<<"\n";
        cout << navieSolution(l,r,k)<<"\n";
    }
    return 0;
}