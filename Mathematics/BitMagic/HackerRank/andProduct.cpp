// Find bitwise AND for [a,b]

#include<iostream>
using namespace std;

long countOnes(long x,long y,long n){
    long res = 0,alpha = n/x;
    res = x*(n/y);
    if((alpha&1)==1){
        // alpha odd 
        res = res + (n%x)+1;
    }
    return res;
}
long andProduct(long a, long b){
    // a <= b
    if(b-a == 1)
        return a&b;
    long c = 1,res = 0;
    while(c <= b){
        if((a&c) && (b&c)){
            long ca = countOnes(c,c<<1,a);
            long cb = countOnes(c,c<<1,b);
            // cout << "ca : "<<ca<<" cb : "<<cb<<"\n";
            if(cb-ca == b-a)
                res = res+c;
        }
        c = c << 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n,a,b;
    cin >> n;
    while(n--){
        cin >> a >> b;
        cout << andProduct(a,b)<<"\n";
    }
    return 0;
}