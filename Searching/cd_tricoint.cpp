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

ll max_triangles(ll n);
ll sum(ll n) { return n * (n + 1) / 2; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll T, n;
    cin >> T;
    while (T) {
        cin >> n;
        cout << max_triangles(n) << "\n";
        T--;
    }
    return 0;
}

ll max_triangles(ll n) {
    // using binary search
    ll l = 1, r = n, prev_m = 0;
    while (l <= r) {
        ll m = (l + r) / 2;
        ll s = sum(m);
        if (s == n)
            return m;
        else if (s < n) {
            if (m < n && sum(m + 1) > n)
                return m;
            l = m + 1;
        } else {
            if (m > 1 && sum(m - 1) < n)
                return m - 1;
            r = m - 1;
        }
        prev_m = m;
    }
    return prev_m;
}