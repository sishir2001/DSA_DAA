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
ll maximal_rectangle(vector<v_ll> &nums, ll si, ll sj, ll ei, ll ej, ll rows,
                     ll cols);

ll maximal_rectangle_effe(vector<v_ll> &nums);

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
        cout << maximal_rectangle(matrix, 0, 0, n - 1, m - 1, n, m) << " "
             << maximal_rectangle_effe(matrix) << "\n";
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

ll maximal_rectangle(vector<v_ll> &nums, ll si, ll sj, ll ei, ll ej, ll rows,
                     ll cols) {
    // !Brute force using backtracking
    // !T(N) = ?? 
    // !S(N) = O(1)
    if (si >= rows || sj >= cols || ej < 0 || ei < 0)
        return 0;
    ll mx_rec = 0;
    FOR(i, ei + 1, si) {
        FOR(j, ej + 1, sj) {
            if (nums[i][j] == 0) {
                mx_rec = max(mx_rec, j - sj);
                // right
                ll right =
                       maximal_rectangle(nums, si, sj + 1, ei, ej, rows, cols),
                   down =
                       maximal_rectangle(nums, si + 1, sj, ei, ej, rows, cols);
                mx_rec = max(mx_rec, max(down, right));
                return mx_rec;
            }
        }
        mx_rec = max(mx_rec, (i - si + 1) * (ej - sj + 1));
    }
    return mx_rec;
}

ll maximal_rectangle_effe(vector<v_ll> &nums) {
    // !T(N) = O(N*M)
    // !S(N) = O(M);
    // approach from maximum rectangle size in a histogram
    int n = nums.size(), m = nums[0].size(), mx = 0;
    FOR(i, n, 0) {
        stack<int> s;  // contains indexes
        s.push(-1);
        int mx_area = 0;
        // TODO : modify the row elements
        FOR(j, m, 0) {
            nums[i][j] = i == 0              ? nums[i][j]
                         : (nums[i][j] == 0) ? 0
                                             : nums[i - 1][j] + 1;
            while (s.top() != -1 && nums[i][j] <= nums[i][s.top()]) {
                // left limit = s.top(),right limit = j
                int k = nums[i][s.top()];
                s.pop();
                int area = k * (j - s.top() - 1);
                mx_area = max(mx_area, area);
            }
            s.push(j);
        }
        // checking for remaining elements in stack
        // right limit = m left limit = s.top()
        while (s.top() != -1) {
            int k = nums[i][s.top()];
            s.pop();
            int area = k * (m - s.top() - 1);
            mx_area = max(mx_area, area);
        }
        mx = max(mx, mx_area);
    }
    return mx;
}