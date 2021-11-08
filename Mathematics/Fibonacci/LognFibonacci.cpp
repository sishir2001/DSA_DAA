// Better implementation of finding a fibonnaci number based on the index 

// * if n = even F(n) = F(n/2){2*F((n/2)+1) - F(n/2)}
// * if n = odd F(n) = F(n/2)^2 + F((n/2)+1)^2

// ? T(N) = O(log(n))
// ? S(N) = O(log(n))

#include<iostream>
using namespace std;

typedef long long ll;

ll *p = new ll[2]; // useful to return from the below function

ll *logNFibo(ll n){
    if(n == 0){
        p[0] = 0;
        p[1] = 1;
        // cout << "n : "<<n<<"\n";
        // cout << "Returning p[0]:"<<"f("<<n<<"):"<<p[0]<<" p[1]:"<<"f("<<n+1<<"):"<<p[1]<<"\n";
        return p;
    }
    if(n == 1){
        p[0] = 1;
        p[1] = 1;
        // cout << "n : "<<n<<"\n";
        // cout << "Returning p[0]:"<<"f("<<n<<"):"<<p[0]<<" p[1]:"<<"f("<<n+1<<"):"<<p[1]<<"\n";
        return p;
    }
    logNFibo(n/2);
    if((n&1) == 1){
        // odd 
        // here x = f(n)
        ll x = p[0]*p[0]+p[1]*p[1];
        // here y = f(n+1)
        ll y = p[1]*(2*p[0]+p[1]);
        p[0] = x;
        p[1] = y;
    }
    else{
        // even 
        // here y = f(n+1)
        ll y = p[0]*p[0]+p[1]*p[1];
        // here x = f(n)
        ll x = p[0]*(2*p[1]-p[0]);
        p[0] = x;
        p[1] = y;
    }
    // cout << "n : "<<n<<"\n";
    // cout << "Returning p[0]:"<<"f("<<n<<"):"<<p[0]<<" p[1]:"<<"f("<<n+1<<"):"<<p[1]<<"\n";
    return p;
}

//Naive implementation of fibonacci code 
// T(N) = O(n)
ll naiveFibo(ll n){
    // looping 
    ll a = 0,b= 1,res = 0;
    for(ll i = 2;i<=n;i++){
        res = a+b;
        a = b;
        b = res;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // @param n : no of testcases 
    ll n;
    cin >>n;
    ll arr[n];
    for(ll i = 0;i<n;i++){
        cin >> arr[i];
    }
    // * Stress testing the lognFibo with naiveFibo
    for(ll i= 0;i<n;i++){
        logNFibo(arr[i]);
        ll x = p[0];
        ll y = naiveFibo(arr[i]);
        if(x != y){
            cout << "Stress Test Failed !!";
            return 0;
        }
    }
    cout << "Stress Test Passed !!";
    return 0;
}