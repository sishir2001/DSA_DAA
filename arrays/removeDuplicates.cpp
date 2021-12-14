// remove duplicated from a sorted array
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

int putINFduplicates(int *arr,int n){
    // put INT_MIN in place of duplicates 
    // !T(n) = O(n)
    int i = 1,size = n;
    while(i < n){
        if(arr[i-1] == arr[i]){
            int k = arr[i],j = i+1;
            arr[i] = INT_MIN;
            size = size-1;
            while(j < n){
                if(arr[j] == k){
                    arr[j] = INT_MIN;
                    size = size -1 ;
                }
                else{
                    break;
                }
                j++;
            }
            i = j;
        }
        i++;
    }
    
    return size;
}
void orderTheArray(int *arr,int n){
    // !T(n) = O(n)
    int i = 0;
    FOR(j,n){
        if(arr[j] != INT_MIN){
            if(i != j){
                swap(arr[i],arr[j]);
                i = j;
            }
            else{
                i++;
            }
        }
    }
}
int removeDuplicates(int *arr,int n){
    // !T(N) = O(N) but two iterations of the array
    int size = putINFduplicates(arr,n);
    orderTheArray(arr,n);
    // deb(size);
    return size;
}
void printArray(int *arr,int n){
    cout << "\n";
    FOR(i,n){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int removeDuplicates1(int *arr,int n){
    // * more efficient 
    // !T(n) = O(n) -> only one iteration of the array 
    // !S(n) = O(1)
    // ? similar alogo to orderTheArray() function
    int i = 1;
    FOR_custom_less(j,n,1){

        if(arr[j] != arr[i]){
            // swap the elements in index i and j
            if(i != j){
                arr[i] = arr[j];
            }
            i++;
        }
    }
    return i;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,n;
    cin >> T;
    while(T){
        cout << "n : ";
        cin >> n;
        int arr[n];
        cout << "arr : ";
        FOR(i,n){
            cin >> arr[i];
        }
        cout << "Before : ";
        printArray(arr,n);
        int size = removeDuplicates1(arr,n);
        cout << "After : ";
        printArray(arr,size);
        T--;
    }
    return 0;
}
