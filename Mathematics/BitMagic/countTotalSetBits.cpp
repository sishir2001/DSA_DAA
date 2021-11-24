// ? GFG problem 
//! find the sum of total set bits from [1-A]
// * If n is of the form 2^n then sum of bits from 1 to that number including = n*(2^(n-1))+1

#include<iostream>
#include<cmath>
using namespace std;

// typedef long long ll;

int powerTwoSumDigits(int k){
    // !T(n) = O(1)
    // k no of digits in the binary representation of the number 
    return k*pow(2,k-1)+1;
}

int sumDigits(int n){
    // ! Required T(N) = O(logN)
    // ! TLE 
    // T(N) = O(n)
    // ? find the nearest k 
    int k = log2(n);
    int l = pow(2,k),h = pow(2,k+1);
    int dl = n - l,dh = h - n;
    int a = (dl <= dh)?k:k+1;
    int sum = powerTwoSumDigits(a); // for the nearest k
    if(a == k){
        for(int i = l+1;i<=n;i++){
            int j = i;
            // Standard algo for finding no of one's 
            while(j){
                sum++;
                j = j&(j-1);
            }
        }
    }
    else if(a == k+1){
        for(int i = h;i > n;i--){
            int j = i;
            // Standard algo for finding no of one's 
            while(j){
                sum--;
                j = j&(j-1);
            }
        }
    }
    else{
        cout <<"Function : sumDigits : Conditions not matching \n";
    }
    return sum ;
}

int sumDigitsEffi(int n){
    // T(n) = O(logn)
    // Just traverse the binary representation of n
    int sum = 0;
    for(int i = 0;(1 << i) <= n;i++){
        int a = 1 << i,b = 1 <<(i+1);
        int alpha = n/a; // integer division
        sum = sum + a*(n/b);
        if((alpha&1) == 1){
            // if alpha is odd 
            sum = sum + (n%a) +1;
        }
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin >> t;
    while(t--){
        cout <<"Enter n : ";
        cin >> n;
        cout << sumDigitsEffi(n)<<"\n";
        cout << sumDigits(n)<<"\n";
    }
    return 0;
}
