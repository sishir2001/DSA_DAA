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

ll find_max_index_prod(v_ll &nums) {
    ll n = nums.size(), mx = 0, right = 0;
    v_ll left(n, 0);
    stack<ll> s;
    s.push(1);
    FOR(i, n - 1, 1) {
        while (!s.empty() && nums[i] >= nums[s.top() - 1]) s.pop();
        left[i] = s.empty() ? 0 : s.top();
        s.push(i + 1);
    }
    while (!s.empty()) s.pop();
    s.push(n);
    FOR_REV(i, n - 1, 1) {
        while (!s.empty() && nums[i] >= nums[s.top() - 1]) s.pop();
        right = s.empty() ? 0 : s.top();
        s.push(i + 1);
        mx = max(mx, right * left[i]);
    }
    return mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, T;
    cin >> T;
    while (T) {
        cin >> n;
        v_ll nums(n);  // vector
        FOR(i, n, 0) { cin >> nums[i]; }
        cout << find_max_index_prod(nums) << "\n";
        nums.clear();
        T--;
    }
    return 0;
}