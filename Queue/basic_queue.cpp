#include <bits/stdc++.h>

#include "queueArr.h"
#include "queueLL.h"

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // Queue_LL<int> *q_ll = new Queue_LL<int>();
    // Queue_arr<int> *q_arr = new Queue_arr<int>(5);
    queue<int> q;
    // q_ll->push(1);
    // q_arr->push(1);
    // q_ll->push(2);
    // q_arr->push(2);
    // q_ll->push(3);
    // q_arr->push(3);
    // q_arr->push(4);
    // q_ll->push(4);
    // q_ll->print_queue();
    // q_arr->print_queue();
    // cout << q_arr->pop() << "\n";
    // cout << q_arr->pop() << "\n";
    // cout << q_arr->pop() << "\n";
    // cout << q_arr->pop() << "\n";
    // q_arr->push(1);
    // q_arr->push(3);
    // q_arr->print_queue();

    q.push(1);
    q.push(1);
    q.push(2);
    q.push(3);
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
    return 0;
}