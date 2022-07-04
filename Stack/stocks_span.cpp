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

v_ll stock_span(v_ll nums);
void print_vector(v_ll nums);

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
        v_ll res = stock_span(nums);
        print_vector(res);
        nums.clear();
        T--;
    }
    return 0;
}

v_ll stock_span(v_ll nums) {
    // !T(N) = O(N)
    // !S(N) = O(N)
    pair<int, int> p;
    stack<pair<int, int>> s;
    v_ll res;
    p.first = nums[0];
    p.second = 0;
    s.push(p);
    res.PB(1);
    FOR(i, nums.size(), 1) {
        if (nums[i] < s.top().first) {
            res.push_back(1);
        } else {
            while (!s.empty() && nums[i] >= s.top().first) {
                s.pop();
            }
            if (s.empty())
                res.push_back(i + 1);
            else
                res.push_back(i - s.top().second);
        }
        p.first = nums[i];
        p.second = i;
        s.push(p);
    }
    return res;
}

void print_vector(v_ll nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    NXT_LINE;
}