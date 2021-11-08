// print all the prime numbers less than or equal to n
// sieve of eratothenes 

#include<iostream>
#include<vector>
using namespace std;

 void sieveOfEratothenes(int n){
     // this is a simple implementation of sieve algorithm 
     // initializing a vector 
     vector<bool> isPrime(n+1,true); // initiliazing of a vector
     for(int i = 2;i*i<=n;i++){
         if(isPrime[i]){
             for(int j = i*i;j<n+1;j=j+i){
                 if(j%i == 0){
                     isPrime[j] = false;
                 }
             }
         }
     }
     // printing all the prime numbers below n
     cout << endl;
     for(int i = 2;i<=n;i++){
         if(isPrime[i] == true){
             cout << i <<" ";
         }
     }
 }
int main(){
    int n;
    cout << "Enter the integer : ";
    cin >> n;
    cout << "All the prime numebers below "<<n<<" : ";
    sieveOfEratothenes(n);
    return 0;
}