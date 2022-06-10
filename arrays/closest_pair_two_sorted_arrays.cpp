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
         << "\n"  // for debugging
#define FOR(a, end, start) \
    for (int(a) = (start); (a) < (end); (a)++)  // regular for loop
#define FOR_REV(a, end, start)             \
    for (int(a) = (end)-1; (a) >= (start); \
         (a)--)  // regular for loop decreasing

p_ll closest_pair(v_ll &nums0, v_ll &nums1, ll x);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll T, n, m, x;
    cin >> T;
    while (T) {
        cin >> n >> m >> x;
        v_ll nums1(n), nums0(m);  // vector
        FOR(i, n, 0) { cin >> nums0[i]; }
        FOR(i, m, 0) { cin >> nums1[i]; }
        p_ll res = closest_pair(nums0, nums1, x);
        cout << res.first << " " << res.second << "\n";
        nums0.clear();
        nums1.clear();
        T--;
    }
    return 0;
}

p_ll closest_pair(v_ll &nums0, v_ll &nums1, ll x) {
    // !T(N) = O(M+N)
    // !S(N) = O(1)
    // ? modification of binary search
    // @nums0 and nums1 : sorted vectors
    ll n = nums0.size(), m = nums1.size(), diff = 0, mn_diff = LLONG_MAX;
    ll l = 0, r = m - 1;
    p_ll res;
    while (l < n && r >= 0) {
        ll sum = nums0[l] + nums1[r];
        diff = abs(x - sum);
        if (diff < mn_diff) {
            mn_diff = diff;
            res.first = nums0[l];
            res.second = nums1[r];
        }
        if (sum == x) {
            return res;
        } else if (sum > x) {
            r--;
        } else {
            l++;
        }
    }
    return res;
}