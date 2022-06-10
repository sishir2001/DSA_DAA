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

ll max_pair(v_ll &nums, ll D);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll N, D;
    cin >> N >> D;
    v_ll nums(N);  // vector
    FOR(i, N, 0) { cin >> nums[i]; }
    cout << max_pair(nums, D) << "\n";
    nums.clear();
    return 0;
}

ll max_pair(v_ll &nums, ll D) {
    // !T(N) = O(NlogN)
    // !S(N) = O(1)
    ll n = nums.size(), pairs = 0;
    // TODO : sort the vector
    sort(nums.begin(), nums.end());
    // TODO : traverse the vector
    ll l = 0, r = 1;
    while (r < n && l < n) {
        // TODO : counting pairs
        ll diff = nums[r] - nums[l];
        if (diff <= D) {
            // ? will make a pair
            pairs++;
            l = r + 1;
            r = l + 1;
        } else {
            l = r;
            r++;
        }
    }
    return pairs;
}