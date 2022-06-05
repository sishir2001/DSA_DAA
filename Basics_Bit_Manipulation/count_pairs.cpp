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

int count_pairs(ll *a, ll *b, ll n, ll x, ll y);
ll count_pairs_effe(ll *a, ll *b, ll n, ll x, ll y);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("count_pair.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll T, n, x, y;
    cin >> T;
    while (T) {
        cin >> n >> x >> y;
        ll *a = new ll[n], *b = new ll[n];
        FOR(i, n) { cin >> a[i]; }
        FOR(i, n) { cin >> b[i]; }
        cout << count_pairs_effe(a, b, n, x, y) << "\n";
        delete[] a;
        delete[] b;
        T--;
    }
    return 0;
}

ll count_pairs_effe(ll *a, ll *b, ll n, ll x, ll y) {
    // !T(N) = O(N)
    // !S(N) = O(N)
    map<int, int> nA, nB;
    FOR(i, n) {
        nA[(a[i] & x) ^ (a[i] & y)]++;
        nB[(b[i] & x) ^ (b[i] & y)]++;
    }

    // lopping through map
    map<int, int>::iterator it;
    ll ans = 0;
    for (it = nA.begin(); it != nA.end(); it++) {
        if (nB.find(it->first) == nB.end()) {
            continue;
        }
        ans = ans + it->second * 1ll * nB[it->first];
    }
    return ans;
}
int count_pairs(ll *a, ll *b, ll n, ll x, ll y) {
    // !T(N) = O(N^2);
    int count = 0;
    FOR(i, n) {
        FOR(j, n) {
            if (a[i] == b[j]) {
                count++;
                continue;
            }
            int xor_ab = a[i] ^ b[j];
            if ((xor_ab & x) == (xor_ab & y)) {
                count++;
            }
        }
    }
    return count;
}