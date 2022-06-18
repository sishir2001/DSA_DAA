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

void merge(v_ll &nums, ll l, ll m, ll r);
void merge_sort(v_ll &nums, ll l, ll r);
void print_vector(v_ll &nums);

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
        print_vector(nums);
        merge_sort(nums, 0, n - 1);
        print_vector(nums);
        nums.clear();
        T--;
    }
    return 0;
}

void merge(v_ll &nums, ll l, ll m, ll r) {
    //! T(N) = O(N)
    //! S(N) = O(N)
    v_ll a, b;
    FOR(i, m + 1, l) { a.PB(nums[i]); }
    FOR(i, r + 1, m + 1) { b.PB(nums[i]); }
    ll i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (a[i - l] <= b[j - m - 1]) {
            nums[k++] = a[i - l];
            i++;
        } else {
            nums[k++] = b[j - m - 1];
            j++;
        }
    }
    while (i <= m) {
        nums[k++] = a[i - l];
        i++;
    }
    while (j <= r) {
        nums[k++] = b[j - m - 1];
        j++;
    }
    return;
}

void merge_sort(v_ll &nums, ll l, ll r) {
    if (l >= r)
        return;
    ll m = (l + r) >> 1;
    merge_sort(nums, l, m);
    merge_sort(nums, m + 1, r);
    merge(nums, l, m, r);
}

void print_vector(v_ll &nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    NXT_LINE;
}