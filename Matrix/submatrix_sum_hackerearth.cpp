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
    for (ll(a) = (start); (a) < (end); (a)++)  // regular for loop
#define FOR_REV(a, end, start) \
    for (ll(a) = (end)-1; (a) >= (start); (a)--)  // regular for loop decreasing

void print_matrix(vector<v_ll> &matrix);
void submatrix_sum_count(vector<v_ll> &matrix, ll s);
void prefix_sum_matrix(vector<v_ll> &matrix, ll rows, ll cols);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, m, s;
    cin >> n >> m >> s;
    // n rows and m cols
    vector<v_ll> matrix(n, v_ll(m, 0));  // 2d matrix
    FOR(i, n, 0) {
        FOR(j, m, 0) { cin >> matrix[i][j]; }
    }
    submatrix_sum_count(matrix, s);
    matrix.clear();
    return 0;
}

void print_matrix(vector<v_ll> &matrix) {
    ll n = matrix.size(), m = matrix[0].size();
    FOR(i, n, 0) {
        FOR(j, m, 0) { cout << matrix[i][j] << " "; }
        NXT_LINE;
    }
}

void submatrix_sum_count(vector<v_ll> &matrix, ll s) {
    // !TLE
    // !T(N) = O(N^4)
    // !S(N) = O(1)
    // count sqaure submatrix sum below s
    // TODO : calculate prefix_sum matrix
    ll rows = matrix.size(), cols = matrix[0].size(), mx_rows = -1, s_row = -1,
       s_col = -1;
    prefix_sum_matrix(matrix, rows, cols);
    // TODO : for every i,j iterate over for sc and sr
    FOR(er, rows, 0) {
        FOR(ec, cols, 0) {
            FOR(sr, er + 1, 0) {
                FOR(sc, ec + 1, 0) {
                    if (ec == sc && er == sr) {
                        // // !This is a sqaure matrix
                        // // calculate the individual value
                        // ll value = matrix[er][ec];
                        // if (er - 1 >= 0) {
                        //     value -= matrix[er - 1][ec];
                        // }
                        // if (ec - 1 >= 0) {
                        //     value -= matrix[er][ec - 1];
                        // }
                        // if (ec - 1 >= 0 && er - 1 >= 0) {
                        //     value += matrix[er - 1][ec - 1];
                        // }
                        // if (value <= s) {
                        //     // * can count as per condition
                        //     if (mx_rows < er - sr) {
                        //         mx_rows = er - sr;
                        //         s_row = sr;
                        //         s_col = sc;
                        //     } else if (mx_rows == er - sr) {
                        //         if (s_row > sr) {
                        //             s_row = sr;
                        //             s_col = sc;
                        //         } else if (s_row == sr) {
                        //             if (s_col > sc) {
                        //                 s_col = sc;
                        //                 s_row = sr;
                        //             }
                        //         }
                        //     }
                        // }
                        continue;
                        // ! should not take 1 X 1 as square matrix
                    } else if (er - sr == ec - sc) {
                        // !This is a square matrix
                        // TODO : calculate the sum of this square matrix
                        ll sum = matrix[er][ec];
                        if (sc - 1 >= 0) {
                            sum -= matrix[er][sc - 1];
                        }
                        if (sr - 1 >= 0) {
                            sum -= matrix[sr - 1][ec];
                        }
                        if (sr - 1 >= 0 && sc - 1 >= 0) {
                            sum += matrix[sr - 1][sc - 1];
                        }
                        if (sum <= s) {
                            // * can count as per condition
                            if (mx_rows < er - sr) {
                                mx_rows = er - sr;
                                s_row = sr;
                                s_col = sc;
                            } else if (mx_rows == er - sr) {
                                if (s_row > sr) {
                                    s_row = sr;
                                    s_col = sc;
                                } else if (s_row == sr) {
                                    if (s_col > sc) {
                                        s_col = sc;
                                        s_row = sr;
                                    }
                                }
                            }
                            // deb2(sr, sc);
                            // deb2(er, ec);
                            // deb(sum);
                            // NXT_LINE;
                        }
                    }
                }
            }
        }
    }
    if (mx_rows == -1) {
        // ! no square matrix found
        cout << "-1"
             << "\n";
    } else {
        cout << mx_rows + 1 << "\n";
        cout << s_row + 1 << " " << s_col + 1 << "\n";
    }
}

void prefix_sum_matrix(vector<v_ll> &matrix, ll rows, ll cols) {
    // !T(N) = O(N^2)
    // !S(N) = O(1)
    FOR(i, rows, 0) {
        FOR(j, cols, 0) {
            if (i == 0 || j == 0) {
                if (i == 0 && j == 0) {
                    continue;
                } else if (i == 0) {
                    matrix[i][j] += matrix[i][j - 1];
                } else {
                    matrix[i][j] += matrix[i - 1][j];
                }
            } else {
                matrix[i][j] = matrix[i][j] + matrix[i - 1][j] +
                               matrix[i][j - 1] - matrix[i - 1][j - 1];
            }
        }
    }
}