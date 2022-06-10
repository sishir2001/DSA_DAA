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

void shortest_path(char path[], ll n);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    char path[1000];
    cin.getline(path, 1000);
    shortest_path(path, strlen(path));
    return 0;
}

void shortest_path(char path[], ll n) {
    // !T(N) = O(N)
    // !S(N) = O(1)
    // NSWE coordinates
    ll x = 0, y = 0;
    // TODO : traverse the array for directions
    FOR(i, n, 0) {
        switch (path[i]) {
            case 'S':
                x--;
                break;
            case 'N':
                x++;
                break;
            case 'W':
                y--;
                break;
            default:
                y++;
                break;
        }
    }

    // making the shortest path
    if (x < 0) {
        while (x != 0) {
            cout << "S";
            x++;
        }
    } else {
        while (x != 0) {
            cout << "N";
            x--;
        }
    }
    if (y < 0) {
        while (y != 0) {
            cout << "W";
            x++;
        }
    } else {
        while (y != 0) {
            cout << "E";
            y--;
        }
    }
}