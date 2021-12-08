// Wrong Approach 
#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

typedef long l;

l minmax(l *arr,l n){
    l mi = LONG_MAX,ma = -1;
    for(l i = 0;i<n;i++){
        mi = min(arr[i],mi);
        ma = max(arr[i],ma);
    }
    return mi^ma;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    l n;
    cin >> n;
    l arr[n];
    for(l i=0;i<n;i++){
        cin >> arr[i];
    }
    // best sorting takes nlogn time , so to find min max - O(n) is better 
    cout << minmax(arr,n);
    return 0;
}