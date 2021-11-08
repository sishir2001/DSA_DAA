// Count binary string with no two consecutive 1's
// Gfg's problem 
// I/P : n = 3
// O/P : 5 , check binary numbers till < 2^3
// * This is also a fibonacci sequence , starting with f(0) = 1 , f(1) = 2;

#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef vector<ll> v_ll;

// * GLobal Vector
v_ll fibo_vector;
ll countBinaryStringsWithoutNoConsecOne(ll n){
    // *T(N) = O(n)
    // *S(n) = O(n) -> for vector and stack with recursion
    // solving using recursion 
    // dynamic programming using vector
    if(n < 0){
        return -1;
    }
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return 2;
    }
    ll res = 0;
    if(n-2 < fibo_vector.size()){
        // the element is inside the vector 
        res = fibo_vector[n-2];
    }
    else{
        res = countBinaryStringsWithoutNoConsecOne(n-2)+countBinaryStringsWithoutNoConsecOne(n-1);
        fibo_vector.push_back(res);
    }
    return res;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    cout << "The number of binary strings with non-consecutive 1's :"<<countBinaryStringsWithoutNoConsecOne(n)<<"\n";
    return 0;
}