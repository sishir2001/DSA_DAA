#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> v_i;

int sansaXor(v_i arr){
    // T(n) = O(n)
    int res = 0;
    if(((arr.size())&1) == 1){
       // if size is odd
       int i=0;
       while(i<arr.size()){
           res = res^arr[i];
           i = i+2;
       }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n,x;
    cin >> t;

    while(t--){
        cin >> n;
        v_i arr;
        for(int i = 0;i<n;i++){
            cin >> x;
            arr.push_back(x);
        }
        cout << sansaXor(arr)<<"\n";
    }
    return 0;
}