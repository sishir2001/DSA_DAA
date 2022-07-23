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

ll wines_recursion(v_ll &nums, ll l, ll r, ll count);
void print_matrix(vector<v_ll> &matrix);
ll wines_recursion_bot_up(v_ll &nums, ll n);

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
        v_ll nums(n);  // vector
        FOR(i, n, 0) { cin >> nums[i]; }
        ll res_bot_up = wines_recursion_bot_up(nums, n);
        cout << res_bot_up << "\n";
        nums.clear();
        T--;
    }
    return 0;
}

ll wines_recursion(v_ll &nums, ll l, ll r, ll count) {
    if (l > r)
        return 0;
    ll left =
           nums[l] * (count + 1) + wines_recursion(nums, l + 1, r, count + 1),
       right =
           nums[r] * (count + 1) + wines_recursion(nums, l, r - 1, count + 1);
    return max(left, right);
}

ll wines_recursion_bot_up(v_ll &nums, ll n) {
    vector<v_ll> dp(n, v_ll(n, 0));
    FOR_REV(l, n, 0) {
        ll tl = l, r = n - 1, yr = l + 1;
        while (tl >= 0) {
            ll left = nums[tl] * yr, right = nums[r] * yr;
            if (tl + 1 < n)
                left += dp[tl + 1][r];
            if (r - 1 >= 0)
                right += dp[tl][r - 1];
            dp[tl][r] = max(left, right);
            tl--;
            r--;
        }
    }
    return dp[0][n - 1];
}

void print_matrix(vector<v_ll> &matrix) {
    ll n = matrix.size(), m = matrix[0].size();
    FOR(i, n, 0) {
        FOR(j, m, 0) { cout << matrix[i][j] << " "; }
        NXT_LINE;
    }
}