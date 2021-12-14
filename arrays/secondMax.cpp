// find the second largest element of the array 

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
// typedef vector<ll> v_ll;

#define mod 1000000007 // 1e9+7
#define deb(x) cout << #x << " = "<<x<<"\n" // for debugging
#define deb2(x,y) cout << #x << " = "<<x << " , " << #y << " = " << y <<"\n" // for debugging 
#define FOR(a,n) for(int (a) = 0;(a) < (n);(a)++) // regular for loop
#define FOR_Custom(a,n,start) for(int (a) = (start);(a) < (n);(a)++) // regular for loop

int secondMaxElement(int *arr,int n){
    // @param arr : pointer to an array
    // @param n : size of the array
    // * T(N) = O(N)

    int f_max = 0,s_max = -1;
    FOR_Custom(i,n,1){
        if(arr[f_max] > arr[i]){
            // check with s_max
            if(s_max == -1 || arr[s_max] < arr[i])
                s_max = i;
        }
        else if (arr[f_max] < arr[i]){
            s_max = f_max;
            f_max = i;
        }
    }
    return s_max;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,n;
    cin >> T;
    while(T){
        cout << "n : " ;
        cin >> n;
        int arr[n];
        cout << "arr : ";
        FOR(i,n){
            cin >> arr[i];
        }
        cout << secondMaxElement(arr,n) << "\n";
        T--;
    }
    return 0;
}
