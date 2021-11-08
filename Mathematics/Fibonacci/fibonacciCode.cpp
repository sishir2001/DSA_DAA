// * Fibonacci is a complete sequence 
// ? Any number can expressed as a sum of fibonacci numbers (no fibonacci number is repeated )

#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> v_ll;
typedef vector<ull> v_ull;


ull fibonacciCode(ull x){
    // @param x : calculate the fibonacci code for the number 
    // * Algo : Find the a fibonacci number smaller than x and y = x - fibonum . 
    // * Eg = 4 = 1+3 = 1011 , the last 1 is for termination 
    // Recursive solution 
    if(x <= 0)
        return -1;

    ull f0 = 0,f1 = 1,res = 0;
    v_ull fibo_vector;
    while(res < x){
        res = f0+f1;
        f0 = f1;
        f1 = res;
        fibo_vector.push_back(res);
    }
    // cout << "res : "<<res<<" f0 : "<<f0<<" f1 : "<<f1<<" x : "<<x<<"\n";
    // printing the vector 
    // for(ull &i : fibo_vector){
    //     cout << i <<" ";
    // }
    // cout <<"\n";
    if(res == x){
        // check for res occuring in fibonacci sequence 
        for(ull i=0;i<fibo_vector.size();i++){
            if(fibo_vector[i] == res){
                cout << 1 ;
                return i+1;
            }
            cout << 0 ;
        }
    }
    else if(res > x){
        ull y = x - f0;
        // ! we dont know for sure , whether y is fibonacci or not 
        ull lowerBound = fibonacciCode(y);
        // find for y and f0 in the vector
        for(ull i = lowerBound;i<fibo_vector.size();i++){
            if(fibo_vector[i] == f0){
                cout << 1 ;
                return i+1;
            }
            else{
                cout << 0 ;
            }
        }
    }
    return -1;
}

int main(){
    // for I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ull x;
    cin >>x ;
    fibonacciCode(x);
    cout << 1 << "\n";
    return 0;
}