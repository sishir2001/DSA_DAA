// rotate the array by d places
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

// * using reversal algorithm to rotate the array 
void reverse(int *a,int l,int h){
    // !T(n) = O(n)
    // !S(n) = O(1)
    // @param a : head allocated array 
    // @param l : lower index 
    // @param h : higher index 
    while(l < h){
        swap(a[l],a[h]);
        l++;
        h--;
    }
}
void reverseRightRotate(int *a,int n,int d){
    // !T(n) = O(n)
    // !S(n) = O(1)
    // @param a : head allocated array 
    // @param n : size of the array
    // @param d : shift by d places 
    int x = n - (d%n);
    reverse(a,0,x-1);
    reverse(a,x,n-1);
    reverse(a,0,n-1);
}
void reversalLeftRotate(int *a,int n,int d){
    // @param a : head allocated array 
    // @param n : size of the array
    // @param d : shift by d places 
    reverse(a,0,d-1);
    reverse(a,d,n-1);
    reverse(a,0,n-1);
}

int *rightRotateArrayD(int *a,int n,int d){
    // @param a : head allocated array 
    // @param n : size of the array
    // @param d : shift by d places 
    // !T(n) = O(n);
    // !S(n) = O(n);

    int *b = new int[n];
    int j = 0,x = n - (d%n);
    if(x == 0 || x == n)
        return a;
    // second part shifting
    FOR_custom_less(i,n,x){
        b[j++] = a[i];
    }
    int i = 0; // first part shifting 
    for(;j<n;j++){
        b[j] = a[i++];
    }
    delete[] a;// deallocating the heap memory 
    return b;
}
int *leftRotateArrayD(int *a,int n,int d){
    // @param a : head allocated array 
    // @param n : size of the array
    // @param d : shift by d places 
    // !T(n) = O(n);
    // !S(n) = O(n);

    int *b = new int[n];
    int j = 0,x = d%n;
    if(x == 0 || x == n)
        return a;
    // second part shifting
    FOR_custom_less(i,n,x){
        b[j++] = a[i];
    }
    int i = 0; // first part shifting 
    for(;j<n;j++){
        b[j] = a[i++];
    }
    delete[] a;// deallocating the heap memory 
    return b;
}
void printArray(int *a,int n){
    cout << "\n";
    FOR(i,n){
        cout <<a[i]<< " ";
    }
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,n,d,decision;
    cin >> T;
    while(T){
        cout << "n : ";
        cin >> n;
        cout << "d : ";
        cin >> d;
        cout << "decision(0:left,1:right) : ";
        cin >> decision;
        int *a = new int[n];// heap allocated array
        FOR(i,n){
            cin >> a[i];
        }
        cout << "Before : ";
        printArray(a,n);
        if(decision == 0){
            reversalLeftRotate(a,n,d);
            cout << "After : ";
            printArray(a,n);
        }
        else if(decision == 1){
            reverseRightRotate(a,n,d);
            cout << "After : ";
            printArray(a,n);
        }
        else{
            cout << "decision should be 0 or 1";
        }
        delete[] a;
        T--;
    }
    return 0;
}
