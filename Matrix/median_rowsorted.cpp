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

void print_matrix(vector<v_ll> &matrix);
ll median(vector<v_ll> &matrix);

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
        cin >> n >> m;
        // n rows and m cols
        vector<v_ll> matrix(n, v_ll(m, 0));  // 2d matrix
        FOR(i, n, 0) {
            FOR(j, m, 0) { cin >> matrix[i][j]; }
        }
        ll med = median(matrix);
        deb(med);
        matrix.clear();
        T--;
    }
    return 0;
}

void print_matrix(vector<v_ll> &matrix) {
    ll n = matrix.size(), m = matrix[0].size();
    FOR(i, n, 0) {
        FOR(j, m, 0) { cout << matrix[i][j] << " "; }
        NXT_LINE;
    }
}

ll median(vector<v_ll> &matrix) {
    // !T(N) = O(r*log(mx-mn)*logc)
    ll r = matrix.size(), c = matrix[0].size();
    ll mn = matrix[0][c - 1], mx = matrix[0][0];
    FOR(i, r, 1) {
        mx = max(mx, matrix[i][c - 1]);
        mn = min(mn, matrix[i][0]);
    }
    deb2(mn, mx);
    ll med_pos = (r * c + 1) / 2;
    deb(med_pos);
    while (mn < mx) {
        ll mid = (mx + mn) / 2, mid_pos = 0;
        // finding the elements less mid in the
        FOR(i, r, 0) {
            mid_pos += upper_bound(matrix[i].begin(), matrix[i].end(), mid) -
                       matrix[i].begin();
        }

        if (mid_pos < med_pos)
            mn = mid + 1;
        else
            mx = mid;
    }
    return mn;
}