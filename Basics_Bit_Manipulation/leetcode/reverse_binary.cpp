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
#define F        first
#define S        second
#define PB       push_back                         // for vector
#define PPB      pop_back                          // for vector
#define mod      1000000007                        // 1e9+7
#define deb(x)   cout << #x << " = " << x << "\n"  // for debugging
#define deb2(x, y)                                        \
    cout << #x << " = " << x << " , " << #y << " = " << y \
         << "\n"                                          // for debugging
#define FOR(a, end) for (int(a) = 0; (a) < (end); (a)++)  // regular for loop
#define FOR_REV(a, start) \
    for (int(a) = (start)-1; (a) >= 0; (a)--)  // regular for loop decreasing
#define FOR_less(a, end, start) \
    for (int(a) = (start); (a) < (end); (a)++)  // regular for loop
#define FOR_REV_great(a, end, start) \
    for (int(a) = (start); (a) > (end); (a)--)  // regular for loop
#define FOR_less_or_equal(a, end, start) \
    for (int(a) = (start); (a) <= (end); (a)++)  // regular for loop
#define FOR_REV_great_or_equal(a, end, start) \
    for (int(a) = (start); (a) >= (end); (a)--)  // regular for loop

uint32_t reverse_binary(uint32_t n);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // given integer is unsigned 32 bit
    uint32_t n;
    cin >> n;
    cout << reverse_binary(n) << "\n";
    return 0;
}

uint32_t reverse_binary(uint32_t n) {
    int x = 1;
    uint32_t res = 0;
    while (n) {
        int index = log2(n & (~(n - 1)));
        res = res | (x << (31 - index));
        n = n & (n - 1);  // clearing the least significant bit
    }
    return res;
}