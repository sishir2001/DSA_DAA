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

void print_matrix(vector<string> &matrix, ll n, ll m);
void print_path_matrix(vector<p_ll> &vec_pair, ll n, ll m);
void rat_mice(vector<string> &matrix, ll n, ll m);
bool helper(vector<string> &matrix, vector<p_ll> &vec_pair, ll prev_i,
            ll prev_j, ll i, ll j, ll n, ll m);
void check_direction(vector<bool> &from, ll prev_i, ll prev_j, ll i, ll j);

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
    vector<string> matrix;
    while (T) {
        cin >> n >> m;
        FOR(i, n, 0) {
            string temp;
            cin >> temp;
            matrix.PB(temp);
        }
        rat_mice(matrix, n, m);
        NXT_LINE;
        matrix.clear();
        T--;
    }
    return 0;
}

void print_matrix(vector<string> &matrix, ll n, ll m) {
    FOR(i, n, 0) { cout << matrix[i] << "\n"; }
    NXT_LINE;
}

void print_path_matrix(vector<p_ll> &vec_pair, ll n, ll m) {
    vector<v_ll> arr(n, v_ll(m, 0));
    for (auto num : vec_pair) {
        arr[num.first][num.second] = 1;
    }
    FOR(i, n, 0) {
        FOR(j, m, 0) { cout << arr[i][j] << " "; }
        NXT_LINE;
    }
}

void rat_mice(vector<string> &matrix, ll n, ll m) {
    vector<p_ll> vec_pair;
    bool res = helper(matrix, vec_pair, 0, 0, 0, 0, n, m);
    if (res)
        print_path_matrix(vec_pair, n, m);
    else {
        cout << "Not found any result \n";
    }
}
bool helper(vector<string> &matrix, vector<p_ll> &vec_pair, ll prev_i,
            ll prev_j, ll i, ll j, ll n, ll m) {
    // * base case
    p_ll p;
    if (i == n - 1 && j == m - 1) {
        p.first = i;
        p.second = j;
        vec_pair.PB(p);
        return true;
    }
    if (i == n || j == m || i == -1 || j == -1 || matrix[i][j] == 'X')
        return false;
    // TODO : add i and j to path
    // getting a vector for boolean
    vector<bool> from(4, false), now(4, false);
    // top = 0,right = 1,down=2,left = 3
    // TODO : check from which direction the path is coming from
    check_direction(from, prev_i, prev_j, i, j);
    p.first = i;
    p.second = j;
    vec_pair.PB(p);

    // right
    if (!from[1]) {
        now[1] = helper(matrix, vec_pair, i, j, i, j + 1, n, m);
        if (now[1])
            return true;
    }
    // down
    if (!from[2]) {
        now[2] = helper(matrix, vec_pair, i, j, i + 1, j, n, m);
        if (now[2])
            return true;
    }
    // left
    if (!from[3]) {
        now[3] = helper(matrix, vec_pair, i, j, i, j - 1, n, m);
        if (now[3])
            return true;
    }
    // top
    if (!from[0]) {
        now[0] = helper(matrix, vec_pair, i, j, i - 1, j, n, m);
        if (now[0])
            return true;
    }
    vec_pair.PPB();
    return false;
}

void check_direction(vector<bool> &from, ll prev_i, ll prev_j, ll i, ll j) {
    ll di = i - prev_i, dj = j - prev_j;
    if (di == 0 && dj == -1)
        from[1] = true;
    else if (di == 0 && dj == 1)
        from[3] = true;
    else if (di == 1 && dj == 0)
        from[0] = true;
    else if (di == -1 && dj == 0)
        from[2] = true;
}