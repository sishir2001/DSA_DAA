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
#define F        first
#define S        second
#define PB       push_back                         // for vector
#define PPB      pop_back                          // for vector
#define mod      1000000007                        // 1e9+7
#define deb(x)   cout << #x << " = " << x << "\n"  // for debugging
#define deb2(x, y)                                        \
    cout << #x << " = " << x << " , " << #y << " = " << y \
         << "\n"                                          // for debugging
#define FOR(a, end) for (int(a) = 0; (a) < (end); (a)++)  // regular for loop
#define FOR_REV(a, start) \
    for (int(a) = (start)-1; (a) >= 0; (a)--)  // regular for loop decreasing
#define FOR_less(a, end, start) \
    for (int(a) = (start); (a) < (end); (a)++)  // regular for loop
#define FOR_REV_great(a, end, start) \
    for (int(a) = (start); (a) > (end); (a)--)  // regular for loop
#define FOR_less_or_equal(a, end, start) \
    for (int(a) = (start); (a) <= (end); (a)++)  // regular for loop
#define FOR_REV_great_or_equal(a, end, start) \
    for (int(a) = (start); (a) >= (end); (a)--)  // regular for loop

void print(ll nums[][100], ll n, ll m);
bool staircase_search(ll nums[][100], ll n, ll m, ll search_key);
bool search_matrix(ll nums[][100], ll n, ll m, ll search_key);
bool search_matrix_effe(ll nums[][100], ll n, ll m, ll search_key);
ll nearest_smallest(ll nums[][100], ll n, ll search_key);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    bool tr = true, fl = false;
    deb2(tr, fl);
    ll T, n, m, search_key;
    cin >> T;
    while (T) {
        // n rows and m cols
        cin >> n >> m >> search_key;
        ll a[100][100];
        // reading the input
        FOR(i, n) {
            FOR(j, m) { cin >> a[i][j]; }
        }

        // printing the input
        print(a, n, m);
        cout << ((search_matrix(a, n, m, search_key) ==
                  staircase_search(a, n, m, search_key))
                     ? "passed"
                     : "failed");
        T--;
    }
    return 0;
}

void print(ll nums[][100], ll n, ll m) {
    FOR(i, n) {
        FOR(j, m) { cout << nums[i][j] << " "; }
        NXT_LINE;
    }
}

bool staircase_search(ll nums[][100], ll n, ll m, ll search_key) {
    // @n : rows of the matrix
    // @m : columns of the matrix
    // !T(N) = O(M+N) linear-time search
    ll i = 0, j = m - 1;
    while (i < n && j >= 0) {
        if (nums[i][j] == search_key)
            return true;
        else if (nums[i][j] < search_key)
            i++;
        else
            j--;
    }
    return false;
}

bool search_matrix(ll nums[][100], ll n, ll m, ll search_key) {
    // @n : rows of the matrix
    // @m : columns of the matrix
    // !T(N) = O(N*logM)
    FOR(i, n) {
        ll l = 0, r = m - 1;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (nums[i][mid] == search_key) {
                return true;
            } else if (nums[i][mid] < search_key) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return false;
}

bool search_matrix_effe(ll nums[][100], ll n, ll m, ll search_key) {
    // @n : rows of the matrix
    // @m : columns of the matrix
    // @search_key : element that needs to be searched
    // !T(N) = O(N*logM)
    // ! more efficient than search_matrix()

    // ? find the closest smaller number to search key in the rows and iterate
    // till that index
    ll row_limit = nearest_smallest(nums, n, search_key);
    FOR(i, row_limit) {
        // using binary search
        ll l = 0, r = m - 1;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (nums[i][mid] == search_key) {
                return true;
            } else if (nums[i][mid] < search_key) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return false;
}

ll nearest_smallest(ll nums[][100], ll n, ll search_key) {
    // !T(N) = O(logn)
    // using binary search to find the nearest smallest
    ll l = 0, r = n - 1, m = 0;
    while (l <= r) {
        m = (l + r) / 2;
        if (nums[m][0] == search_key)
            return m;
        else if (nums[m][0] < search_key)
            l = m + 1;
        else {
            if (m == 0)
                return -1;
            else if (nums[m - 1][0] < search_key)
                return m - 1;
            else {
                r = m - 1;
            }
        }
    }
    return m;
}