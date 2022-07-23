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

ll max_money_top_down(v_ll &nums, vector<v_ll> &dp, ll n, ll l, ll r);
ll max_money(v_ll &nums, ll n, ll l, ll r);
void print_matrix(vector<v_ll> &matrix);

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
        ll res_recursion = max_money(nums, n, 0, n - 1);
        deb(res_recursion);
        vector<v_ll> dp(n, v_ll(n, -1));
        ll res_top_down = max_money_top_down(nums, dp, n, 0, n - 1);
        deb(res_top_down);
        print_matrix(dp);
        nums.clear();
        T--;
    }
    return 0;
}

ll max_money_top_down(v_ll &nums, vector<v_ll> &dp, ll n, ll l, ll r) {
    if (l > r)
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];
    if (l == r)
        return dp[l][r] = nums[l];
    ll left = nums[l] + min(max_money_top_down(nums, dp, n, l + 2, r),
                            max_money_top_down(nums, dp, n, l + 1, r - 1)),
       right = nums[r] + min(max_money_top_down(nums, dp, n, l, r - 2),
                             max_money_top_down(nums, dp, n, l + 1, r - 1));
    return dp[l][r] = max(left, right);
}
ll max_money(v_ll &nums, ll n, ll l, ll r) {
    if (l > r)
        return 0;
    if (l == r)
        return nums[l];
    ll left = nums[l] + min(max_money(nums, n, l + 2, r),
                            max_money(nums, n, l + 1, r - 1)),
       right = nums[r] + min(max_money(nums, n, l, r - 2),
                             max_money(nums, n, l + 1, r - 1));
    return max(left, right);
}

void print_matrix(vector<v_ll> &matrix) {
    ll n = matrix.size(), m = matrix[0].size();
    FOR(i, n, 0) {
        FOR(j, m, 0) { cout << matrix[i][j] << " "; }
        NXT_LINE;
    }
}