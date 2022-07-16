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

ll longest_subarray_k(v_ll &nums, ll k);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll T, n, k;
    cin >> T;
    while (T) {
        cin >> n >> k;
        v_ll nums(n);  // vector
        FOR(i, n, 0) { cin >> nums[i]; }
        ll res = longest_subarray_k(nums, k);
        deb(res);
        nums.clear();
        T--;
    }
    return 0;
}

ll longest_subarray_k(v_ll &nums, ll k) {
    ll n = nums.size(), pr_sum = 0, mx = 0;
    map<ll, ll> m;  // prefix_sum : index
    m[0] = 0;
    FOR(i, n, 0) {
        pr_sum += nums[i];
        ll search = pr_sum - k;
        if (m.find(search) != m.end()) {
            mx = max(mx, i + 1 - m[search]);
        }
        if (m.find(pr_sum) == m.end())
            m[pr_sum] = i + 1;
    }
    return mx;
}