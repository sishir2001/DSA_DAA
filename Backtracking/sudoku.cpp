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
void print_set(vector<set<int>> &vect_set);
void sudoku(vector<v_ll> &matrix);
bool helper(vector<v_ll> &matrix, vector<set<int>> &rows,
            vector<set<int>> &cols, vector<set<int>> &m_hash, ll i, ll j);
ll get_index(ll i, ll j);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll T;
    cin >> T;
    while (T) {
        // n rows and m cols
        vector<v_ll> matrix(9, v_ll(9, 0));  // 2d matrix
        FOR(i, 9, 0) {
            FOR(j, 9, 0) { cin >> matrix[i][j]; }
        }
        sudoku(matrix);
        print_matrix(matrix);
        NXT_LINE;
        matrix.clear();
        T--;
    }
    return 0;
}

void print_matrix(vector<v_ll> &matrix) {
    FOR(i, 9, 0) {
        FOR(j, 9, 0) { cout << matrix[i][j] << " "; }
        NXT_LINE;
    }
}

void sudoku(vector<v_ll> &matrix) {
    // TODO : create sets for rows cols and m_hash
    vector<set<int>> rows(9, set<int>()), cols(9, set<int>()),
        m_hash(9, set<int>());
    // TODO : traverse the matrix to update the hashes
    FOR(i, 9, 0) {
        FOR(j, 9, 0) {
            if (matrix[i][j] == 0)
                continue;
            // TODO : find out the index for m_hash
            ll index = get_index(i, j);
            // TODO adding the element to rows cols and m_hash
            rows[i].insert(matrix[i][j]);
            cols[j].insert(matrix[i][j]);
            m_hash[index].insert(matrix[i][j]);
        }
    }
    helper(matrix, rows, cols, m_hash, 0, 0);
}

bool helper(vector<v_ll> &matrix, vector<set<int>> &rows,
            vector<set<int>> &cols, vector<set<int>> &m_hash, ll i, ll j) {
    // !BruteForce solution
    // !S(N) = O(N^2)
    if (j == 9) {
        return helper(matrix, rows, cols, m_hash, i + 1, 0);
    }
    if (i == 9)
        return true;

    if (matrix[i][j] != 0)
        return helper(matrix, rows, cols, m_hash, i, j + 1);

    FOR(k, 10, 1) {
        // TODO : check the validity of the value
        // TODO : find the index for m_hash
        ll index = get_index(i, j);
        if (rows[i].find(k) != rows[i].end() ||
            cols[j].find(k) != cols[j].end() ||
            m_hash[index].find(k) != m_hash[index].end())
            continue;

        // TODO : insert the element in the respective sets
        rows[i].insert(k);
        cols[j].insert(k);
        m_hash[index].insert(k);
        matrix[i][j] = k;
        bool sub_res = helper(matrix, rows, cols, m_hash, i, j + 1);
        if (sub_res)
            return true;
        rows[i].erase(k);
        cols[j].erase(k);
        m_hash[index].erase(k);
        matrix[i][j] = 0;
    }
    return false;
}

ll get_index(ll i, ll j) {
    // TODO : find out the index for m_hash
    ll index = 0;
    if ((i >= 0 && i <= 2) && (j >= 0 && j <= 2))
        index = 0;
    else if ((i >= 0 && i <= 2) && (j >= 3 && j <= 5))
        index = 1;
    else if ((i >= 0 && i <= 2) && (j >= 6 && j <= 8))
        index = 2;
    else if ((i >= 3 && i <= 5) && (j >= 0 && j <= 2))
        index = 3;
    else if ((i >= 3 && i <= 5) && (j >= 3 && j <= 5))
        index = 4;
    else if ((i >= 3 && i <= 5) && (j >= 6 && j <= 8))
        index = 5;
    else if ((i >= 6 && i <= 8) && (j >= 0 && j <= 2))
        index = 6;
    else if ((i >= 6 && i <= 8) && (j >= 3 && j <= 5))
        index = 7;
    else if ((i >= 6 && i <= 8) && (j >= 6 && j <= 8))
        index = 8;
    return index;
}

void print_set(vector<set<int>> &vect_set) {
    for (auto s : vect_set) {
        for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
            cout << *it << " ";
        }
        NXT_LINE;
    }
}