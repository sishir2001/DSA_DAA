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

void print_matrix(vector<v_ll> &matrix);
ll max_happiness_recursion(vector<v_ll> &matrix, ll i, ll n, ll p);
ll max_happiness_top_down(vector<v_ll> &matrix, vector<v_ll> &dp, ll i, ll n,
                          ll p);
ll max_happiness_bot_up(vector<v_ll> &matrix, ll n);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, m = 3;
    cin >> n;
    // n rows and m cols
    vector<v_ll> matrix(n, v_ll(m, 0));  // 2d matrix
    // m = 0 -> a,m = 1->b,m = 2->c
    FOR(i, n, 0) {
        FOR(j, m, 0) { cin >> matrix[i][j]; }
    }
    // ll res = max_happiness_recursion(matrix, 0, n, -1);
    // deb(res);
    // vector<v_ll> dp(n + 1, v_ll(4, -1));
    // ll res_top_down = max_happiness_top_down(matrix, dp, 0, n, 0);
    // deb(res_top_down);
    ll res_bot_up = max_happiness_bot_up(matrix, n);
    cout << res_bot_up << "\n";

    // print_matrix(dp);
    matrix.clear();
    return 0;
}

void print_matrix(vector<v_ll> &matrix) {
    ll n = matrix.size(), m = matrix[0].size();
    FOR(i, n, 0) {
        FOR(j, m, 0) { cout << matrix[i][j] << " "; }
        NXT_LINE;
    }
}

ll max_happiness_recursion(vector<v_ll> &matrix, ll i, ll n, ll p) {
    if (i == n)
        return 0;
    ll mx = 0;
    for (ll j = 0; j <= 2; j++) {
        if (j != p) {
            mx = max(mx, matrix[i][j] +
                             max_happiness_recursion(matrix, i + 1, n, j));
        }
    }
    return mx;
}

ll max_happiness_top_down(vector<v_ll> &matrix, vector<v_ll> &dp, ll i, ll n,
                          ll p) {
    if (i == n)
        return 0;
    if (dp[i][p] != -1) {
        return dp[i][p];
    }
    ll mx = 0;
    for (ll j = 1; j <= 3; j++) {
        if (j != p) {
            mx = max(mx, matrix[i][j - 1] +
                             max_happiness_top_down(matrix, dp, i + 1, n, j));
        }
    }
    return dp[i][p] = mx;
}

ll max_happiness_bot_up(vector<v_ll> &matrix, ll n) {
    // !T(N) = thetha(3*N)
    // !S(N) = thetha(3*N)
    vector<v_ll> dp(n + 1, v_ll(3, 0));
    FOR_REV(i, n, 0) {
        FOR(j, 3, 0) {
            dp[i][j] = matrix[i][j] +
                       max(dp[i + 1][(j + 1) % 3], dp[i + 1][(j + 2) % 3]);
        }
    }
    return max(dp[0][0], max(dp[0][1], dp[0][2]));
}