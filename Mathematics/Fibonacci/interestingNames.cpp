// Geeksforgeeks problem 
#include<iostream>
#include<cmath>
using namespace std;

typedef unsigned long long ll;
ll mod = 1e9+7;// scientific notation
ll *p = new ll[2]; // useful to return from the below function

void Fibo(ll n){
    if(n == 0){
        p[0] = 0;
        p[1] = 1;
        // cout << "n : "<<n<<"\n";
        // cout << "Returning p[0]:"<<"f("<<n<<"):"<<p[0]<<" p[1]:"<<"f("<<n+1<<"):"<<p[1]<<"\n";
        return ;
    }
    if(n == 1){
        p[0] = 1;
        p[1] = 1;
        // cout << "n : "<<n<<"\n";
        // cout << "Returning p[0]:"<<"f("<<n<<"):"<<p[0]<<" p[1]:"<<"f("<<n+1<<"):"<<p[1]<<"\n";
        return ;
    }
    Fibo(n/2);
    if((n&1) == 1){
        // odd 
        // here x = f(n)
        ll x = ((p[0]*p[0])%mod+(p[1]*p[1])%mod)%mod;
        // here y = f(n+1)
        ll y = (p[1]*(((2*p[0])%mod+p[1]))%mod)%mod;
        p[0] = x;
        p[1] = y;
    }
    else{
        // even 
        // here y = f(n+1)
        ll y = ((p[0]*p[0])%mod+(p[1]*p[1])%mod)%mod;
        // here x = f(n)
        ll x = (p[0]*(((2*p[1])%mod-p[0]))%mod)%mod;
        p[0] = x;
        p[1] = y;
    }
    // cout << "n : "<<n<<"\n";
    // cout << "Returning p[0]:"<<"f("<<n<<"):"<<p[0]<<" p[1]:"<<"f("<<n+1<<"):"<<p[1]<<"\n";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    ll n;
    cin >> T;
    while(T){
        cin >> n;
        // need to find sum of fibonacci numbers 
        // ! Here count(n)=fib(n+2)
        // So sum(n) = fib(n+4)-3
        Fibo(n+4);
        ll res = (p[0]-3)%mod;
        cout << res <<"\n";
        p[0] = 0;
        p[1] = 0;
        T--;
    }
    return 0;
}