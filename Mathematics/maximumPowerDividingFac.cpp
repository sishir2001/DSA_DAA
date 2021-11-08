// Find out the maximum power of a number dividing a factorial 
// !fun(2,5) -> what is the maximum powet of 2 that divides 5! = 8 = 2^3 = output = 3

#include<iostream>
using namespace std;
int largestPrimeFactor(int n){
    // ! gives wrong answer when n has only one prime factor -> perfect exponent of a prime !
    // if n is prime -> largestPrimeFactor = n
    int primeFac = 0;
    cout <<endl<< " n : "<<n<<endl;
    if(n == 2|| n == 3){
        return n;
    }
    if(n%2 == 0){
        primeFac = max(primeFac,2);
        cout << endl << "n%2 PrimeFac "<<primeFac << endl;
    }
    if(n%3 == 0){
        cout << endl << "n%3 B PrimeFac "<<primeFac << endl;
        primeFac = max(primeFac,3);
        cout << endl << "n%3 A PrimeFac "<<primeFac << endl;
    }
    cout << "Before loop n : "<<n<<endl;
    for(int i = 5;i<=n/2;i=i+6){
        // * prime factors will be of the form 6i-1 and 6i+1 
        cout << endl <<"Inside loop"<<endl;
        if(n%i == 0){
            primeFac = max(primeFac,i);
            cout << endl << "PrimeFac "<<primeFac << endl;
        }
        if(n%(i+2) == 0){
            primeFac = max(primeFac,i+2);
            cout << endl << "PrimeFac "<<primeFac << endl;
        }
    }
    cout << endl << "PrimeFac "<<primeFac << endl;
    return primeFac == 0 ? n : primeFac;
}
int maxPowerDivFacEffi(int n,int f){
    // if n is prime , implement Legendres formula for larges power dividing the factorial 
    // Legendres formula : floor(f/n)+floor(f/n^2)+ .... 0 if n = prime
    // floor(f/x)+floor(f/x^2)+ .... 0 if n = composite , where x is the largest prime divisor 
    // * No overflow case due as we dont calculate the factorial here 
    // ? T(n) = O(n^1/2 + log(n)) -> finding whether n is prime or not + applying legendre's formula 
    // ? S(n) = O(1)

    // check whether n is prime or composite 
    // A function that returns the largest prime divisor 
    int maxPrimeFac = largestPrimeFactor(n);
    cout <<endl<< "Largest Prime Factor for "<<n<<" : "<<maxPrimeFac<<endl;
    // applying legendre's formula 
    int res = 0,primeFac = maxPrimeFac;
    while(maxPrimeFac <= f){
        res += f/maxPrimeFac;
        maxPrimeFac *= primeFac;
    }
    return res;
}
int maxPowerDivFac(int n,int f){
    // @param n : base to for that calculation of power
    // @param f : calculate the factorial of this number 
    // T(n) = O(n)
    // S(n) = O(1)
    long long res = 1;
    int count = 0,l = n;
    for(int i =2;i<=f;i++){

        res*=i;
        if(res%n == 0){
            count++;
            n*=l;
        }
    }
    return count;
}

int maxPowDivFacNaive(int n,int f){
    // calculate the factorial
    // T(n) = O(n + exp)
    // S(n) = O(1)
    unsigned long long fac = 1;
    for(int i = 2;i<=f;i++){
        fac = fac*i;
    }
    // calculate the greatest power of n that divides fac
    int count = 0,l = n;
    while(fac%n == 0){
        count ++;
        n*=l;
    }
    return count ;
}

int main(){
    int n,f ;
    cout <<"Enter n and f :";
    cin >> n >> f;
    cout << "The maximum power of "<<n<<" that divides "<<f<<"! :"<<maxPowerDivFac(n,f)<<endl;    
    cout << "Naive solution, The maximum power of "<<n<<" that divides "<<f<<"! :"<<maxPowDivFacNaive(n,f)<<endl;    
    cout << "Efficient solution,applying legendre's formula, The maximum power of "<<n<<" that divides "<<f<<"! :"<<maxPowerDivFacEffi(n,f);    
    return 0;
}