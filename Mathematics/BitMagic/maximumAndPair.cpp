// Find the maximum value of AND pair in the given array 
// * Hint : See the binary representation of the numebers in the array 
// Assume : array of integers and 32 bits 

#include<iostream>
using namespace std;
int getCountSetBits(int pattern,int *arr,int n){
    // @param arr : pointer to an array 
    // @param n: size of the array 
    // @param pattern: the number that needs to AND ed with every number in the array 
    int count = 0;
    for(int i = 0;i<n;i++){
        if((pattern & arr[i]) == pattern){
            count ++;
        }
    }
    return count;
}

int maxAndPair(int *arr,int N){
    // @param arr : pointer to an array 
    // @param n: size of the array 
    int res = 0,count = 0;
    // ? Assuming int to be 32 bits 
    for(int bit = 31;bit >=0;bit--){
        count = getCountSetBits((res | (1 << bit)),arr,N);
        if(count >= 2){
            res = (res | (1 << bit));
        }
    }
    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxAndPair(arr,n);
    return 0;
}