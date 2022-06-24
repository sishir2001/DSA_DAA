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
void merge_2d_array(vector<v_ll> &nums, ll si, ll sj, ll ei, ll ej);
void merge_rows(vector<v_ll> &nums, ll si, ll sj, ll ei, ll ej);
void merge_cols(vector<v_ll> &nums, ll si, ll sj, ll ei, ll ej);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, m;
    cin >> n >> m;
    // n rows and m cols
    vector<v_ll> matrix(n, v_ll(m, 0));  // 2d matrix
    FOR(i, n, 0) {
        FOR(j, m, 0) { cin >> matrix[i][j]; }
    }
    merge_2d_array(matrix, 0, 0, n - 1, m - 1);
    print_matrix(matrix);
    matrix.clear();
    return 0;
}

void print_matrix(vector<v_ll> &matrix) {
    ll n = matrix.size(), m = matrix[0].size();
    FOR(i, n, 0) {
        FOR(j, m, 0) { cout << matrix[i][j] << " "; }
    }
    NXT_LINE;
}

void merge_2d_array(vector<v_ll> &nums, ll si, ll sj, ll ei, ll ej) {
    if (si >= ei && sj >= ej)
        return;
    // I
    ll cols_mid = (ej + sj) / 2, row_mid = (si + ei) / 2;
    merge_2d_array(nums, si, sj, row_mid, cols_mid);
    // II
    merge_2d_array(nums, si, cols_mid + 1, row_mid, ej);
    // III
    merge_2d_array(nums, row_mid + 1, sj, ei, cols_mid);
    // IV
    merge_2d_array(nums, row_mid + 1, cols_mid + 1, ei, ej);
    merge_rows(nums, si, sj, ei, ej);
    merge_cols(nums, si, sj, ei, ej);
}
void merge_rows(vector<v_ll> &nums, ll si, ll sj, ll ei, ll ej) {
    // !T(N) = O(N*M)
    // !S(N) = O(M)
    ll mid = (sj + ej) / 2;
    ll n = mid - sj + 1, m = ej - mid;
    v_ll f(n, 0), s(m, 0);
    for (int i = si; i <= ei; i++) {
        // * COPYING THE ELEMENTS
        for (int j = sj; j <= mid; j++) {
            f[j - sj] = nums[i][j];
        }
        for (int j = mid + 1; j <= ej; j++) {
            s[j - mid - 1] = nums[i][j];
        }
        // * merging the elements into the original matrix
        ll l = 0, r = 0, k = sj;
        while (l < n && r < m) {
            if (f[l] <= s[r])
                nums[i][k++] = f[l++];
            else
                nums[i][k++] = s[r++];
        }
        while (l < n) nums[i][k++] = f[l++];
        while (r < m) nums[i][k++] = s[r++];
    }
}

void merge_cols(vector<v_ll> &nums, ll si, ll sj, ll ei, ll ej) {
    // !T(N) = O(N*M)
    // !S(N) = O(N)
    ll mid = (si + ei) / 2;
    ll n = mid - si + 1, m = ei - mid;
    v_ll f(n, 0), s(m, 0);
    for (int j = sj; j <= ej; j++) {
        // *Copying the elements
        for (int i = si; i <= mid; i++) {
            f[i - si] = nums[i][j];
        }
        for (int i = mid + 1; i <= ei; i++) {
            s[i - mid - 1] = nums[i][j];
        }

        // * merging the elements into the original matrix
        ll l = 0, r = 0, k = si;
        while (l < n && r < m) {
            if (f[l] <= s[r])
                nums[k++][j] = f[l++];
            else
                nums[k++][j] = s[r++];
        }
        while (l < n) nums[k++][j] = f[l++];
        while (r < m) nums[k++][j] = s[r++];
    }
}