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

int max_pizza_with_money(v_int &count, v_int &price, int n, int K);
int max_pizza(v_int &count, v_int &price, int n, int K);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    int T, K;
    string s;
    cin >> T;
    while (T) {
        cin >> s;
        int n = s.length();
        deb(n);
        v_int count(n, 0), price(n, 0);
        FOR(i, n, 0)
        cin >> count[i];
        FOR(i, n, 0)
        cin >> price[i];
        cin >> K;
        int total = max_pizza(count, price, n, K);
        deb(total);
        T--;
    }
    return 0;
}

int max_pizza(v_int &count, v_int &price, int n, int K) {
    // TODO : find maximum pizza without money
    int mx1 = count[0];
    FOR(i, n, 1) { mx1 = min(mx1, count[i]); }
    FOR(i, n, 0) { count[i] -= mx1; }
    deb(mx1);
    int mx2 = max_pizza_with_money(count, price, n, K);
    deb2(mx1, mx2);
    return mx1 + mx2;
}

int max_pizza_with_money(v_int &count, v_int &price, int n, int K) {
    deb(K);
    if (K < 0)
        return -1;
    int res = count[0];
    FOR(i, n, 1) { res = min(res, count[i]); }
    if (K == 0) {
        return res;
    }
    FOR(i, n, 0) {
        count[i]++;
        int sub_res = max_pizza_with_money(count, price, n, K - price[i]);
        count[i]--;
        if (sub_res != -1)
            res = max(res, sub_res);
        deb(res);
    }
    return res;
}