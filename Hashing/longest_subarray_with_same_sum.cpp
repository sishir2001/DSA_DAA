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
#define FOR_REV(a, end, start)             \
    for (ll(a) = (end)-1; (a) >= (start); \
         (a)--)  // regular for loop decreasing

ll longest_common_subarray_with_samesum(v_ll nums1, v_ll nums2);
ll longest_common_subarray_with_samesum_brute(v_ll &nums1, v_ll &nums2);

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
        v_ll nums1(n), nums2(n);  // vector
        FOR(i, n, 0) { cin >> nums1[i]; }
        FOR(i, n, 0) { cin >> nums2[i]; }
        ll res = longest_common_subarray_with_samesum(nums1, nums2);
        ll res_brute = longest_common_subarray_with_samesum_brute(nums1, nums2);
        deb2(res, res_brute);
        nums1.clear();
        nums2.clear();
        T--;
    }
    return 0;
}

ll longest_common_subarray_with_samesum(v_ll nums1, v_ll nums2) {
    // !T(N) = O(N)
    // !S(N) = O(N)
    // !subtract the arrays
    map<ll,ll> m; // value : index
    ll sum = 0,mx = 0,n = nums1.size();
    m[0] = 0;
    FOR(i, n, 0) { 
        nums1[i] = nums1[i] - nums2[i];
        sum += nums1[i];
        if(m.find(sum) == m.end()){
            m[sum] = i+1;
        }
        else{
            mx = max(mx,i+1-m[sum]);
        }
    }
    return mx;
}

ll longest_common_subarray_with_samesum_brute(v_ll &nums1, v_ll &nums2) {
    // ! T(N) = O(N^2)
    // ! S(N) = O(1)

    ll n = nums1.size(), mx = 0;
    for (ll i = 0; i < n; i++) {
        ll sum1 = 0, sum2 = 0;
        for (ll j = i; j < n; j++) {
            sum1 += nums1[j];
            sum2 += nums2[j];
            if (sum1 == sum2) {
                mx = max(mx, j - i + 1);
            }
        }
    }
    return mx;
}
