// find the only two odd occuring numbers in a given array 
// Geeksforgeeks problem 

// Hint : XOR sum all the elements in an array and segregate the array according to left most set bit of XORSUM

#include<iostream>
using namespace std;


void twoOddOccuring(int *arr,int n){
    // @param arr : array of integers . Calculate XOR sum on this 
    // @param n : size of the array 
    int XorSum = 0;
    for(int i = 0;i<n;i++){
        XorSum ^= arr[i]; // only two odd occuring , x^y
    }

    // cout << "XorSum : "<<XorSum <<"\n";

    // finding the right most set bit 
    int a = XorSum & (~(XorSum-1));
    // cout << "a : "<<a<<"\n";
    // segregating the array according to the set bit and finding XOR sum 
    int XorSum0 = 0,XorSum1 = 0; // @param XorSum0 for the set bit 0 and XorSum1 for 1
    for(int i = 0;i<n;i++){
        if((arr[i]&a) == 0){
            XorSum0 ^=arr[i];
        }
        else{
            XorSum1 ^=arr[i];
        }
    }
    cout << XorSum0 <<" "<<XorSum1<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; // size of the array 
    cin >> n;

    int arr[n];
    for(int i = 0;i<n;i++)
        cin >> arr[i];
    
    twoOddOccuring(arr,n);
    
    return 0;
}