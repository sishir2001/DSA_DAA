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

int minimum_cost(int *nums, int n, int c_01, int c_10);
int minimum_cost1(int *nums, int n, int c_01, int c_10);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("minimum_cost1.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T, n, c_01, c_10;
    cin >> T;
    while (T) {
        cin >> n >> c_01 >> c_10;
        int *a = new int[n];
        FOR(i, n) { cin >> a[i]; }
        cout << minimum_cost1(a, n, c_01, c_10) << "\n";
        delete[] a;
        T--;
    }
    return 0;
}

int minimum_cost(int *nums, int n, int c_01, int c_10) {
    int cost = 0;
    if ((nums[0] + nums[1]) == 0) {
        // both are 0's
        if ((n & 1) == 0) {
            // n is even
            if (nums[n - 1] == 0) {
                nums[0] = 1;
            } else {
                nums[1] = 1;
            }
        } else {
            // n is odd
            if (nums[n - 1] == 0) {
                nums[1] = 1;
            } else {
                nums[0] = 1;
            }
        }
        cost = cost + c_01;
    } else if (nums[0] + nums[1] == 2) {
        // both are 1
        if ((n & 1) == 0) {
            // n is even
            if (nums[n - 1] == 1) {
                nums[0] = 0;
            } else {
                nums[1] = 0;
            }
        } else {
            // n is odd
            if (nums[n - 1] == 1) {
                nums[1] = 0;
            } else {
                nums[0] = 0;
            }
        }
        cost += c_10;
    }

    // now from 2nd index
    for (int i = 2; i < n; i++) {
        if ((nums[i - 1] ^ nums[i]) == 0) {
            if (nums[i] == 0) {
                cost += c_01;
                nums[i] = 1;
            } else {
                cost += c_10;
                nums[i] = 0;
            }
        }
    }
    return cost;
}

int minimum_cost1(int *nums, int n, int c_01, int c_10) {
    int k = 0, i = 1, cost = 0;
    while (i < n) {
        int x = nums[i] ^ nums[i - 1];
        if (x == 0) {
            int j = i + 1;
            if (i == n - 1) {
                while (k < i) {
                    if (((i - k) & 1) == 0) {
                        if (nums[k] != nums[i]) {
                            // index k need to change
                            nums[k] = nums[i];
                            if (nums[i] == 1)
                                cost += c_01;
                            else
                                cost += c_10;
                        }
                    } else {
                        if (nums[k] == nums[i]) {
                            // index k need to change
                            nums[k] = nums[i] ^ 1;
                            if (nums[i] == 1)
                                cost += c_10;
                            else
                                cost += c_01;
                        }
                    }
                    k++;
                }
            } else {
                while (j < n) {
                    if ((j == n - 1) ||
                        ((x ^ nums[j]) == 1 && (nums[i] ^ nums[i + 1]) == 1)) {
                        // TODO : loop through j
                        while (k < j) {
                            if (((j - k) & 1) == 0) {
                                if (nums[k] != nums[j]) {
                                    // index k need to change
                                    nums[k] = nums[j];
                                    if (nums[j] == 1)
                                        cost += c_01;
                                    else
                                        cost += c_10;
                                }
                            } else {
                                if (nums[k] == nums[j]) {
                                    // index k need to change
                                    nums[k] = nums[j] ^ 1;
                                    if (nums[j] == 1)
                                        cost += c_10;
                                    else
                                        cost += c_01;
                                }
                            }
                            k++;
                        }
                        i = k++;
                        break;
                    }
                    j++;
                }
            }
        }
        i++;
    }
    return cost;
}