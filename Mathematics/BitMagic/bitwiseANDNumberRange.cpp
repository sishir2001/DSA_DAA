// link : https://leetcode.com/problems/bitwise-and-of-numbers-range/ 
// #include<bits/stdc++.h>
#include<iostream>
#include<climits>
using namespace std;

    int sumBinaryPos(int n,unsigned int a,unsigned int b){
        // T(N) = O(1)
        // sum of 1's in that particular pos from [0,n]
        int alpha = n/a,count=0;
        count = a*(n/b);
        if((alpha & 1) == 1){
            // alpha is odd
            count = count + (n % a) + 1;
        }
        return count ;
    }
    int rangeBitwiseAnd(int left, int right) {
        // T(n) = O(logn)
        if(left == 0 || (left & right) == 0){
            return 0;
        }
               
        unsigned int a = 1,b = 2,res = 0; // 1<<0,1<<1
        while(a <= right){
            // calculating sum of 1's in the particular position
            int count_left = sumBinaryPos(left-1,a,b);
            int count_right = sumBinaryPos(right,a,b);
            if((count_right - count_left) == (right-left + 1)){
                res += a;
            }
            a = a << 1;
            // if(b < )
            b = b << 1;
        }
        return res;
    }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << rangeBitwiseAnd(5,7);
    return 0;
}

