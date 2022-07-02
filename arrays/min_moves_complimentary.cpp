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

ll min_moves(v_ll &nums, ll limit) {
    // !T(N) = O(N^2)
    ll mn = LLONG_MAX, n = nums.size();
    FOR(i, n / 2 + 1, 0) {
        ll req_sum = nums[i] + nums[n - 1 - i], l = 0, r = n - 1, count = 0;
        while (l <= r) {
            if (nums[l] + nums[r] > req_sum) {
                if ((nums[l] > nums[i] || nums[l] > nums[n - 1 - i]) &&
                    (nums[r] > nums[i] || nums[r] > nums[n - 1 - i]))
                    count += 2;
                else {
                    count += 1;
                }
            } else if (nums[l] + nums[r] < req_sum) {
                if ((nums[l] < nums[i] || nums[l] > nums[n - 1 - i]) &&
                    (nums[r] < nums[i] || nums[r] < nums[n - 1 - i]))
                    count += 2;
                else {
                    count += 1;
                }
            }
            l++;
            r--;
        }
        mn = min(mn, count);
    }
    return mn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll T, n, limit;
    cin >> T;
    while (T) {
        cin >> n >> limit;
        v_ll nums(n);  // vector
        FOR(i, n, 0) { cin >> nums[i]; }
        cout << min_moves(nums, limit) << "\n";
        nums.clear();
        T--;
    }
    return 0;
}