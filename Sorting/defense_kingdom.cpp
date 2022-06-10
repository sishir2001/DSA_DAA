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

ll defense_kingdom(v_ll &cols, v_ll &rows);
void print_vector(v_ll &nums);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll T, n, H, W;
    cin >> T;
    while (T) {
        cin >> W >> H >> n;
        v_ll cols(n), rows(n);  // vector
        FOR(i, n, 0) { cin >> cols[i] >> rows[i]; }
        cols.PB(W);
        rows.PB(H);
        cout << defense_kingdom(cols, rows) << "\n";
        cols.clear();
        rows.clear();
        T--;
    }
    return 0;
}

ll defense_kingdom(v_ll &cols, v_ll &rows) {
    // !T(N) = O(NlogN)
    // !S(N) = O(1)
    // sort the vectors
    sort(cols.begin(), cols.end());
    sort(rows.begin(), rows.end());
    ll n = cols.size(), mx_cols = cols[1] - cols[0],
       mx_rows = rows[1] - rows[0];
    FOR(i, n, 2) {
        mx_cols = max(cols[i] - cols[i - 1], mx_cols);
        mx_rows = max(rows[i] - rows[i - 1], mx_rows);
    }
    return (mx_cols - 1) * (mx_rows - 1);
}
void print_vector(v_ll &nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    NXT_LINE;
}