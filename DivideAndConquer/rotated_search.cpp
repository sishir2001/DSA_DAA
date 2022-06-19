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

void print_vector(v_ll &nums);
ll break_point(v_ll &nums);
ll binary_search(v_ll &nums, ll l, ll r, ll x);
ll rotated_search(v_ll &nums, ll x);
ll rotated_search2(v_ll &nums, ll x);
ll rotated_search_duplicates(v_ll &nums, ll x, ll l, ll r);

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
        print_vector(nums);
        cout << rotated_search(nums, x) << " ";
        cout << rotated_search2(nums, x) << " ";
        cout << rotated_search_duplicates(nums, x, 0, n - 1) << "\n";
        nums.clear();
        T--;
    }
    return 0;
}

void print_vector(v_ll &nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    NXT_LINE;
}

ll break_point(v_ll &nums) {
    // !T(N) = O(logN)
    // !S(N) = O(1)
    ll l = 0, r = nums.size() - 1;
    while (l <= r) {
        ll m = (l + r) / 2;
        if (nums[m] <= nums[r]) {
            if (m == 0 || nums[m - 1] > nums[r])
                return m;
            else {
                r = m;
            }
        } else {
            l = m + 1;
        }
    }
    return -1;  // should never come to this , only descending order
}

ll binary_search(v_ll &nums, ll l, ll r, ll x) {
    // !T(N) = O(logN)
    // !S(N) = O(1)
    while (l <= r) {
        ll m = (l + r) / 2;
        if (nums[m] == x)
            return m;
        else if (nums[m] > x) {
            r = m - 1;
        } else
            l = m + 1;
    }
    return -1;
}

ll rotated_search(v_ll &nums, ll x) {
    // !T(N) = O(logN)
    // !S(N) = O(1)
    ll p = break_point(nums);
    ll left = binary_search(nums, 0, p - 1, x);
    if (left != -1)
        return left;
    return binary_search(nums, p, nums.size() - 1, x);
}

ll rotated_search2(v_ll &nums, ll x) {
    // !T(N) = O(logN)
    // !S(N) = O(1)
    // * without finding the inflection point
    ll l = 0, r = nums.size() - 1;
    // TODO : check which line does x exists
    if (nums[l] <= x) {
        // lies in 1
        while (l <= r) {
            ll m = (l + r) / 2;
            if (nums[m] < nums[l] || nums[m] > x)
                r = m - 1;
            else if (nums[m] == x)
                return m;
            else
                l = m + 1;
        }
    } else {
        while (l <= r) {
            ll m = (l + r) / 2;
            if (nums[m] > nums[r] || nums[m] < x)
                l = m + 1;
            else if (nums[m] == x)
                return m;
            else
                r = m - 1;
        }
    }
    return -1;
}

ll rotated_search_duplicates(v_ll &nums, ll x, ll l, ll r) {
    if (l > r)
        return -1;
    if (x == nums[0] || x == nums[nums.size() - 1]) {
        return nums[0] == x ? l : r;
    } else if (x < nums[nums.size() - 1]) {
        // target is in part 2
        while (l <= r) {
            ll m = (l + r) / 2;
            if (nums[m] == x)
                return m;
            else if (nums[m] < nums[nums.size() - 1]) {
                // m is inside part 2
                if (nums[m] < x)
                    l = m + 1;
                else
                    r = m - 1;
            } else if (nums[m] > nums[0]) {
                // m is inside part 1
                l = m + 1;
            } else if (nums[m] == nums[0] || nums[m] == nums[nums.size() - 1]) {
                if (nums[m] == nums[0] && nums[m] == nums[nums.size() - 1]) {
                    ll left = rotated_search_duplicates(nums, x, l, m - 1);
                    if (left != -1) {
                        return left;
                    }
                    return rotated_search_duplicates(nums, x, m + 1, r);
                } else if (nums[m] < nums[0]) {
                    // inside part 2
                    if (nums[m] < x)
                        l = m + 1;
                    else
                        r = m - 1;
                } else
                    l = m + 1;
            }
        }
    } else {
        // target is in part 1
        while (l <= r) {
            ll m = (l + r) / 2;

            if (nums[m] == x)
                return m;
            else if (nums[m] > nums[0]) {
                // m inside part 1
                if (nums[m] < x)
                    l = m + 1;
                else
                    r = m - 1;
            } else if (nums[m] < nums[nums.size() - 1]) {
                // m inside part 2
                r = m - 1;
            } else if (nums[m] == nums[0] || nums[m] == nums[nums.size() - 1]) {
                if (nums[m] == nums[0] && nums[m] == nums[nums.size() - 1]) {
                    ll left = rotated_search_duplicates(nums, x, l, m - 1);
                    if (left != -1) {
                        return left;
                    }
                    return rotated_search_duplicates(nums, x, m + 1, r);
                } else if (nums[m] > nums[nums.size() - 1]) {
                    // inside part 1
                    if (nums[m] < x)
                        l = m + 1;
                    else
                        r = m - 1;
                } else
                    r = m - 1;
            }
        }
    }
    return -1;
}