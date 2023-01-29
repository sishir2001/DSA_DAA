#include<bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long l;
typedef unsigned long ul;
typedef long long ll;
typedef unsigned long long ull;

typedef vector<l> v_l;
typedef vector<ul> v_ul;
typedef vector<ll> v_ll;
typedef vector<ull> v_ull;
typedef vector<int> v_int;
typedef vector<uint> v_uint;
typedef pair<l,l> p_l;
typedef pair<ul,ul> p_ul;
typedef pair<ll,ll> p_ll;
typedef pair<ull,ull> p_ull;
typedef pair<int,int> p_int;
typedef pair<uint,uint> p_uint;

#define NXT_LINE cout << "\n"
#define EOL      '\n'
#define F first
#define S second
#define PB push_back // for vector
#define PPB pop_back // for vector
#define mod 1000000007 // 1e9+7
#define deb(x) cout << #x << " = "<<x<<"\n" // for debugging
#define deb2(x,y) cout << #x << " = "<<x << " , " << #y << " = " << y <<"\n" // for debugging 
#define FOR(a,end,start) for(int (a) = (start);(a) <(end);(a)++) // regular for loop
#define FOR_REV(a,end,start) for(int (a) = (end)-1;(a) >= (start);(a)--) // regular for loop decreasing

void reverse(string &str,int l ,int r){
	while(l < r){
		swap(str[l],str[r]);
		l++;
		r--;
	}
}

void reverseWordsString(string &str){
	const int LENGTH = str.length();
	int l = 0,r = 0;
	// traverse the string for reversing the words
	while(r < LENGTH){
		if(str[r] != ' '){
			r++;
		}
		else{
			reverse(str,l,r-1);
			l = r+1;
			r = l;
		}
	}
	if(l != r){
		reverse(str,l,r-1);
	}
	reverse(str,0,LENGTH-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    int T;
    string str = "";
    cin >> T;
    // flush
    while(T+1){
    	getline(cin,str);
    	reverseWordsString(str);
    	deb(str);
        T--;
    }
    return 0;
}
