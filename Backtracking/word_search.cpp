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

void print_matrix(vector<vector<char> > &matrix);
bool word_search(vector<vector<char> > &matrix, string str, int n, int m, int k,
                 int prev_i, int prev_j, int i, int j,
                 set<pair<int, int> > &visited);
void get_directions(vector<bool> &from, int pi, int pj, int i, int j);
void print_set_pair(set<p_int> &visited) {
    set<p_int>::iterator it = visited.begin();
    for (; it != visited.end(); it++) {
        cout << "(" << it->first << "," << it->second << ") ";
    }
}

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
    bool tr = true, fl = false;
    deb2(tr, fl);
    while (T) {
        string str;
        cin >> n >> m;
        cin >> str;
        // n rows and m cols
        vector<vector<char> > matrix(n, vector<char>(m, '0'));  // 2d matrix
        FOR(i, n, 0) {
            FOR(j, m, 0) { cin >> matrix[i][j]; }
        }
        // word search;
        set<p_int> visited;
        cout << word_search(matrix, str, n, m, 0, 0, 0, 0, 0, visited) << "\n";
        print_set_pair(visited);
        NXT_LINE;
        NXT_LINE;
        matrix.clear();
        visited.clear();
        T--;
    }
    return 0;
}

void print_matrix(vector<vector<char> > &matrix) {
    ll n = matrix.size(), m = matrix[0].size();
    FOR(i, n, 0) {
        FOR(j, m, 0) { cout << matrix[i][j] << " "; }
        NXT_LINE;
    }
}
bool word_search(vector<vector<char> > &matrix, string str, int n, int m, int k,
                 int prev_i, int prev_j, int i, int j,
                 set<pair<int, int> > &visited) {
    pair<int, int> p;
    p.first = i;
    p.second = j;
    if (k == str.length())
        return true;
    if (i == n || i == -1 || j == m || j == -1 ||
        visited.find(p) != visited.end())
        return false;
    vector<bool> from(4, false), now(4, false);
    // top - 0,right-1,down-2,left-3
    if (k == 0) {
        FOR(a, n, 0) {
            FOR(b, m, 0) {
                if (matrix[a][b] != str[k])
                    continue;
                // matches
                p.first = a;
                p.second = b;
                visited.insert(p);
                // top
                now[0] = word_search(matrix, str, n, m, k + 1, a, b, a - 1, b,
                                     visited);
                if (now[0])
                    return true;
                // right
                now[1] = word_search(matrix, str, n, m, k + 1, a, b, a, b + 1,
                                     visited);
                if (now[1])
                    return true;
                // down
                now[2] = word_search(matrix, str, n, m, k + 1, a, b, a + 1, b,
                                     visited);
                if (now[2])
                    return true;
                // left
                now[3] = word_search(matrix, str, n, m, k + 1, a, b, a, b - 1,
                                     visited);
                if (now[3])
                    return true;
                visited.erase(p);
            }
        }
    } else {
        if (matrix[i][j] != str[k])
            return false;

        // matches
        p.first = i;
        p.second = j;
        visited.insert(p);
        get_directions(from, prev_i, prev_j, i, j);
        // top
        if (!from[0]) {
            now[0] =
                word_search(matrix, str, n, m, k + 1, i, j, i - 1, j, visited);
            if (now[0])
                return true;
        }
        // right
        if (!from[1]) {
            now[1] =
                word_search(matrix, str, n, m, k + 1, i, j, i, j + 1, visited);
            if (now[1])
                return true;
        }
        // down
        if (!from[2]) {
            now[2] =
                word_search(matrix, str, n, m, k + 1, i, j, i + 1, j, visited);
            if (now[2])
                return true;
        }
        // left
        if (!from[3]) {
            now[3] =
                word_search(matrix, str, n, m, k + 1, i, j, i, j - 1, visited);
            if (now[3])
                return true;
        }
        visited.erase(p);
    }
    return false;
}

void get_directions(vector<bool> &from, int pi, int pj, int i, int j) {
    int di = i - pi, dj = j - pj;
    // left
    if (di == 0 && dj == 1)
        from[3] = true;
    // right
    else if (di == 0 && dj == -1)
        from[1] = true;
    // top
    else if (di == 1 && dj == 0)
        from[0] = true;
    // down
    else if (di == -1 && dj == 0)
        from[2] = true;
}