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

void append_results(vector<p_ll> &matrix, ll n, vector<vector<string>> &res);
void print_matrix(vector<vector<string>> &res);
void n_queens(vector<p_ll> &queens_places, ll n, ll i,
              vector<vector<string>> &res);

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
        vector<p_ll> queens_places;
        vector<vector<string>> res;
        n_queens(queens_places, n, 0, res);
        print_matrix(res);
        queens_places.clear();
        T--;
    }
    return 0;
}

void append_results(vector<p_ll> &matrix, ll n, vector<vector<string>> &res) {
    vector<string> str;
    // ? Initialization of vector string
    FOR(i, n, 0) {
        string temp = "";
        FOR(j, n, 0) { temp += "."; }
        str.PB(temp);
    }
    for (auto i : matrix) {
        str[i.first][i.second] = 'Q';
    }
    res.PB(str);
}

void n_queens(vector<p_ll> &queens_places, ll n, ll i,
              vector<vector<string>> &res) {
    // ! T(N) = O(N^2)
    // !S(N) = O(N)
    // * row wise calculation of the spot
    if (i == n) {
        append_results(queens_places, n, res);
        return;
    }
    p_ll p;
    FOR(j, n, 0) {
        // TODO : calculate the whether this index is valid or not
        bool isContinue = false;
        for (auto coords : queens_places) {
            ll a = abs(i - coords.first), b = abs(j - coords.second);
            if (a == b || i == coords.first || j == coords.second) {
                isContinue = true;
                break;
            }
        }
        if (isContinue)
            continue;

        // * this is index is valid
        p.first = i;
        p.second = j;
        queens_places.PB(p);
        n_queens(queens_places, n, i + 1, res);
        queens_places.PPB();
    }
}

void print_matrix(vector<vector<string>> &res) {
    for (auto i : res) {
        for (auto j : i) {
            cout << j << "\n";
        }
        NXT_LINE;
    }
    NXT_LINE;
}