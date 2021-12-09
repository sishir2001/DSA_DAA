// Palindrome check using recursion 
#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
// typedef vector<ll> v_ll;

#define mod 1000000007 // 1e9+7
#define deb(x) cout << #x << " = "<<x<<"\n" // for debugging
#define deb2(x,y) cout << #x << " = "<<x << " , " << #y << " = " << y <<"\n" // for debugging 
#define FOR(a,n) for(int (a) = 0;(a) < (n);(a)++) // regular for loop

bool isPalindrome(string &s,int l,int r,int c = 0){
    // !T(n) = O(n)
    // !S(n) = O(n)
    // & alias operator, for not copying the string again and again 
    // string s : string on which palindrome needs to be checked c
    // l : must be 0 for initial call
    // r : must be s.size()-1 for initial call
    // c : for count on recursion

    // ** corner cases
    // for an empty string 
    if(s.size() == 0)
        return true;

    // for an single char string 
    if(s.size() == 1)
        return true;
    // ** corner cases

    // l and r not in the required range
    if(!(l >= 0 && l < s.size() && r >= 0 && r < s.size()))
        return false;

    // wrong case provided
    if(c == 0 && l > r)
        return false;

    if(l > r)
        return true;

    if(s[l] != s[r])
        return false;

    // only if its true
    return isPalindrome(s,l+1,r-1,c+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    deb(true);
    deb(false);
    // int T;
    // cin >> T;
    // while(T){


    //     T--;
    // }
    // cout << isPalindrome("abca",0,3) << "\n";
    string s = "a";
    cout << isPalindrome(s,0,0)<< "\n";
    return 0;
}
