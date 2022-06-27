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

ll grid_paths(ll n, ll m, ll i, ll j);
ll grid_paths1(ll n, ll m);
ll factorial(ll n);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    bool tr = true, fl = false;
    deb2(tr, fl);
    ll T, n, m;
    cin >> T;
    while (T) {
        cin >> n >> m;
        if (grid_paths1(n, m) == grid_paths(n, m, 0, 0)) {
            cout << true << "\n";
        } else {
            cout << false << "\n";
        }
        T--;
    }
    return 0;
}

ll grid_paths(ll n, ll m, ll i, ll j) {
    // !works only for smaller inputs
    // * Dynamic Programming can be used here , sub-problem is recurring.
    if (i >= n || j >= m)
        return 0;
    if (i == n - 1 && j == m - 1)
        return 1;
    ll right = grid_paths(n, m, i, j + 1), down = grid_paths(n, m, i + 1, j);
    return right + down;
}

ll grid_paths1(ll n, ll m) {
    // !works only for smaller inputs
    // * Dynamic Programming can be used here , sub-problem is recurring.
    // !T(N) = O(N+M)
    // !S(N) = O(1)
    ll numerator = factorial(n + m - 2),
       denominator = factorial(n - 1) * factorial(m - 1);
    return numerator / denominator;
}

ll factorial(ll n) {
    // !T(N) = O(N)
    // !S(N) = O(1)
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}