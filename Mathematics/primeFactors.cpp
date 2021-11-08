// prime factorization of a number 
// T(n) = O(log2(n)+n^1/2)
// S(n) = O(1)

#include<iostream>
using namespace std;

void printPrimeFactors(int x){
   // !Imp point to note : Prime numbers will of the form 6i-1 | 6i+1
   while(x!= 0 && x%2 == 0){
       cout << 2 <<" ";
       x = x/2;
   } 
   while(x!= 0 && x%3 == 0){
       cout << 3 <<" ";
       x = x/3;
   } 
   for(int i = 5;i*i<=x;i=i+6){

       while(x!= 0 && x%i == 0){
           cout << i <<" ";
           x = x/i;
       } 

       while(x!= 0 && x%(i+2) == 0){
           cout << i+2 <<" ";
           x = x/(i+2);
       } 
   }
   if(x > 3){
       cout << x <<" "<<endl;
   }
}

int main(){
    int x;
    cout << "Enter an integer : ";
    cin >> x;
    cout << "Prime factors : ";
    printPrimeFactors(x);
    return 0;
}