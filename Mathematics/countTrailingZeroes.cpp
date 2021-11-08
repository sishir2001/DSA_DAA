// count no of trailing zeroes for a factorial 
// T(n) = O(log5(n))
// S(n) = O(1)
#include<iostream>
using namespace std;

int countTrailingZeroes(int x){
    // @param x : count trailing zeroes in x!
    int n = 5;
    int res = 0;
    while(x >= n){
        res = res + x/n;
        n = n*n;
    }
    return res;
}

int main(){
    int x; // input number 
    cout << "Enter an integer : ";
    cin >> x;
    cout << "The trailing zeroes of "<<x<<"! are : "<<countTrailingZeroes(x)<<endl;
    return 0;
}