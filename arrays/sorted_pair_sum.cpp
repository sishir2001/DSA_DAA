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

p_ll sorted_par_sum(v_ll &nums, ll x);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll T, n, x;
    cin >> T;
    while (T) {
        cin >> n >> x;
        v_ll nums(n);  // vector
        FOR(i, n, 0) { cin >> nums[i]; }
        p_ll res = sorted_par_sum(nums, x);
        cout << res.first << " " << res.second << "\n";
        nums.clear();
        T--;
    }
    return 0;
}
p_ll sorted_par_sum(v_ll &nums, ll x) {
    // @nums : sorted vector
    ll l = 0, r = nums.size() - 1, mn_diff = LLONG_MAX;
    p_ll res;
    while (l < r) {
        ll diff = abs(x - nums[l] - nums[r]);
        if (diff < mn_diff) {
            mn_diff = diff;
            res.first = nums[l];
            res.second = nums[r];
        }
        if (nums[l] + nums[r] == x)
            return res;
        else if (nums[l] + nums[r] > x) {
            r--;
        } else {
            l++;
        }
    }
    return res;
}
