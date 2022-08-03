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

void print_2d_vector(vector<vector<string>> &nums);
void print_vector(v_ll &nums);
vector<vector<string>> tokenise(string &s);
void print_solution(vector<vector<string>> &tokens);
int convert_string_int(string s);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input2.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
	string s,log_file = "",prev = "";
	while(true){
		prev = s;
		getline(cin,s);
		if(prev == s)
			break;
		log_file = log_file + s;
	}
	// cout << log_file;
	vector<vector<string>> tokens = tokenise(log_file);
	print_solution(tokens);
    return 0;
}

void print_2d_vector(vector<vector<string>> &nums) {
    for (auto num : nums) {
    	for(auto i : num){
    		cout << i << " ";
    	}
    	NXT_LINE;
    }
    NXT_LINE;
}

void print_vector(v_ll &nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    NXT_LINE;
}

void print_solution(vector<vector<string>> &tokens){
	map<string,int> m;
	vector<string> order;
	for(auto token : tokens){
		// TODO : calculate the bytes send
		int bytes = convert_string_int(token[2]);
		if(m.find(token[0]) == m.end()){
			m[token[0]] = bytes;
			order.PB(token[0]);
		}
		else{
			m[token[0]] += bytes;
		}
	}
	// traversing the map 
	int order_n = order.size();
	for(int i = 0;i < order_n;i++){
		cout << order[i] << " : " << m[order[i]] <<" ";
	}
}

vector<vector<string>> tokenise(string &s){
	vector<vector<string>> tokens;
	stringstream ss(s);
	string temp;
	int check = 0;
	vector<string> sub_tokens(3,"");
	while(getline(ss,temp,' ')){
		if(isdigit(temp[0])){
			sub_tokens[check] = temp; 
			// deb2(temp,check);
			check++;
			check = check%3;
			if(check == 0){
				tokens.PB(sub_tokens);
			}
		// deb(temp);
		}
	}
	// print_2d_vector(tokens);
	return tokens;
}

int convert_string_int(string s){
	stringstream ss(s);
	int res = 0;
	ss >> res;
	return res;
}
