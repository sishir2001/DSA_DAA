#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> makeZeroes(vector<vector<int>> arr){
    set<int> rows,cols;
    int n = arr.size(),m = arr[0].size();
    for(int i = 0;i<n;i++){
        for(int j = 0;j < m;j++){
            if(arr[i][j] == 0){
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    set<int>::iterator it;
    for(it = rows.begin();it!=rows.end();it++){
        for(int i = 0;i < m;i++){
            arr[*it][i] = 0;
        }
    }
    for(it = cols.begin();it!=cols.end();it++){
        for(int i = 0; i < n;i++){
            arr[i][*it] = 0;
        }
    }
    return arr;
}