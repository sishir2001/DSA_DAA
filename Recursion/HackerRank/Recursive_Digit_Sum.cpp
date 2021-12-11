
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
// typedef vector<ll> v_ll;

#define mod 1000000007 // 1e9+7
#define deb(x) cout << #x << " = "<<x<<"\n" // for debugging
#define deb2(x,y) cout << #x << " = "<<x << " , " << #y << " = " << y <<"\n" // for debugging 
#define FOR(a,n) for(int (a) = 0;(a) < (n);(a)++) // regular for loop

int sumofString(int n){
    int sum = 0;
    // summing the string
    while(n){
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int superDigit(string &n,int k){
    // ! Not passing test cases for larger strings 

    int32_t size = n.size();
    if(k == 1 && size == 1)
        return stoi(n);
        
    // string can larger than the space for an integer 
    int32_t num = 0,sum = 0;
    if(size <= 8){
        num += stoi(n);
        sum += sumofString(num);
    }
    else{
        sum += n[0] - 48;
        int32_t l = 1,r = 7;
        while(r <= size){
            num = stoi(n.substr(l,r));
            sum += sumofString(num);
            l = r+1;
            r = l+6;
        }
        if(l <=size - 1){
            num = stoi(n.substr(l,size));
            sum += sumofString(num);
        }
    }
    sum = sum*k;
    string new_n = to_string(sum);
    return superDigit(new_n,1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string n;
    int k;
    cin >> n >> k;
    // cin >> T;
    // while(T){
    cout << superDigit(n,k)<<"\n";
    //     T--;
    // }
    return 0;
}
