// Find modulo by m of nth fibonnaci number 
// ! fib(n)%m is extremely is expensive as for n > 100 . fib(n) will have larger number than long long . There will be overflow
// * Using Pisano's Period to find the modulo 
// ? for m > 0 , there will be a sequence of fib%m that will be repeated 

#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef vector<ll> v_ll;

v_ll fib;
ll pisanoPeriod(ll m){
    // ! Optimization needed in terms of time 
    // T(n) = O(n^2)
    // S(n) = O(n^2)
    // initialization 
    fib.push_back(0);
    fib.push_back(1);
    fib.push_back(1);

    for(ll i = 3;i<=m*m;i++){
        fib.push_back((fib[i-1]+fib[i-2])%m);
        if(fib[i] == 0){
            // check for the next element
            ll next = (fib[i-1]+fib[i])%m;
            if(next == 1){
                // sequence detected
                // cout << "Sequence Detected !\n";
                return i;
            }
        }
    }
    return -1;
    // ? End 
}
ll fibModM(ll n,ll m){

    // ? calculating pisono's period 
    ll p = pisanoPeriod(m);
    if(p == -1){
        cout << "Pisano's Period Not detected \n";
        return -1;
    }
    n = n%p;
    return fib[n]%m;
}
// !For stress testing 
ll arr[] = {0,1};
ll *fibFunction(ll n){
    //logn implementation 
    // T(n) = O(logn)
    if(n == 0){
        arr[0] = 0;
        arr[1] = 1;
        return arr;
    }
    if(n == 1){
        arr[0] = 1;
        arr[1] = 1;
    }
    fibFunction(n/2);
    // global arr might be changed 
    ll x = 0,y = 0;
    if((n&1) == 0){
        // even 
        // x = f(n)
        x = arr[0]*(2*arr[1]-arr[0]);
        // y = f(n+1)
        y = arr[0]*arr[0]+arr[1]*arr[1];
    }
    else{
        // odd
        x = arr[0]*arr[0]+arr[1]*arr[1];
        y = arr[1]*(2*arr[0]+arr[1]);
    }
    arr[0] = x;
    arr[1] = y;
    return arr;
}
ll StressTest(ll n,ll m){
    // ! Overflow may happen in this 
    return fibFunction(n)[0]%m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ll m,n;
    // cin >> n >> m;
    // checking the test cases
    ll narr[] = {10,12,14,15,11,16},marr[] = {4,5,7,25,3};
    for(ll i = 0;i<6;i++){
        // narr
        for(ll j = 0;j<5;j++){
            // clearing the vector
            fib.clear();
            if(fibModM(narr[i],marr[j]) == StressTest(narr[i],marr[j])){
                cout << "Passed for n : "<<narr[i]<<" m :"<<marr[j]<<"\n";
            }
            else{
                cout << "Failed for n : "<<narr[i]<<" m :"<<marr[j]<<"\n";
            }
        }
    }

    return 0;
}