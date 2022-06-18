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

ll tiling_problem(ll R, ll C, string pattern = "", ll row_length = 0,
                  ll col_length = 0) {
    // TODO : check the last character of string
    // !T(N) = O(2^N)
    // !S(N) = O(1)
    ll n = pattern.length();
    if (n != 0) {
        if (pattern[n - 1] == 'r') {
            if (col_length == 0 || col_length == C) {
                row_length += 1;
            } else {
                col_length += C;
            }
        } else {
            if (col_length == 0) {
                row_length += C;
                col_length += 1;
            } else if (col_length == C) {
                col_length = 1;
                row_length += C;
            } else {
                col_length += 1;
            }
        }
    }
    if (col_length > C || row_length > R)
        return 0;
    if ((col_length == C && (row_length == R || row_length == 0)) ||
        (row_length == R && (col_length == C || col_length == 0)))
        return 1;
    return tiling_problem(R, C, pattern + "r", row_length, col_length) +
           tiling_problem(R, C, pattern + "c", row_length, col_length);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T, n, m;
    cin >> T;
    while (T) {
        cin >> n >> m;
        cout << tiling_problem(n, m) << "\n";
        T--;
    }
    return 0;
}