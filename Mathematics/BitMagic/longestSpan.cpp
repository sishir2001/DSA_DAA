#include<iostream>
#include<algorithm>

using namespace std;
int resMax = 0;

void longSpan(int* a1,int* a2,int n1,int n2,int c1,int c2,int i = 0,int j = 1,int res = 1){
    // ! Segmentation Fault
    // ! This is the naive solution
    // ! T(n) = more than O(n)
    if(j == min(n1,n2))
        return;

    c1 += a1[j];
    c2 += a2[j];
    if(c1 != c2){
        c1 = c1 - a1[i]-a1[j];
        c2 = c2 - a2[i]-a2[j];
        int k = i++;
        longSpan(a1,a2,n1,n2,c1,c2,k,j,j-i-1);
    }
    else{
        res++;
        resMax = max(resMax,res);
    }
    int k = j++;
    longSpan(a1,a2,n1,n2,c1,c2,i,k,res);
}
int maxSpan(int* a1,int* a2,int n1,int n2){
    // * T(n) = O(n^2)
    int resMax = 0;
    for(int i = 0;i < min(n1,n2);i++){
        int s1 = 0,s2 = 0;
        for(int j = i;j<min(n1,n2);j++){
            s1 += a1[i];
            s2 += a2[i];
            if(s1 == s2){
                int length = j-i+1;
                resMax = max(resMax,length);
            }
        }
    }
    return resMax;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr1[] = {0,1,0,1,1,1},arr2[] = {1,0,1,1,0},n1 = sizeof(arr1)/sizeof(arr1[0]),n2 = sizeof(arr2)/sizeof(arr2[0]);
    // longSpan(arr1,arr2,n1,n2,arr1[0],arr2[0]);
    cout << "Result : " << resMax;
    return 0;
}