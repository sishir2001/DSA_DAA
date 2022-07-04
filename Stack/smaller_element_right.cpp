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

vector<ll> smaller_element_right(vector<ll> nums);
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
        vector<ll> res = smaller_element_right(nums);
        print_vector(res);
        nums.clear();
        T--;
    }
    return 0;
}

vector<ll> smaller_element_right(vector<ll> nums) {
    // !T(N) = O(N)
    // !S(N) = O(N)
    stack<pair<ll, ll>> s;
    pair<ll, ll> p;
    int n = nums.size();
    for (int i = n - 1; i >= 0; i--) {
        if (s.empty()) {
            // stack is empty
            p.first = nums[i];
            p.second = 0;
        } else {
            while (!s.empty() && nums[i] <= s.top().first) s.pop();
            p.first = nums[i];
            p.second = s.empty() ? 0 : s.top().second + 1;
        }
        nums[i] = p.second;
        s.push(p);
    }
    return nums;
}

void print_vector(v_ll &nums) {
    for (auto num : nums) cout << num << " ";
    NXT_LINE;
}