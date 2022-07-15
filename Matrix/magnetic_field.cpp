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
ll magnetic_field(vector<v_ll> &matrix);
ll diagnol_sum(vector<v_ll> &matrix, ll i, ll j, ll n);

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
        // n rows and m cols
        vector<v_ll> matrix(n, v_ll(n, 0));  // 2d matrix
        FOR(i, n, 0) {
            FOR(j, n, 0) { cin >> matrix[i][j]; }
        }
        ll res = magnetic_field(matrix);
        cout << res << "\n";
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

ll magnetic_field(vector<v_ll> &matrix) {
    ll n = matrix.size(), mx = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            ll row_sum = 0, cols_sum = 0,
               diag_sum = diagnol_sum(matrix, i, j, n);
            for (int a = 0; a < n; a++) {
                // row sum
                if (a == i)
                    continue;
                row_sum += matrix[a][j];
            }
            for (int a = 0; a < n; a++) {
                // row sum
                if (a == j)
                    continue;
                cols_sum += matrix[i][a];
            }
            ll tot_sum = row_sum + cols_sum + diag_sum + matrix[i][j];
            mx = max(tot_sum, mx);
        }
    }
    return mx;
}

ll diagnol_sum(vector<v_ll> &matrix, ll i, ll j, ll n) {
    ll left_sum = 0, right_sum = 0, a = i - 1, b = j - 1;
    while (a >= 0 && b >= 0) {
        left_sum += matrix[a][b];
        a--;
        b--;
    }
    a = i + 1;
    b = j + 1;
    while (a < n && b < n) {
        left_sum += matrix[a][b];
        a++;
        b++;
    }
    a = i - 1, b = j + 1;
    while (a >= 0 && j < n) {
        right_sum += matrix[a][b];
        a--;
        b++;
    }
    a = i + 1, b = j - 1;
    while (j >= 0 && a < n) {
        right_sum += matrix[a][b];
        b--;
        a++;
    }
    return left_sum + right_sum;
}