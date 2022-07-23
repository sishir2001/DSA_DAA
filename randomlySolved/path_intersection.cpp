#include <bits/stdc++.h>
using namespace std;

int client(vector<vector<int>> &nums);

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<pair<int, int>> nums(n);
    pair<int, int> p;
    for (int i = 0; i < n; i++) {
        cin >> p.first >> p.second;
        nums[i] = p;
    }
    int res = client(nums);
    cout << res << "\n";
    nums.clear();
}

int client(vector<vector<int>> &nums) {
    int n = nums.size(), count = 0;
    vector<int> temp = nums[1];
    for (int i = 1; i < n; i++) {
        if (nums[i][0] <= temp[1] && nums[i][0] >= temp[0]) {
            temp[0] = min(temp[0], nums[i][0]);
            temp[1] = max(temp[1], nums[i][1]);
        } else {
            temp[0] = nums[i][0];
            temp[1] = nums[i][1];
            count++;
        }
    }
    return count;
}