//! link : https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/maximize-sum-0423b95e/

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

void maxSum(ll *a,ll n,ll k);
// void printArr(ll *a , ll n){
//     cout << "\n";
//     FOR(i,n){
//         cout << a[i] << " ";
//     }
//     cout << "\n";
// }
// void printVec(vll a){
//     cout << "\n";
//     int n = a.size();
//     FOR(i,n){
//         cout << a[i] << " ";
//     }
//     cout << "\n";
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll T,n,k;
    cin >> T;
    while(T){
        cin >> n >> k;
        ll *a = new ll[n];
        FOR(i,n){
            cin >> a[i];
        }
        maxSum(a,n,k);
        delete []a;
        T--;
    }
    return 0;
}


void maxSum(ll *a,ll n,ll k){
    // !T(n) = O(nlogn)
    // !S(n) = O(n)
    // sorting the array 
    if(k == 0){
        cout << 0 <<"\n";
        return;
    }
    vll res;
    // * sorting an array
    sort(a,a+n);
    // printArr(a,n);// ! remove
    // adding the duplicate elements
    ll vSum = a[0];
    FOR_custom_less(i,n,1){
        if(a[i] == a[i-1]){
            vSum += a[i];
        }
        else{
            res.PB(vSum);
            vSum = a[i];
        }
        if(i == n-1){
            res.PB(vSum);
        }
    }
    // * sorting a vector
    sort(res.begin(),res.end());
    // printVec(res); // ! remove

    ll size = res.size();
    ll sum = res[size-1],count = 1,i = size-2,mx = res[size-1];
    while(i >= 0 && count < k){
        count++;
        sum+=res[i];
        mx = max(mx,sum);
        // deb2(i,mx);
        i--;
    }
    // while(i >= 0){
    //     if(res[i] == res[i+1]){
    //         sum += res[i];
    //         mx = max(mx,sum);
    //     }
    //     else  break;
    //     i--;
    // }
    // deb2(sum,mx);
    cout <<mx<<"\n";
}