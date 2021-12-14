// move zeroes in an array to the end 
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
// typedef vector<ll> v_ll;

#define mod 1000000007 // 1e9+7
#define deb(x) cout << #x << " = "<<x<<"\n" // for debugging
#define deb2(x,y) cout << #x << " = "<<x << " , " << #y << " = " << y <<"\n" // for debugging 
#define FOR(a,end) for(int (a) = 0;(a) < (end);(a)++) // regular for loop
#define FOR_custom_less(a,end,start) for(int (a) = (start);(a) < (end);(a)++) // regular for loop
#define FOR_custom_less_or_equal(a,end,start) for(int (a) = (start);(a) <= (end);(a)++) // regular for loop
void moveZeroestoEnd(int *arr,int n){
    // *T(n) = O(n)
    // *S(n) = O(1)
    // @param arr : pointer to an array 
    // @param n : size of the array 
    int i = 0;
    FOR(j,n){
        if(arr[j]!=0){
            if(i != j)
                swap(arr[i],arr[j]);
            i++;
        }
    }
}

void printArray(int *arr,int n){
    // *T(n) = O(n)
    // *S(n) = O(1)
    // @param arr : pointer to an array 
    // @param n : size of the array 
    cout << "\n";
    FOR(i,n){
        cout <<arr[i]<< " ";
    }
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,n;
    cin >> T;
    while(T){
        cin >> n;
        int arr[n];
        FOR(i,n){
            cin >> arr[i];
        }
        cout << "Before : ";
        printArray(arr,n);
        moveZeroestoEnd(arr,n);
        cout << "After : ";
        printArray(arr,n);
        T--;
    }
    return 0;
}
