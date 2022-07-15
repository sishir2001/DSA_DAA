#include <bits/stdc++.h>
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
typedef pair<l, l> p_l;
typedef pair<ul, ul> p_ul;
typedef pair<ll, ll> p_ll;
typedef pair<ull, ull> p_ull;
typedef pair<int, int> p_int;
typedef pair<uint, uint> p_uint;

#define NXT_LINE cout << "\n"
#define EOL      '\n'
#define F        first
#define S        second
#define PB       push_back                         // for vector
#define PPB      pop_back                          // for vector
#define mod      1000000007                        // 1e9+7
#define deb(x)   cout << #x << " = " << x << "\n"  // for debugging
#define deb2(x, y)                                        \
    cout << #x << " = " << x << " , " << #y << " = " << y \
         << "\n"  // for debugging
#define FOR(a, end, start) \
    for (int(a) = (start); (a) < (end); (a)++)  // regular for loop
#define FOR_REV(a, end, start)             \
    for (int(a) = (end)-1; (a) >= (start); \
         (a)--)  // regular for loop decreasing
int min_sum(int n);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int res = min_sum(n);
    cout << res << "\n";
    return 0;
}

int min_sum(int n) {
    v_int digits;
    int k = n;
    while (k) {
        digits.PB(k % 10);
        k = k / 10;
    }
    // using min heap
    priority_queue<int,vector<int>,greater<int> > min_heap;
    for(int i = 0;i < digits.size();i++){
        min_heap.push(digits[i]);
    }
    int num1 = 0,num2 = 0;
    while(!min_heap.empty()){
        num1*=10;
        num1 += min_heap.top();
        min_heap.pop();
        if(!min_heap.empty()){
            num2 *= 10;
            num2 += min_heap.top();
            min_heap.pop();
        }
    }
    return num1+num2;
}