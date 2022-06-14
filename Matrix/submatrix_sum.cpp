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
ll submatrix_sum(vector<v_ll> &matrix, ll sr, ll sc, ll er, ll ec);
void prefix_matrix_sum(vector<v_ll> &matrix);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll T, n, m, sr, sc, er, ec;
    cin >> T;
    while (T) {
        cin >> n >> m >> sr >> sc >> er >> ec;
        // n rows and m cols
        vector<v_ll> matrix(n, v_ll(m, 0));  // 2d matrix
        FOR(i, n, 0) {
            FOR(j, m, 0) { cin >> matrix[i][j]; }
        }
        cout << submatrix_sum(matrix, sr, sc, er, ec) << "\n";
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

void prefix_matrix_sum(vector<v_ll> &matrix) {
    // !T(N) = O(N^2)
    // !S(N) = O(1)
    // modifying the matrix in prefix matrix sum
    ll rows = matrix.size(), cols = matrix[0].size();
    FOR(i, rows, 0) {
        FOR(j, cols, 0) {
            if (i == 0 || j == 0) {
                if (i == 0 && j == 0) {
                    continue;
                } else if (i == 0) {
                    matrix[i][j] = matrix[i][j - 1] + matrix[i][j];
                } else {
                    matrix[i][j] = matrix[i - 1][j] + matrix[i][j];
                }
            } else {
                matrix[i][j] = matrix[i][j] + matrix[i - 1][j] +
                               matrix[i][j - 1] - matrix[i - 1][j - 1];
            }
        }
    }
}

ll submatrix_sum(vector<v_ll> &matrix, ll sr, ll sc, ll er, ll ec) {
    // preprocessing should be done to calculate the submatrix sum
    // !T(N) = O(N^2)
    // !S(N) = O(1)
    prefix_matrix_sum(matrix);
    ll res = matrix[er][ec];
    if (sc - 1 >= 0) {
        res -= matrix[er][sc - 1];
    }
    if (sr - 1 >= 0) {
        res -= matrix[sr - 1][ec];
    }
    if (sr - 1 >= 0 && sc - 1 >= 0) {
        res += matrix[sr - 1][sc - 1];
    }
    return res;
}