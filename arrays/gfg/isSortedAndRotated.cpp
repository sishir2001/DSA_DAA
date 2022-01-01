// check if array is sorted and rotated 
// ! link : https://practice.geeksforgeeks.org/problems/check-if-array-is-sorted-and-rotated-clockwise-1587115620/1/?track=DSASP-Arrays&batchId=154

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

#define PB push_back // for vector
#define PPB pop_back // for vector
#define mod 1000000007 // 1e9+7
#define deb(x) cout << #x << " = "<<x<<"\n" // for debugging
#define deb2(x,y) cout << #x << " = "<<x << " , " << #y << " = " << y <<"\n" // for debugging 
#define FOR(a,end) for(int (a) = 0;(a) < (end);(a)++) // regular for loop
#define FOR_desc(a,end) for(int (a) = (end)-1;(a) >= 0;(a)--) // regular for loop decreasing
#define FOR_custom_more_desc(a,start) for(int (a) = (start);(a) > 0;(a)--) 
#define FOR_custom_more_or_equal_desc(a,start) for(int (a) = (start);(a) >= 0;(a)--) 
#define FOR_custom_less(a,end,start) for(int (a) = (start);(a) < (end);(a)++) // regular for loop
#define FOR_custom_less_or_equal(a,end,start) for(int (a) = (start);(a) <= (end);(a)++) // regular for loop

void reverse(int *arr,int l,int r);
void rotateLeft(int *arr,int n,int d);
bool isSortedAndRotated(int *arr,int n);
bool isSortedAndRotated1(int *arr,int n);


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    bool t = true,f = false;
    deb2(t,f);
    int T,n;
    cin >> T;
    while(T){
        cin >> n;
        int *a = new int[n];
        FOR(i,n){
            cin >> a[i];
        }
        deb2(isSortedAndRotated,isSortedAndRotated1);
        delete []a;
        T--;
    }
    return 0;
}

void reverse(int *arr,int l,int r){
    while(l < r){
        swap(arr[l],arr[r]);
        l++;r--;
    }
}
void rotateLeft(int *arr,int n,int d){
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}
bool isSortedAndRotated(int *a,int n){
    // * T(n) = thetha(2*n);
    // * S(n) = O(1);

    if(n == 1)
        return false;
    if( n == 2)
        return true;

    bool isRotated = false,isSorted = true;
    ll prevDiff = a[1]-a[0],currDiff = 0;
    FOR_custom_less(i,n,2){
        currDiff = a[i] - a[i-1];
        if(currDiff*prevDiff < 0){
            if(abs(prevDiff) > abs(currDiff)){
                rotateLeft(a,n,i-1);
            }
            else{
                rotateLeft(a,n,i);
            }
            isRotated = true;
            break;
        }
        else{
            prevDiff = currDiff;
        }
    }
    if(!isRotated)
        return false; // the array is not rotated
    // check if the array is sorted 
    int diff = a[n-1] - a[0];
    if(diff == 0){
        // * array should be same -> arr[i] == arr[i-1]
        FOR_custom_less(i,n,1){
            if(a[i] != a[i-1]){
                isSorted = false;
                break;
            }
        }
    }
    else if(diff < 0){
        // * array should be non-increasing -> arr[i] <= arr[i-1]
        FOR_custom_less(i,n,1){
            if(a[i] > a[i-1]){
                isSorted = false;
                break;
            }
        }
    }
    else{
        // * array should be non-decreasing -> arr[i] >= arr[i-1]
        FOR_custom_less(i,n,1){
            if(a[i] < a[i-1]){
                isSorted = false;
                break;
            }
        }
    }
    return isSorted;
}
bool isSortedAndRotated1(int *arr,int n){
    // ! simpler solution 
    // ? Observation : If array is sorted and rotated , minEle and maxEle will be adjacent to each other 

    // *T(n) = thehta(n)
    // *S(n) = O(1)
    // mx: max element , mxi = max element index
    // mn: min element , mni = min element index
    int mx = INT_MIN,mn = INT_MAX,mxi = 0,mni = 0;
    FOR(i,n){
        if(arr[i] > mx){
            mx = arr[i];
            mxi = i;
        }
        else if(arr[i] < mn){
            mn = arr[i];
            mni= i;
        }
    }

    // checking whether min and max are adjacent 
    if((mni - mxi == 1 && arr[0] > arr[n-1]) || (mxi - mni == 1 && arr[0] < arr[n-1]))
        return true;
    return false;
}