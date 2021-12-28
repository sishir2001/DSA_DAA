// ? https://www.geeksforgeeks.org/find-minimum-subarray-sum-for-each-index-i-in-subarray-i-n-1/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
// typedef vector<ll> v_ll;
typedef vector<int> v_int;

#define mod 1000000007 // 1e9+7
#define deb(x) cout << #x << " = "<<x<<"\n" // for debugging
#define deb2(x,y) cout << #x << " = "<<x << " , " << #y << " = " << y <<"\n" // for debugging 
#define FOR(a,end) for(int (a) = 0;(a) < (end);(a)++) // regular for loop
#define FOR_desc(a,end) for(int (a) = (end)-1;(a) >= 0;(a)--) // regular for loop decreasing
#define FOR_custom_more_desc(a,start) for(int (a) = (start);(a) > 0;(a)--) 
#define FOR_custom_more_or_equal_desc(a,start) for(int (a) = (start);(a) >= 0;(a)--) 
#define FOR_custom_less(a,end,start) for(int (a) = (start);(a) < (end);(a)++) // regular for loop
#define FOR_custom_less_or_equal(a,end,start) for(int (a) = (start);(a) <= (end);(a)++) // regular for loop

int kadane(v_int nums,int l,int h);
void printVector(v_int nums);
v_int minSubArrSumEachIndex(v_int nums);
v_int minSubArrSumEachIndexImproved(v_int nums);
v_int kadaneImproved(v_int nums,int l,int h);


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,n;
    v_int nums;
    cin >> T;
    while(T){
        cin >> n;
        FOR(i,n){
            int x;
            cin >> x;
            nums.push_back(x);
        }
        printVector(minSubArrSumEachIndex(nums));
        printVector(minSubArrSumEachIndexImproved(nums));
        nums.clear();
        T--;
    }
    return 0;
}


int kadane(v_int nums,int l,int h){
    // * standard
    // *T(n) = O(n)
    // *S(n) = O(1)
    // find the min subarray sum 
    int sum = nums[l],min_sum = nums[l]; 
    FOR_custom_less(i,h,l+1){
        sum = min(sum+nums[i],nums[i]);
        min_sum = min(sum,min_sum);
    }
    return min_sum;
}
v_int minSubArrSumEachIndex(v_int nums){
    // * standard
    // *T(n) = O(n^2)
    // *S(n) = O(1)
    v_int res;
    int h = nums.size();
    FOR(l,h){
        res.push_back(kadane(nums,l,h));
    }
    return res;
}
void printVector(v_int nums){
    // *T(n) = O(n)
    // *S(n) = O(1)
    int size = nums.size();
    cout << "\n";
    FOR(i,size){
        cout << nums[i] <<" ";
    }
    cout << "\n";
}
v_int kadaneImproved(v_int nums,int l,int h){
    v_int res ; // size = 2, res[0] = result,res[1] = value of k;
    int k = l,sum = nums[l],min_sum = nums[l];
    FOR_custom_less(j,h,l+1){
        sum = min(sum+nums[j],nums[j]);
        if(min_sum > sum){
            min_sum = sum;
            k = j;
        }
    }
    res.push_back(min_sum);
    res.push_back(k);
    return res;

}
v_int minSubArrSumEachIndexImproved(v_int nums){
    // Time complexity :
    // * Descending order : O(n)
    // * Ascending order : O(n^2)
    // *S(n) = O(1)

    v_int res;
    int h = nums.size(),l = 0;
    while(l < h){
        v_int kadane_res = kadaneImproved(nums,l,h);
        int min_sum = kadane_res[0],k = kadane_res[1];
        if(k != l){
            FOR_custom_less(i,k,l){
                res.push_back(min_sum);
            }
            l = k;
        }
        else{
            res.push_back(min_sum);
            l++;
        }
    }
    return res;
}