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

void count_sort(v_ll &nums);
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
        count_sort(nums);
        print_vector(nums);
        nums.clear();
        T--;
    }
    return 0;
}

void count_sort(v_ll &nums) {
    // ? helpful when given input is in a range
    // !T(N) = O(N+range)
    // !S(N) = O(range)
    // ! Not stable algorithm
    // TODO : find max element in nums
    ll mx = nums[0], n = nums.size(), k = 0;
    FOR(i, n, 1) { mx = max(mx, nums[i]); }
    v_ll count(mx + 1, 0);
    // TODO : traversing nums for frequency
    FOR(i, n, 0) { count[nums[i]]++; }
    // TODO : traversing the count vector for sorting
    FOR(i, mx + 1, 0) {
        FOR(j, count[i], 0) { nums[k++] = i; }
    }
}

void print_vector(v_ll &nums) {
    ll n = nums.size();
    FOR(i, n, 0) { cout << nums[i] << " "; }
    NXT_LINE;
}