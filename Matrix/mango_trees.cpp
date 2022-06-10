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

ll mango_trees(vector<v_ll> &farm, ll n);
void print_matrix(vector<v_ll> &farm, ll n);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // Find the maximum number of trees ramu takes , ramu should take the lowest
    // number of trees of the four
    ll T, n, dimen;
    cin >> T;
    while (T) {
        cin >> dimen >> n;
        // create a 2D vector with default of 0 and map the trees with 1
        vector<v_ll> farm(dimen, v_ll(dimen, 0));
        FOR(i, n, 0) {
            ll a, b;
            cin >> a >> b;
            // TODO : mark the a,b
            // ! taking the coordinates as 0-based index
            farm[a][b] = 1;
        }
        cout << mango_trees(farm, dimen) << "\n";
        farm.clear();
        T--;
    }
    return 0;
}

ll mango_trees(vector<v_ll> &farm, ll dimen) {
    // !T(N) = O(N^2)
    // !S(N) = O(N^2)
    // TODO : calculate a prefix sum matrix
    vector<v_ll> prefix_sum(dimen, v_ll(dimen, 0));
    FOR(i, dimen, 0) {
        FOR(j, dimen, 0) {
            if (i == 0 || j == 0) {
                if (i == 0 && j == 0) {
                    prefix_sum[i][j] = farm[i][j];
                } else if (i == 0) {
                    prefix_sum[i][j] = farm[i][j] + prefix_sum[i][j - 1];
                } else {
                    prefix_sum[i][j] = farm[i][j] + prefix_sum[i - 1][j];
                }
            } else {
                prefix_sum[i][j] = farm[i][j] + prefix_sum[i - 1][j] +
                                   prefix_sum[i][j - 1] -
                                   prefix_sum[i - 1][j - 1];
            }
        }
    }
    // TODO : dividing the matrix into four quadrants and calculating the mx of
    // min
    ll mx_tree = LLONG_MIN;
    FOR(i, dimen - 1, 0) {
        FOR(j, dimen - 1, 0) {
            ll s1 = 0, s2 = 0, s3 = 0, s4 = 0, mn_trees = 0;
            s1 = prefix_sum[i][j];
            s2 = prefix_sum[i][dimen - 1] - s1;
            s3 = prefix_sum[dimen - 1][j] - s1;
            s4 = prefix_sum[dimen - 1][dimen - 1] - s1 - s2 - s3;
            mn_trees = min(s1, min(s2, min(s3, s4)));
            mx_tree = max(mx_tree, mn_trees);
        }
    }
    return mx_tree;
}

void print_matrix(vector<v_ll> &farm, ll dimen) {
    // !T(N) = O(N^2)
    FOR(i, dimen, 0) {
        FOR(j, dimen, 0) { cout << farm[i][j] << " "; }
        NXT_LINE;
    }
}