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

ll helper(ll n, ll i, vector<p_ll> &vec_pair);
ll n_queens_ways(ll n);

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
        cout << n_queens_ways(n) << "\n";
        T--;
    }
    return 0;
}

ll helper(ll n, ll i, vector<p_ll> &vec_pair) {
    if (i == n) {
        // cout << "Got solution \n";
        return 1;
    }
    ll count = 0;
    p_ll p;
    FOR(j, n, 0) {
        // Checking eligibility of i,j
        bool is_continue = false;
        for (auto num : vec_pair) {
            ll a = abs(i - num.first), b = abs(j - num.second);
            if (i == num.first || j == num.second || a == b) {
                is_continue = true;
                break;
            }
        }
        if (is_continue)
            continue;
        // TODO : adding the i,j to vec_pair
        p.first = i;
        p.second = j;
        vec_pair.PB(p);
        count += helper(n, i + 1, vec_pair);
        vec_pair.PPB();
    }
    return count;
}
ll n_queens_ways(ll n) {
    vector<p_ll> vec_pair;
    return helper(n, 0, vec_pair);
}