// Solving diphotane equations using extended euclidean algorithm 
// ax+by = c
#include<iostream>
using namespace std;
typedef long long ll;

ll s_sol = 0,t_sol = 0;
ll gcd(ll a , ll b){
    while(b){
        ll r = a%b;
        a = b;
        b = r;
    }
    return a;
}
void extendedEuclid(ll a,ll b){
    
    ll s = 0,t = 0,s1 = 1,s2 =0 ,t1 = 0,t2 = 1;
    while(b!=0){
        ll q = a/b;
        ll r = a%b;
        a = b;
        b = r;
        s = s1 - q*s2;
        t = t1 - q*t2;
        s1 = s2;
        s2 = s;
        t1 = t2;
        t2 = t;
    }
    s_sol = s1;
    t_sol = t1;
}
void diphotane(ll a,ll b,ll c){
    ll d = gcd(a,b);
    if(c%d == 0){
        // has infinite solutions , need to find particular solution
        cout << "The equation has infinite solution "<<"\n";
        ll a1 = a/d,b1 = b/d,c1 = c/d;
        // finding solution for a1*s+b1*t = 1 , s and t
        extendedEuclid(a1,b1);
        // now s_sol and t_sol are s and t
        cout <<"x0 : "<<(c/d)*s_sol<<" y0:"<<(c/d)*t_sol<<"\n";

    }
    else{
        cout << "The equation has no solution "<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,c;
    cout << "Enter values : ";
    cin >> a >> b >> c;
    diphotane(a,b,c);
    return 0;
}