// finding majority elements if their frequency is > n/3

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v_ll;
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

v_int majorityElement2(v_int nums);

void printVector(v_int nums);
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

        printVector(majorityElement2(nums));

        T--;
    }
    return 0;
}

v_int majorityElement2(v_int nums){
    // @param nums : int vector
    // *T(n) = O(n)
    // *S(n) = O(1)
    v_int res;
    int size = nums.size();
    int threshhold = size/3 + 1; // >= 

    // if(size == 1)
    //     return nums;
    // finding two candidates for majority elements
    int maj1 = 0,maj2 = 0,count1= 0,count2 = 0; // maj1 default 1st element
    FOR(i,size){
        if(count1 == 0 && nums[i] != nums[maj2]){
            maj1=i;
            // count1 = 0;
        }
        if(nums[maj1] == nums[i])
            count1++;
        else{
            // for candidate 2
            if(count2 == 0 && nums[i] != nums[maj1]){ // !imp , not making maj1 and maj2 equal
                // count2 = 0;
                maj2 = i;
            }
            if(nums[maj2] == nums[i])
                count2++;
        }
        if(nums[maj1] != nums[i] && nums[maj2] != nums[i]){// !imp , not making maj1 and maj2 equal
            count1 --;
            count2 --;
        }
        // if(count1 == 0){
        //     maj1 = i;
        //     count1 = 1;
        // }
        // else if(count2 == 0){
        //     maj2 = i;
        //     count2 = 1;
        // }
    }
    // deb2(nums[maj1],nums[maj2]);
    int majC1 = 0,majC2 = 0;
    // looping again to verify the candidates 
    FOR(i,size){
        if(nums[maj1] == nums[i])
            majC1++;
        else if(nums[maj2] == nums[i])
            majC2++;
    }
    if(majC1 >= threshhold)
        res.push_back(nums[maj1]);
    if(majC2 >= threshhold)
        res.push_back(nums[maj2]);
    return res;
}
void printVector(v_int nums){
    int size = nums.size();
    cout << "\n";
    FOR(i,size){
        cout << nums[i] <<" ";
    }
    cout << "\n";
}