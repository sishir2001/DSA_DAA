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
void rotate_90_clockwise(vector<v_ll> &matrix);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // ! Inplace rotation of the matrix
    ll n, m;
    cin >> n >> m;
    // n rows and m cols
    vector<v_ll> matrix(n, v_ll(m, 0));  // 2d matrix
    FOR(i, n, 0) {
        FOR(j, m, 0) { cin >> matrix[i][j]; }
    }
    print_matrix(matrix);
    NXT_LINE;
    rotate_90_clockwise(matrix);
    print_matrix(matrix);
    matrix.clear();
    return 0;
}

void print_matrix(vector<v_ll> &matrix) {
    ll n = matrix.size();
    FOR(i, n, 0) {
        FOR(j, n, 0) { cout << matrix[i][j] << " "; }
        NXT_LINE;
    }
}

void rotate_90_clockwise(vector<v_ll> &matrix) {
    // * inplace
    // !T(N) = O(N^2)
    // @matrix : square matrix
    ll n = matrix.size();
    ll a = 0, b = n - 1;
    while (a < b) {
        for (ll i = 0; i < (b - a); i++) {
            swap(matrix[a][a + i], matrix[a + i][b]);
            swap(matrix[a][a + i], matrix[b][b - i]);
            swap(matrix[a][a + i], matrix[b - i][a]);
        }
        a++;
        b--;
    }
}