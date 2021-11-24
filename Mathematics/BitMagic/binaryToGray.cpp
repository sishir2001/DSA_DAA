// Given a number , return with Gray equivalent of it 
// Basically binary to gray code 
// ! Gn = Gb ^ (Gb/2) , integer division

#include<iostream>
using namespace std;

int binaryToGray(int n){
    // !T(n) = thetha(1)
    return n ^ (n/2); // integer division
}
int GrayToBinary(int n){
    if(n == 0||n == 1)
        return n;
    int a = n >> 1;
    int res = n >> 1;
    while(a != 1){
        res = res ^ n;
        res = res >> 1;
        a = a >> 1;
    }
    res = res ^ n;
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout <<"BinaryToGray : "<< binaryToGray(n) <<"\n";
    cout <<"GrayToBinary : "<< GrayToBinary(n);

    return 0;
}