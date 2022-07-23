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

int leftmost_repeating(string s) {
    v_int h(26, 0);
    for (int i = 0; i < s.size(); i++) {
        h[s[i] - 'a']++;
    }
    int idx = -1;
    for (int i = 0; i < s.size(); i++) {
        if (h[s[i] - 'a'] > 1) {
            idx = i;
            break;
        }
    }
    return idx;
}

int leftmost_repeating_effe(string s);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    string s;
    cin >> T;
    while (T) {
        cin >> s;
        int res = leftmost_repeating(s);
        int res_effe = leftmost_repeating_effe(s);
        deb2(res, res_effe);
        T--;
    }
    return 0;
}

int leftmost_repeating_effe(string s) {
    // !T(N) = O(N) single traversing
    v_int h(26, -1);
    int mn = -1;
    for (int i = 0; i < s.size(); i++) {
        if (h[s[i] - 'a'] == -1)
            h[s[i] - 'a'] = i;
        else {
            mn = mn == -1 ? h[s[i] - 'a'] : min(mn, h[s[i] - 'a']);
        }
    }
    return mn;
}