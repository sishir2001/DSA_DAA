// ?
// https://www.geeksforgeeks.org/maximize-product-of-subarray-sum-with-its-maximum-element/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// typedef vector<ll> v_ll;
typedef vector<int> v_int;

#define mod    1000000007                        // 1e9+7
#define deb(x) cout << #x << " = " << x << "\n"  // for debugging
#define deb2(x, y)                                        \
    cout << #x << " = " << x << " , " << #y << " = " << y \
         << "\n"                                          // for debugging
#define FOR(a, end) for (int(a) = 0; (a) < (end); (a)++)  // regular for loop
#define FOR_desc(a, end) \
    for (int(a) = (end)-1; (a) >= 0; (a)--)  // regular for loop decreasing
#define FOR_custom_more_desc(a, start) for (int(a) = (start); (a) > 0; (a)--)
#define FOR_custom_more_or_equal_desc(a, start) \
    for (int(a) = (start); (a) >= 0; (a)--)
#define FOR_custom_less(a, end, start) \
    for (int(a) = (start); (a) < (end); (a)++)  // regular for loop
#define FOR_custom_less_or_equal(a, end, start) \
    for (int(a) = (start); (a) <= (end); (a)++)  // regular for loop

int maxSumSubArrXmaxEleSubArr(v_int nums);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T, n, x;
    v_int nums;
    cin >> T;
    while (T) {
        cin >> n;
        FOR(i, n) {
            cin >> x;
            nums.push_back(x);
        }
        cout << maxSumSubArrXmaxEleSubArr(nums) << "\n";
        nums.clear();
        T--;
    }
    return 0;
}

int maxSumSubArrXmaxEleSubArr(v_int nums) {
    // * T(n) = O(n)
    // *S(n) = O(1)
    // just a modification to kadane's algorithm
    int size = nums.size(), sum = nums[0], max_sum = nums[0], max_ele = nums[0];
    FOR_custom_less(i, size, 1) {
        if (sum + nums[i] < nums[i]) {
            sum = nums[i];
            max_ele = nums[i];
        } else {
            max_ele = max(max_ele, nums[i]);
            sum = sum + nums[i];
        }
        max_sum = max(max_sum, sum);
    }
    return max_ele * max_sum;
}