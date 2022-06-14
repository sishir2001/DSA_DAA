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

vector<bool> subset_sum(v_ll &nums, v_ll &query);
vector<bool> subset_sum_effe(v_ll &nums, v_ll &query);
void print_vector(vector<bool> &nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    NXT_LINE;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll T, n, m;
    cin >> T;
    while (T) {
        cin >> n;
        v_ll nums(n);  // vector
        FOR(i, n, 0) { cin >> nums[i]; }
        cin >> m;  // queries
        v_ll query(m);
        FOR(i, m, 0) { cin >> query[i]; }
        vector<bool> res = subset_sum(nums, query);
        print_vector(res);
        vector<bool> res_effe = subset_sum_effe(nums, query);
        print_vector(res_effe);
        nums.clear();
        T--;
    }
    return 0;
}
vector<bool> subset_sum(v_ll &nums, v_ll &query) {
    ll num_n = nums.size(), N = query.size();
    ll limit = 1 << num_n;
    vector<bool> res;
    set<int> hash;
    FOR(i, limit, 1) {
        ll j = i, k = 0, sum = 0;
        string binary_str = "";
        while (j > 0) {
            if ((j & 1) == 1) {
                binary_str = "1" + binary_str;
                sum += nums[k];
            } else {
                binary_str = "0" + binary_str;
            }
            k++;
            j = j >> 1;
        }
        hash.insert(sum);
        // deb(sum);
        // deb(binary_str);
    }
    FOR(i, N, 0) {
        if (hash.find(query[i]) != hash.end()) {
            // found
            res.PB(true);
        } else {
            res.PB(false);
        }
    }
    return res;
}

vector<bool> subset_sum_effe(v_ll &nums, v_ll &query) {
    // !T(N) = O(N+M)
    // ! using bitset
    ll N = query.size(), nums_n = nums.size();
    vector<bool> res;
    bitset<100> bit;
    bit.reset();
    bit[0] = 1;
    FOR(i, nums_n, 0) { bit |= (bit << nums[i]); }
    FOR(i, N, 0) {
        ll x = query[i];
        res.PB(bit[x] == 1 ? true : false);
    }
    return res;
}