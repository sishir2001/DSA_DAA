// * GFG practice problem 

#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;
typedef long long ll;

unordered_map<ll,ll> umap;
ll StepsToZero(ll n){
    // !wrong algo
    ll count = 0;
    while(n){
        // inserting n to unordered map
        umap[n] = 1;
        ll a = n,b = n; // for first and second steps
        // first step 
        ll x = a&(~(a-1)); // for the right most set bit
        a = a^(x<<1); 
        // second step 
        b = b^1;// toggling the last bit 
        if(umap.find(a) != umap.end()){
            // a exists in umap
            n = b;
        }
        else if(umap.find(b) != umap.end()){
            // b exists in umap
            n = a;
        }
        else{
            // both a and b does not exist in umap
            n = min(a,b);
        }
        count ++;
        cout << count << "\n";
    }
    return count;
}

ll grayToBinary(ll n){
    // convert grey to binary to get the result 
    if(n == 0 || n == 1)
        return n;
    ll b = n>>1;
    for(ll i = n>>1;i!=1;i=i>>1){
        b = b^n;
        b = b>>1;
    }
    b = b ^ n;
    return b;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n;
    cin >> t;
    while(t){
        cin >> n;
        // cout << StepsToZero(n)<<"\n";
        cout << grayToBinary(n)<<"\n";
        t--;
    }
    return 0;
}
