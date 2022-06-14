// using inbuilt search functions
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 3, 4, 5, 6, 3, 2};
    int key = 3;
    // ? the inbuild function for doing a linear search is like a pointer
    // [v.begin(),v.end()) range
    vector<int>::iterator it = find(v.begin(), v.end(), key);
    if (it != v.end()) {
        cout << "Found the key : " << it - v.begin() << "\n";
    } else {
        cout << "Not Found the key "
             << "\n";
    }

    // using inbuilt binary search
    sort(v.begin(), v.end());
    if (binary_search(v.begin(), v.end(), 10)) {
        cout << "Found"
             << "\n";
    } else {
        cout << "Not found \n";
    }
    return 0;
}
