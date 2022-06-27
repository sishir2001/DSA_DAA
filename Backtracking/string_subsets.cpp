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

void subsets(string &s, int i, string res);
void subsets_char(char *s, int i, int j, char *res, vector<string> &v);
void print_vector(vector<string> &nums);
bool compare(string a, string b) {
    if (a.length() < b.length() || a.length() > b.length())
        return a.length() < b.length();
    return a < b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T, n;
    string s;
    cin >> T;
    vector<string> v;
    while (T) {
        cin >> n;
        char *s = new char[n + 1], *res = new char[n + 1];
        cin >> s;
        subsets_char(s, 0, 0, res, v);
        sort(v.begin(), v.end(), compare);
        print_vector(v);
        // subsets(s, 0, "");
        v.clear();
        T--;
    }
    return 0;
}

void subsets(string &s, int i, string res) {
    if (i == s.length()) {
        cout << res << " ";
        return;
    }
    subsets(s, i + 1, res);
    subsets(s, i + 1, res + s[i]);
    return;
}

void subsets_char(char *s, int i, int j, char *res, vector<string> &v) {
    if (s[i] == '\0') {
        // print
        res[j] = '\0';
        string temp(res);
        v.PB(temp);
        return;
    }

    // adding the current
    res[j] = s[i];
    subsets_char(s, i + 1, j + 1, res, v);
    subsets_char(s, i + 1, j, res, v);
    return;
}

void print_vector(vector<string> &nums) {
    for (auto i : nums) {
        cout << i << ",";
    }
    NXT_LINE;
}