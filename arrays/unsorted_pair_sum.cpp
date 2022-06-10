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

p_ll unsorted_pair_sum(v_ll &nums, ll x);

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
        p_ll res = unsorted_pair_sum(nums, x);
        cout << res.first << " " << res.second << "\n";
        nums.clear();
        T--;
    }
    return 0;
}

p_ll unsorted_pair_sum(v_ll &nums, ll x) {
    // @nums: unsorted vector
    ll n = nums.size();
    p_ll res;
    map<ll, v_ll> m;  // value : list of indexes
    for (ll i = 0; i < n; i++) {
        m[nums[i]].PB(i);
    }
    // // printing the map
    // map<ll, v_ll>::iterator it;
    // for (it = m.begin(); it != m.end(); it++) {
    //     cout << it->first << " : ";
    //     // printing the vector
    //     ll vec_n = it->second.size();
    //     for (ll j = 0; j < vec_n; j++) {
    //         cout << it->second[j] << " ";
    //     }
    //     NXT_LINE;
    // }

    // TODO : traverse the vector and find the index
    FOR(i, n, 0) {
        map<ll, v_ll>::iterator it = m.find(x - nums[i]);
        if (it != m.end()) {
            // traversing the it->second vector
            v_ll indexex = it->second;
            ll indexes_n = indexex.size();
            FOR(j, indexes_n, 0) {
                if (i != indexex[j]) {
                    res.first = i;
                    res.second = indexex[j];
                    return res;
                }
            }
        }
    }
    res.first = -1;
    res.second = -1;
    return res;
}