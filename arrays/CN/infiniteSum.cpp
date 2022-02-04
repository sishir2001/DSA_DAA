#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v_ll;
typedef vector<int> v_int;

#define PB push_back // for vector
#define PPB pop_back // for vector
#define mod 1000000007 // 1e9+7
#define deb(x) cout << #x << " = "<<x<<"\n" // for debugging
#define deb2(x,y) cout << #x << " = "<<x << " , " << #y << " = " << y <<"\n" // for debugging 
#define FOR(a,end) for(int (a) = 0;(a) < (end);(a)++) // regular for loop
#define FOR_REV(a,start) for(int (a) = (start)-1;(a) >= 0;(a)--) // regular for loop decreasing
#define FOR_less(a,end,start) for(int (a) = (start);(a) < (end);(a)++) // regular for loop
#define FOR_REV_great(a,end,start) for(int (a) = (start);(a) > (end);(a)--) // regular for loop
#define FOR_less_or_equal(a,end,start) for(int (a) = (start);(a) <= (end);(a)++) // regular for loop
#define FOR_REV_great_or_equal(a,end,start) for(int (a) = (start);(a) >= (end);(a)--) // regular for loop

v_int sumInRanges(v_int arr,int n,vector<v_ll> queries,int q);
v_int bfSumInRanges(v_int arr,int n,vector<v_ll> queries,int q);
int sumRange(v_ll prefixSum,int n,ll limit,ll sumArr);
void printVector(v_int arr);


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input3.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int T,n,q;
    cin >> T;

    while(T){
        cin >> n;
        v_int nums(n); // vector
        FOR(i,n){
            cin >> nums[i];
        }
        cin >> q;
        vector<v_ll> queries(q,v_ll(2)); // vector

        FOR(i,q){
            cin >> queries[i][0] >> queries[i][1];
        }

        printVector(sumInRanges(nums,n,queries,q));
        printVector(bfSumInRanges(nums,n,queries,q));

        nums.clear();
        queries.clear();
        T--;
    }
    return 0;
}

void printVector(v_int arr){
    int n = arr.size();
    FOR(i,n){
        cout << arr[i] <<" ";
    }
    cout << "\n";
}
int sumRange(v_ll prefixSum,int n,ll limit,ll sumArr){
    ll k = limit%n,m = limit/n;
    int res = ((m*sumArr)%mod + prefixSum[k])%mod;
    return res;
}

v_int sumInRanges(v_int arr,int n,vector<v_ll> queries,int q){
    // calculate prefixSum
    v_ll prefixSum(n,0);
    v_int res(q,0);
    ll sumArr = 0;
    FOR(i,n){
        sumArr = sumArr + arr[i];
        prefixSum[i] = sumArr;
    }

    // traversing the queries 
    FOR(i,q){
        ll l = queries[i][0],r = queries[i][1];
        int resR = sumRange(prefixSum,n,r,sumArr);
        int resL = sumRange(prefixSum,n,l-1,sumArr);
        int resSum = resR - resL;
        res[i] = resSum;
    }
    return res;
}
v_int bfSumInRanges(v_int arr,int n,vector<v_ll> queries,int q){
    v_int res(q,0);
    // traversing the queries 
    FOR(i,q){
        ll l = queries[i][0],r = queries[i][1],sumArr = 0;
        FOR_less_or_equal(j,r,l){
            sumArr = (sumArr + arr[j%n])%mod;
        }
        res[i] = sumArr;
    }
    return res;
}