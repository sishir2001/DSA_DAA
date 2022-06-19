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

int find_min(v_ll &nums, ll l, ll r);

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
        cout << find_min(nums, 0, n - 1) << "\n";
        nums.clear();
        T--;
    }
    return 0;
}

int find_min(v_ll &nums, ll l, ll r) {
    // !T(N) = O(logN)
    // !S(N) = (logN)
    // ! there will be elements repeating
    if (l == r) {
        return nums[l];
    }
    ll m = (l + r) / 2;
    if (m == l) {
        if (nums[m] < nums[r])
            return nums[m];
        else {
            return find_min(nums, m + 1, r);
        }
    }
    if (m == r) {
        if (nums[m] < nums[m - 1])
            return nums[m];
        else {
            return find_min(nums, l, m - 1);
        }
    }
    if (nums[m - 1] > nums[m] && nums[m] <= nums[m + 1]) {
        return nums[m];
    } else if (nums[m] <= nums[r]) {
        if (nums[m] < nums[l]) {
            return find_min(nums, l, m - 1);
        } else {
            // don't know which part m is in
            ll left = find_min(nums, l, m), right = find_min(nums, m + 1, r);
            return min(left, right);
        }
    } else {
        return find_min(nums, m + 1, r);
    }
    return nums[0];  // should not execute
}