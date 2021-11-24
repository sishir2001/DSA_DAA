// GFG 
#include<iostream>
using namespace std;

typedef unsigned int ui;

ui swapEvenOddBits(ui n){
    ui a = 3,i = 0;
    while(i < 32){
        if(((n&a) != 0) && ((n&a) != a)){
            n = n^a;
        }
        a = a<<2;
        i = i+2;
    }
    return n;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ui n;
    cin >> n;
    cout << swapEvenOddBits(n);
    return 0;
}