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

string binary_add(string a, string b);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    //   freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
#endif
    string a = "1101", b = "1";
    cout << binary_add(a, b) << "\n";
    return 0;
}

string binary_add(string a, string b) {
    string res = "";
    int i = a.length() - 1, j = b.length() - 1, carry = 0;

    while (i >= 0 && j >= 0) {
        if (a[i] == '1' && b[j] == '1') {
            if (carry == 1) {
                // 3 1's
                carry = 1;
                res = "1" + res;
            } else {
                // 2 1's
                carry = 1;
                res = "0" + res;
            }
        } else if (a[i] == '1' || b[j] == '1') {
            if (carry == 1) {
                // 2 1's
                carry = 1;
                res = "0" + res;
            } else {
                // 1 1's
                carry = 0;
                res = "1" + res;
            }
        } else {
            // both are 0
            if (carry == 1) {
                // 1 1's
                carry = 0;
                res = "1" + res;
            } else {
                // 0 1's
                carry = 0;
                res = "0" + res;
            }
        }
        i--;
        j--;
    }
    while (i >= 0) {
        if (a[i] == '1' && carry == 1) {
            // 2 1's
            carry = 1;
            res = "0" + res;
        } else if (a[i] == '1' || carry == 1) {
            // 1 1's
            carry = 0;
            res = "1" + res;
        } else {
            carry = 0;
            res = "0" + res;
        }
        i--;
    }
    while (j >= 0) {
        if (b[j] == '1' && carry == 1) {
            // 2 1's
            carry = 1;
            res = "0" + res;
        } else if (b[j] == '1' || carry == 1) {
            // 1 1's
            carry = 0;
            res = "1" + res;
        } else {
            carry = 0;
            res = "0" + res;
        }
        j--;
    }
    if (carry == 1) {
        res = "1" + res;
    }
    return res;
}