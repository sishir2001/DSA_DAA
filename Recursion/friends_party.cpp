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

int nC2(int n) { return n * (n - 1) / 2; }

double friends_party(int n, int k = 1) {
    // !T(N) = O(N)
    // !S(N) = O(N)
    if (n == 0 || n == 1)
        return 0;
    double res = friends_party(n - 2, k + 1);
    return (double)nC2(n) * (1 + res) / k;
}

p_int recurrence(int n);
int friends_party_2(int n);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T, n;
    cin >> T;
    while (T) {
        cin >> n;
        double res = friends_party(n) + 1;
        cout << res << "\n";
        cout << friends_party_2(n) << "\n";
        T--;
    }
    return 0;
}

p_int recurrence(int n) {
    // ! F(N) = F(N-1)+(N-1)*F(N-2)
    // !T(N) = O(N)
    // !S(N) = O(N)

    p_int res, p;
    if (n == 1) {
        res.first = 1;
        res.second = 1;
        return res;
    }
    p = recurrence(n - 1);
    res.second = p.first;
    res.first = p.first + (n - 1) * p.second;
    return res;
}
int friends_party_2(int n) {
    p_int res = recurrence(n);
    return res.first;
}