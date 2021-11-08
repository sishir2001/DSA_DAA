// S(N) = O(1)
// more efficient soln than O(n^1/2) for larger primes 
#include<iostream>
using namespace std;

bool isPrime(int x){
    // @param : x : integer 
    bool res = true;
    // first check whether x == 1
    if(x == 1){
        res = false;
    }
    else if(x == 2 || x == 3){
        // need to explicitly check for these two cases 
        res = true;
    }
    else if(x%2 == 0){
        // 2 is the only even prime , checks for all even numbers 
        res = false;
    }
    else if(x%3 == 0){
        res = false;
    }
    else{
        for(int i = 5;i*i<=x;i=i+6){
            // checking with x%i
            if(x%i == 0 || x%(i+2) == 0){
                res = false;
                break;
            }
        }
    }
    return res;
}


int main(){
    int x;// input from the user 
    cout << "True : "<<true<<" and False : "<<false<<endl;
    cout << "Enter a integer : ";
    cin >> x;
    cout << "The primality test of "<< x <<" : "<<isPrime(x)<<endl;
    return 0;
}