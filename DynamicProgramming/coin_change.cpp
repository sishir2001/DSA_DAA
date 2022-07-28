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
    for (ll(a) = (start); (a) < (end); (a)++)  // regular for loop
#define FOR_REV(a, end, start) \
    for (ll(a) = (end)-1; (a) >= (start); (a)--)  // regular for loop decreasing

ll coin_change(v_ll &coins, ll m, map<ll, ll> &h);
ll coin_change_itr(v_ll &coins, ll m);
ll coin_change_recr(v_ll &coins, ll m);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll T, n, m;
    cin >> T;
    while (T) {
        cin >> n >> m;
        v_ll nums(n);  // vector
        FOR(i, n, 0) { cin >> nums[i]; }
        deb(m);
        map<ll, ll> h;
        ll res = coin_change(nums, m, h);
        ll res_itr = coin_change_itr(nums, m);
        // ll res_recr = coin_change_recr(nums, m);
        deb2(res, res_itr);
        // deb(res_recr);
        nums.clear();
        T--;
    }
    return 0;
}

ll coin_change(v_ll &coins, ll m, map<ll, ll> &h) {
    if (m < 0)
        return -1;
    if (m == 0)
        return 0;
    if (h.find(m) != h.end())
        return h[m];
    ll mn = LLONG_MAX;
    FOR(i, coins.size(), 0) {
        if (h.find(m - coins[i]) == h.end())
            h[m - coins[i]] = coin_change(coins, m - coins[i], h);
        if (h[m - coins[i]] != -1)
            mn = min(mn, h[m - coins[i]]);
    }
    return mn == LLONG_MAX ? -1 : mn + 1;
}

ll coin_change_recr(v_ll &coins, ll m) {
    if (m < 0)
        return -1;
    if (m == 0)
        return 0;
    ll mn = LLONG_MAX;
    FOR(i, coins.size(), 0) {
        deb2(m, coins[i]);
        ll temp = coin_change_recr(coins, m - coins[i]);
        if (temp != -1)
            mn = min(mn, temp);
    }
    return mn == LLONG_MIN ? -1 : mn + 1;
}

ll coin_change_itr(v_ll &coins, ll m) {
    // Bottoms up approach DP
    v_ll dp(m + 1, 0);
    dp[0] = 0;
    FOR(i, m + 1, 1) {
        ll mn = LLONG_MAX;
        FOR(j, coins.size(), 0) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != -1)
                mn = min(mn, dp[i - coins[j]]);
        }
        dp[i] = mn == LLONG_MAX ? -1 : mn + 1;
    }
    return dp[m];
}
