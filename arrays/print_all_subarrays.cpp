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

void print_all_subarray(ll *nums, ll n);
ll print_all_subarray_recursion(ll *nums, ll n, ll i, ll j);
ll kadane_algo(ll *nums, ll n);
ll mx_subarray_sum_usingprefix(ll *nums, ll n);

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
        ll *a = new ll[n];
        FOR(i, n, 0) { cin >> a[i]; }
        print_all_subarray(a, n);
        cout << "Maximum Subarray sum using recursion : "
             << print_all_subarray_recursion(a, n, 0, 0) << "\n";
        cout << "Maximum Subarray sum using kadane's algo : "
             << kadane_algo(a, n) << "\n";
        cout << "Maximum Subarray sum using Prefix_sum method : "
             << mx_subarray_sum_usingprefix(a, n) << "\n";
        delete[] a;
        T--;
    }
    return 0;
}

void print_all_subarray(ll *nums, ll n) {
    // !T(N) = O(N^2)
    // !S(N) = O(1)
    ll mx_sum = LLONG_MIN;
    FOR(k, n, 0) {
        FOR(i, n, 0) {
            bool is_break = false;
            ll sum = 0;
            // For printing the array
            FOR(j, i + k + 1, i) {
                if (i + k + 1 <= n) {
                    sum = sum + nums[j];
                } else {
                    is_break = true;
                    break;
                }
            }
            if (is_break) {
                break;
            }
            mx_sum = max(mx_sum, sum);
        }
    }
    cout << "Maximum Subarray sum : " << mx_sum << "\n";
}

ll print_all_subarray_recursion(ll *nums, ll n, ll i, ll j) {
    // !T(N) = O(N^2)
    // !S(N) = O(N)
    if (i >= n || j >= n)
        return LLONG_MIN;

    // getting the sum of the subarray
    ll sum = 0, sum_l = LLONG_MIN, sum_r = 0;
    FOR(k, j + 1, i) { sum += nums[k]; }
    if (i == 0)
        sum_l = print_all_subarray_recursion(nums, n, i, j + 1);
    sum_r = print_all_subarray_recursion(nums, n, i + 1, j + 1);
    return max(sum, max(sum_l, sum_r));
}

ll kadane_algo(ll *nums, ll n) {
    // !T(N) = O(N)
    // !S(N) = O(1)
    ll mx_sum = nums[0], sum = nums[0];
    FOR(i, n, 1) {
        sum = max(sum + nums[i], nums[i]);
        mx_sum = max(sum, mx_sum);
    }
    return mx_sum;
}

ll mx_subarray_sum_usingprefix(ll *nums, ll n) {
    // ?using prefix sum approach

    // TODO : calculate the prefix_sum array
    ll *prefix_nums = new ll[n], mx_sum = LLONG_MIN;
    prefix_nums[0] = nums[0];

    FOR(i, n, 1) { prefix_nums[i] = prefix_nums[i - 1] + nums[i]; }

    // TODO : calculating max subarray sum
    FOR(i, n, 0) {
        FOR(j, n, i) {
            // FOR(k, j + 1, i) { cout << nums[k] << " "; }
            // NXT_LINE;
            ll sum = LLONG_MIN;
            if (i == j)
                sum = nums[j];
            else if (i == 0)
                sum = prefix_nums[j];
            else
                sum = prefix_nums[j] - prefix_nums[i - 1];
            mx_sum = max(sum, mx_sum);
        }
    }
    delete[] prefix_nums;
    prefix_nums = NULL;
    return mx_sum;
}