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
void spiral_print(vector<v_ll> &matrix);
void spiral_print_1(vector<v_ll> &matrix);

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
        spiral_print(matrix);
        spiral_print_1(matrix);
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

void spiral_print(vector<v_ll> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    int rl = 0, cl = 0, rh = n - 1, ch = m - 1;
    while (rl <= rh && cl <= ch) {
        FOR(j, ch + 1, cl) { cout << matrix[rl][j] << " "; }
        FOR(i, rh + 1, rl + 1) { cout << matrix[i][ch] << " "; }
        if (rl != rh) {
            FOR_REV(j, ch, cl) { cout << matrix[rh][j] << " "; }
        }
        if (ch != cl) {
            FOR_REV(i, rh, rl + 1) { cout << matrix[i][cl] << " "; }
        }
        rl++;
        cl++;
        rh--;
        ch--;
    }
    NXT_LINE;
}

void spiral_print_1(vector<v_ll> &matrix) {
    int top = 0, bottom = matrix.size() - 1, left = 0,
        right = matrix[0].size() - 1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
            cout << matrix[top][j] << " ";
        }
        top++;
        if(top >bottom)
            break;
        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";
        }
        right--;
        if(left > right)
            break;
        for (int j = right; j >= left; j--) {
            cout << matrix[bottom][j] << " ";
        }
        bottom--;
        if(top > bottom)
            break;
        for (int i = bottom; i >= top; i--) {
            cout << matrix[i][left] << " ";
        }
        left++;
    }
    NXT_LINE;
}