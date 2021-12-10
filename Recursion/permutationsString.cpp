// find all the permutations of a string 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
// typedef vector<ll> v_ll;

#define mod 1000000007 // 1e9+7
#define deb(x) cout << #x << " = "<<x<<"\n" // for debugging
#define deb2(x,y) cout << #x << " = "<<x << " , " << #y << " = " << y <<"\n" // for debugging 
#define FOR(a,n) for(int (a) = 0;(a) < (n);(a)++) // regular for loop

void permutation(string s,int i=0){
    //* T(n) = O(n^2)
    //* S(n) = O(n)

    int n = s.size(); // size of the string 
    if(i >= n){
        cout << s << "\n";
        return;
    }
    for(int j = i;j<n;j++){
        swap(s[i],s[j]);
        permutation(s,i+1);
        swap(s[i],s[j]); // bringing back to its original form 
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    string s;
    cin >> T;
    while(T){
        cin >> s;
        cout << "Permutations : \n";
        permutation(s);
        T--;
    }
    return 0;
}
