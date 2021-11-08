// T(n) = O(1)
// S(n) = O(1)
#include<iostream>
#include<cmath>
using namespace std;

int noOfDigits(int x){
    // @param x : integer 
    return floor(log10(x)+1);
}

int main(){
    int x;
    cout << "Enter a integer : ";
    cin >> x;
    cout << "The digits in "<<x<<" is "<<noOfDigits(x)<<endl;
    return 0;
}