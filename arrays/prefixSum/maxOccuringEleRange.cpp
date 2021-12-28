// find the maximum occuring element in the given ranges
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

int maxOccuringEle(vi l,vi r);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,x,n;
    vi l,r; // vector
    cin >> T;
    while(T){
        cin >> n;

        cout << "L[] = ";

        FOR(i,n){
            cin >> x;
            l.PB(x);
        }
        cout << "R[] = ";

        FOR(i,n){
            cin >> x;
            r.PB(x);
        }

        cout << maxOccuringEle(l,r)<<"\n";

        l.clear();
        r.clear();

        T--;
    }
    return 0;
}


int maxOccuringEle(vi l,vi r){
    // !T(n) = O(n)
    // !S(n) = O(1000)

    int n = l.size();
    // * We using a technique of prefix sum 
    // * We do not traverse the whole range , instead just the lower bounds and upperbounds
    // ? assumming the max value of the range is below 1000
    vi arr(1000);//a vector with size 1000

    // going through l and r
    FOR(i,n){
        arr[l[i]]++;// incrementing the lowerbound index
        arr[r[i] + 1]--;// decrementing  the upperbound + 1 index
    }

    // performing prefix sum on the arr 
    int maxm = arr[0],res = 0;// res will store the index of maximum value in the arr
    // traversing arr
    FOR_custom_less(i,1000,1){
        arr[i]+=arr[i-1];
        if(maxm < arr[i]){
            maxm = arr[i];
            res = i;
        }
    }
    // end decision factor
    if(maxm == 1)
        res = -1; // occurence of all elements is same 
    return res;

}
