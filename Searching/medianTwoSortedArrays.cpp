// find the median of an array that is merged with two sorted array
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

vll merge(vll a1,vll a2);
double median(vll a1,vll a2);
void printVector(vll a){
    cout << "\n";
    FOR(i,a.size()){
        cout << a[i] <<" ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll T,n,m;
    cin >> T;
    while(T){
        cin >> m >> n; // m : size of a1, n: size of a2
        vll a2(n),a1(m); // vector
        FOR(i,m){
            cin >> a1[i];
        }
        FOR(i,n){
            cin >> a2[i];
        }
        cout << median(a1,a2) <<"\n";

        a1.clear();
        a2.clear();
        T--;
    }
    return 0;
}

vll merge(vll a1,vll a2){
    // * T(n) = O(n+m)
    // * S(n) = O(n+m)
    ll n1 = a1.size(),n2 = a2.size(),i = 0,j = 0;// i:a1,j:a2
    vll res;
    while(i < n1 && j < n2){

        if(a1[i] <= a2[j])
            res.PB(a1[i++]);
        else
            res.PB(a2[j++]);

    }
    while(i < n1){
        res.PB(a1[i++]);
    }
    while(j < n2){
        res.PB(a2[j++]);
    }
    return res;
}
double median(vll a1,vll a2){
    // * T(n) = O(n+m)
    // * S(n) = O(n+m)

    vll a = merge(a1,a2);
    double res = 0.0;
    ll n = a.size();
    if((n&1)==1){
        // odd
        res = a[n/2]/1.0;
    }
    else{
        res = (a[n/2] + a[n/2 - 1])/2.0;
    }
    return res;
}