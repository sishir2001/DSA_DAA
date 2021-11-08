// count set bits in a number 
#include<iostream>
using namespace std;

typedef long long ll;

int countSetBitsBetter(int n){
    // * Brian Kerningam's Algorithm
    // ? Standard Algorithm
    int count = 0;
    while(n){
        count ++;
        n = n&(n-1);// unsets the last most set bit
    }
    return count;
}
// Lookup method
// 256 - 1 byte - 8 bits 
int table[256];
void initializeTable(){
    table[0] = 0;
    for(int i = 1;i<256;i++){
        table[i] = (i&1) + table[i/2];
    }
}
int countSetBitsBest(int n){
    // !T(n) = theta(1)
    // !S(n) = Theta(256*4)
    initializeTable();

    int res = table[(n&255)]; // 0-7 bits 
    n = n>>8;
    
    res += table[(n&255)]; // 8-15 bits 
    n = n>>8;

    res += table[(n&255)];// 16-23 bits
    n = n>>8;

    res += table[(n&255)];// 24-31 bits
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; // 32 bits 
    cin >> n;
    cout << "Count set bits(better): "<<countSetBitsBetter(n)<<"\n";
    cout << "Count set bits(best): "<<countSetBitsBest(n)<<"\n";
    return 0;
}