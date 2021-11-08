// There is one new born cow initially 
// Every cow can reproduce one cow after two years and then one every year 
// ! Find the number of cows at the end of nth year

// * DudneysCow(n) = Fib(n); 
// T(n) = O(2^n) // time complexity of fibonacci implementation
// S(n) = O(n)

#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef vector<ll> v_ll;

v_ll fibo_vector;
ll fibonacci(ll n){
    // Dynamic programming 
    // f(0) = 0
    // f(1) = 1
    // f(2) = 1
    if(n < 0){
        return -1;
    }
    if(n == 0 || n == 1){
        return n;
    }
    ll res = 0;
    // checking whether the value of n exists in vector 
    if(n-2 < fibo_vector.size()){
       res = fibo_vector[n-2]; 
    }
    else{
        // calculate the result 
        res = fibonacci(n-2)+fibonacci(n-1);
        fibo_vector.push_back(res);
    }
    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    cout << "Number of Dudney cow's end of "<<n<<" years : "<<fibonacci(n);
    return 0;
}
