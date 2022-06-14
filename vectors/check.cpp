#include <iostream>

#include "vector.h"

int main() {
    Vector<int> v(4);
    v.Push_Back(1);
    v.Push_Back(2);
    v.Push_Back(3);
    v.Print();
    Vector<string> s(4);
    s.Push_Back("Sishir");
    cout << s[0] << "\n";
    return 0;
}