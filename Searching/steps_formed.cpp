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

ll steps_formed(ll n);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T, n;
    cin >> T;
    while (T) {
        cin >> n;
        cout << steps_formed(n) << "\n";
        T--;
    }
    return 0;
}

ll steps_formed(ll n) {
    // implementation of binary search
    // x*(x+1)/2 <= n
    // We need to find x
    n = 2 * n;
    ll l = 1, r = n / 2;
    while (l <= r) {
        ll m = (l + r) / 2;
        ll steps = m * (m + 1) - 1;
        if (steps == n)
            return m;
        else if (steps < n) {
            // checking for next number
            if ((m + 1) * (m + 2) - 1 > n)
                return m;
            else
                l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return 0;  // this should never be executed
}