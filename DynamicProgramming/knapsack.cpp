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

ll knapsack_brute(v_ll &prices, v_ll &weights, ll w);
ll knapsack_brute_bot_up(v_ll &prices, v_ll &weights, ll N, ll W);
ll knapsack_recursion(v_ll &prices, v_ll &weights, ll w, ll n);
ll knapsack_recursion_top_down(v_ll &prices, v_ll &weights, ll w, ll n,
                               vector<v_ll> &dp);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll T, n, w;
    cin >> T;
    while (T) {
        cin >> n >> w;
        v_ll prices(n), weights(n);  // vector
        FOR(i, n, 0) { cin >> prices[i]; }
        FOR(i, n, 0) { cin >> weights[i]; }
        ll res = knapsack_brute(prices, weights, w);
        deb(res);
        ll res_rec = knapsack_recursion(prices, weights, w, n);
        deb(res_rec);
        vector<v_ll> dp(n + 1, v_ll(w + 1, -1));
        ll res_top_down =
            knapsack_recursion_top_down(prices, weights, w, n, dp);
        deb(res_top_down);
        ll res_bot_up = knapsack_brute_bot_up(prices, weights, n, w);
        deb(res_bot_up);
        prices.clear();
        weights.clear();
        T--;
    }
    return 0;
}

ll knapsack_brute(v_ll &prices, v_ll &weights, ll w) {
    // !T(N) = O(2^N)
    // * using binary exponentiation
    ll mx_p = 0, n = prices.size();
    ll limit = (ll)pow(2, n);
    FOR(i, limit, 1) {
        ll k = 0, x = 1, sum_p = 0, sum_wt = 0;
        while (x <= i) {
            if ((i & x) != 0) {
                sum_wt += weights[k];
                sum_p += prices[k];
            }
            x = x << 1;
            k++;
        }
        if (sum_wt <= w) {
            mx_p = max(mx_p, sum_p);
        }
    }
    return mx_p;
}

ll knapsack_recursion(v_ll &prices, v_ll &weights, ll w, ll n) {
    if (w == 0 || n == 0)
        return 0;
    ll inc = 0, exc = knapsack_recursion(prices, weights, w, n - 1);
    if (w - weights[n - 1] >= 0) {
        inc = prices[n - 1] +
              knapsack_recursion(prices, weights, w - weights[n - 1], n - 1);
    }
    return max(inc, exc);
}

ll knapsack_recursion_top_down(v_ll &prices, v_ll &weights, ll w, ll n,
                               vector<v_ll> &dp) {
    if (n == 0 || w == 0)
        return 0;
    if (dp[n][w] != -1) {
        cout << "matched ! " << n << " " << w << "\n";
        return dp[n][w];
    }
    ll inc = 0, exc = knapsack_recursion(prices, weights, w, n - 1);
    if (w - weights[n - 1] >= 0) {
        inc = prices[n - 1] +
              knapsack_recursion(prices, weights, w - weights[n - 1], n - 1);
    }
    return dp[n][w] = max(inc, exc);
}

ll knapsack_brute_bot_up(v_ll &prices, v_ll &weights, ll N, ll W) {
    // !T(N) = O(WN)
    // !S(N) = O(WN)
    // bottom down approach
    vector<v_ll> dp(N + 1, v_ll(W + 1, 0));
    for (int n = 1; n <= N; n++) {
        for (int w = 1; w <= W; w++) {
            ll inc = 0, exc = dp[n - 1][w];
            if (weights[n - 1] <= w) {
                inc = prices[n - 1] + dp[n - 1][w - weights[n - 1]];
            }
            dp[n][w] = max(inc, exc);
        }
    }
    return dp[N][W];
}