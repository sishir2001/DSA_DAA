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

ll sumRange(v_ll prefixSum,ll n,ll sum,ll limit);
v_ll sumInRange(v_ll nums,v_ll l,v_ll r);
void printVector(v_ll res);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("winput.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll T,n,q;
    cin >> T;
    while(T){
        cin >> n;
        v_ll nums(n); // vector
        FOR(i,n){
            cin >> nums[i];
        }

        cin >> q;
        v_ll l(q),r(q);

        FOR(i,q)
            cin >> l[i];
        FOR(i,q)
            cin >> r[i];
        
        // // traversing l and r
        // FOR(i,q)
        //     cout << l[i] <<" ";
        // cout << "\n";

        // FOR(i,q)
        //     cout << r[i] <<" ";
        // cout << "\n";
        printVector(sumInRange(nums,l,r));
        T--;
    }
    return 0;
}

ll sumRange(v_ll prefixSum,ll n,ll sum,ll limit){
    if(limit == -1)
        return 0;
    ll k = limit%n,m = limit/n;
    return (m*sum + prefixSum[k])%mod;
}

v_ll sumInRange(v_ll nums,v_ll l,v_ll r){
    ll n = nums.size(),sumNums= 0,q = l.size();
    v_ll prefixSum(n,0),res(q,0);
    
    // calculating prefixSum
    FOR(i,n){
        sumNums = sumNums+nums[i];
        prefixSum[i] = sumNums;
    }

    // traversing the queries 
    FOR(i,q){
        ll resL = sumRange(prefixSum,n,sumNums,l[i]-2);
        ll resR = sumRange(prefixSum,n,sumNums,r[i]-1);
        ll resSum =resR-resL;
        res[i] = resSum;
    }
    return res;
}

void printVector(v_ll res){
    ll n = res.size();
    FOR(i,n){
        cout << res[i] << " ";
    }
    cout << "\n";
}