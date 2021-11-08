// ! need optimization 
// GFG problem - 2 points 
#include <iostream>
#include<cmath>
using namespace std;
unsigned long long mod = pow(10,9)+7;

long long easySeq(int N){
    // cout << "Mod : "<<mod<<"\n";
    // recursion : easySeq(N) = easySeq(N-1)(easySeq(N-1) - 1) + 1
    // ! T(N) = O(N)
    // ! S(N) = O(N)
    if(N == 0){
        return 2;
    }
    
    long long y = easySeq(N-1)%mod;
    return (y*(y-1)+1)%mod; 
}
int main() {
	//code
    // * for faster input and output 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T;
	cin >> T;
	while(T){
	    int N;
	    cin >> N;
	    cout << easySeq(N) <<"\n";
	    T--;
	}
	return 0;
}