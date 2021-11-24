// Hackerrank - XOR sequence 

#include<iostream>
using namespace std;

long getXORelement(long i){
    long res = 0;
    if(i%4 == 0)
        res =  i;
    if(i%4 == 1)
        res = 1;
    if(i%4 == 2)
        res = i+1;
    if(i%4 == 3)
        res = 0;
    return res;
}
long xorSequence(long l,long r){
    // !TLE 
    // T(n) = O(n)
    // ! Required T(n) = O(1)
    long res = 0,i = 0;
    if((l&1) == (r&1)){
        // both l and r have same LSB
        res = getXORelement(l);
        i = l+2;
    }
    else{
        // both l and r have different LSB 
        res = l+1;
        i = l+3;
    }
    // for(;i<=r;i=i+2);
    // }
    while(i <= r){
        res = res ^ i;
        i = i+2;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long t,l,r;
    cin >> t;
    while(t--){
        cin >> l >> r;
        cout << xorSequence(l,r)<<"\n";
    }
    return 0;
}