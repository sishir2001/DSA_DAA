#include<iostream>
#include<vector>
using namespace std;

vector<int> client(vector<int> &nums);

int main(){
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int i = 0;i < n;i++){
        cin >> nums[i];
    }

    nums.clear();
}

vector<int> client(vector<int> &nums){
    int n = nums.size();
    vector<int> res(n,0);
    for(int i = 0;i < n;i++){
        int sum = nums[i]%10;
        nums[i] /= 10;
        while(nums[i]){
            sum += nums[i]%10;
            nums[i] /= 10;
        }
        res[i] = sum;
    }
    return res;
}