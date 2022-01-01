// Rearrange Array Alternatively
// ! link : https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately-1587115620/1/?track=DSASP-Arrays&batchId=154

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

void rearrange(ll *arr,int n);
void rearrange1(ll *arr,int n);
void printArr(ll *arr,int n);
void reverse(ll *arr,int l ,int r);
void rotateLeft(ll *arr,int n ,int d);


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T,n;
    cin >> T;
    while(T){
        cin >> n;
        ll *a = new ll[n];
        FOR(i,n){
            cin >> a[i];
        }
        rearrange1(a,n);
        printArr(a,n);
        delete []a;
        T--;
    }
    return 0;
}

void rearrange(ll *arr,int n){
    // * T(n) = O(n)
    // * S(n) = O(n)
    // int size = n;
    // if((n&1) == 1){
    //     size = n-1;
    //     rotateLeft(arr + n/2,n-n/2,1);
    // }
    // printArr(arr,n);
    // int l = 0,r = size-1; // where max elements should be , r : where max elements are 
    // deb2(l,r);
    // while(l < r){
    //     int temp = arr[l],t_index = (l+l+1)%size;
    //     arr[l] = arr[r];
    //     arr[r] = arr[t_index];
    //     arr[t_index] = temp;
    //     l = l+2;
    //     r--;
    // }
    // swap(arr[l],arr[r]);
    ll *b = new ll[n];
    int l = 0,r = n-1,i = 0;
    while(l < r){
        b[i++] = arr[r--];
        b[i++] = arr[l++];
    }
    if(i == n-1 && l == r)
        b[i] = arr[l];
    FOR(i,n){
        arr[i] = b[i];
    }
    delete []b;
}
void printArr(ll *arr,int n){
    cout << "\n";
    FOR(i,n)
        cout <<arr[i]<< " ";
    cout << "\n";
}
// void reverse(ll *arr,int l ,int r){
//     while(l < r){
//         swap(arr[l],arr[r]);
//         l++;
//         r--;
//     }
// }
// void rotateLeft(ll *arr,int n ,int d){
//     reverse(arr,0,d-1);
//     reverse(arr,d,n-1);
//     reverse(arr,0,n-1);
// }
void rearrange1(ll *arr,int n){
    // * T(n) = O(n)
    // * S(n) = O(1)

    int maxEle = arr[n-1]+1,l = 0,r = n-1;
    // ! Below is the formula for storing two numbers as one number
    FOR(i,n){
        if((i&1) == 1){
            // odd . this should be occupied by minimum
            arr[i] = arr[i] + (arr[l]%maxEle)*maxEle;
            l++;
        }
        else{
            // even . this should be occupied by maximum
            arr[i] = arr[i] + (arr[r]%maxEle)*maxEle;
            r--;
        }
    }
    FOR(i,n){
        // arr[i]/maxEle -> new number
        // arr[i]%maxEle -> original number
        arr[i] = floor(arr[i]/maxEle);
    }
}