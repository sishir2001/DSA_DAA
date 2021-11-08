// print all the divisors of a number 
// x*y is pair that will result in n , x <=sqrt(n),y>=sqrt(n) 
// * above is the hint to solve this problem efficiently
// T(n) = O(sqrt(n))
// S(n) = O(1)

#include<iostream>
using namespace std;

void printAllDivisors(int n){
    // 1 will always be the divisor for every number 
    cout << "1 ";

    // looping from 2 to sqrt(n)
    for(int i = 2;i*i <= n;i++){
        // modulo of n with i 
        if(n % i == 0){
            cout << i <<" ";
            // this i is x which is <= sqrt(i)
            // there will be a y which >= sqrt(i) = n/i 
            if(i != n/i){
                cout << n/i <<" ";
            }
        }
    }
}

void printAllDivisorAsc(int n){
    // printing all the divisors in ascending order 
    cout << "1 ";
    // T(n) = O(2sqrt(n))
    // S(n) = O(1)
    int i = 2;
    for(;i*i<=n;i++){
        if(n%i == 0){
            cout << i <<" "; // printing the x side of sqrt(n)
        }
    }
    i=i-1;
    for(;i>1;i--){
        if(n%i == 0 && i != n/i){
            cout << n/i <<" ";// y = n/x, which is >=sqrt(n)
        }
    }
}

int main(){
    int n; // user input 
    cout << "Enter an integer : ";
    cin >> n;
    cout << "All the divisors : ";
    printAllDivisors(n);
    cout << "\nAll the divisors(Ascending Order) : ";
    printAllDivisorAsc(n);
    return 0;
}
