#include <bits/stdc++.h>

#include "stackLL.h"
#include "stackV.h"

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
    Stack<int> *s = new Stack<int>();
    Stack_V<int> *s1 = new Stack_V<int>();
    s->push(1);
    s1->push(1);
    s->push(2);
    s1->push(2);
    s->push(3);
    s1->push(3);
    s->push(4);
    s1->push(4);

    cout << "s : ";
    s->print_stack();

    cout << "s1 : ";
    s1->print_stack();

    s->pop();
    s1->pop();

    cout << "s : ";
    s->print_stack();

    cout << "s1 : ";
    s1->print_stack();

    deb(s->is_empty());
    deb(s1->is_empty());
    return 0;
}