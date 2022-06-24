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

v_int top_K_freq_elements(v_int &nums, int k);
void print_vector(v_int &nums);
int partition(v_int &nums, map<int, int> &m, int l, int r);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T, n, k;
    cin >> T;
    while (T) {
        cin >> n >> k;
        v_int nums(n);  // vector
        FOR(i, n, 0) { cin >> nums[i]; }
        v_int res = top_K_freq_elements(nums, k);
        print_vector(res);
        nums.clear();
        T--;
    }
    return 0;
}

v_int top_K_freq_elements(v_int &nums, int k) {
    // !T(N) = O(NlogN)
    // !S(N) = O(N)
    // using quickselect algorithm similar to quicksort
    map<int, int> m;
    v_int res, keys;
    // TODO : traverse the array for map
    for (auto num : nums) {
        m[num]++;
    }
    // TODO : take all the keys from the map and use the quickselect algorithm
    for (auto it : m) {
        keys.PB(it.first);
    }
    int l = 0, r = keys.size() - 1, n = keys.size();
    while (l <= r) {
        int p = partition(keys, m, l, r);
        if (p == n - k) {
            for (int i = p; i < n; i++) {
                res.PB(keys[i]);
            }
            break;
        } else if (p < n - k) {
            l = p + 1;
        } else
            r = p - 1;
    }
    return res;
}

void print_vector(v_int &nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    NXT_LINE;
}

int partition(v_int &keys, map<int, int> &m, int l, int r) {
    // !T(N) = O(N)
    // !S(N) = O(1)
    int p = r, i = l, j = r - 1;
    while (i <= j) {
        if (m[keys[i]] < m[keys[p]]) {
            i++;
        } else {
            swap(keys[i], keys[j]);
            j--;
        }
    }
    swap(keys[i], keys[p]);
    return i;
}