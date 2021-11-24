// Extended Euclidean Algorithm 
// ? a*s + b*t = gcd(a,b)
// * This extended algo finds s,t and gcd(a,b) simultaneously 

#include<iostream>
using namespace std;
typedef long long ll;

void ExtendedEuclideanAlgo(ll a,ll b){
    // this functions prints the s,t and gcd(a,b)
    // ! for calculation of s and t , initialize s1 = 1,s2 = 0 and t1= 1,t2 = 0
    ll s1 = 1,s2 = 0,t1 = 0,t2 = 1,r = 0,s = 0,t = 0;
    while(b!=0){
        ll q = a/b; //integer division
        cout << "q : "<<q<<"\n";
        r = a%b;// 3 operations 
        s = s1 - q*s2;
        t = t1 - q*t2;
        a = b;
        b = r;
        s1 = s2;
        s2 = s;
        t1 = t2;
        t2 = t;
    }
    cout << "GCD : "<<a<<"\n";
    cout << "s : "<<s1<<"\n";
    cout << "t : "<<t1<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ExtendedEuclideanAlgo(0,45);
    return 0;
}