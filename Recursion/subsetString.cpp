// generate subsets of a string 
// if string length is n , then there will be 2^n subsets 

#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
// typedef vector<ll> v_ll;

#define mod 1000000007 // 1e9+7
#define deb(x) cout << #x << " = "<<x<<"\n" // for debugging
#define deb2(x,y) cout << #x << " = "<<x << " , " << #y << " = " << y <<"\n" // for debugging 
#define FOR(a,n) for(int (a) = 0;(a) < (n);(a)++) // regular for loop

void subsetsString(string &s,int i = 0,string res = ""){
    // !T(N)= O(2^n)
    // !S(N)= O(n)
    if(i == s.size()){
        cout << res <<"\n";
        return;
    }
    // left branch of tree
    subsetsString(s,i+1,res);
    // right branch of tree
    subsetsString(s,i+1,res+s[i]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    string s;
    cin >> T;
    while(T){
        cin >> s;// taking input of string
        subsetsString(s);
        T--;
    }
    return 0;
}
