// find the median of two sorted arrays if they are combined 
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

double median(ll *a1,ll *a2,ll n1,ll n2);
void printArray(ll *a1,ll *a2,ll n1,ll n2);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll T,n1,n2;
    cin >> T;
    while(T){
        cin >> n1 >> n2;
        ll *a1 = new ll[n1];
        ll *a2 = new ll[n2];
        FOR(i,n1){
            cin >> a1[i];
        }

        FOR(i,n2){
            cin >> a2[i];
        }
        cout <<median(a1,a2,n1,n2)<<"\n"; 
        
        delete []a1;
        delete []a2;

        T--;
    }
    return 0;
}


double median(ll *a1,ll *a2,ll n1,ll n2){

    // * T(N) = O(logn1)
    // * S(N) = O(1)
    
    if(n1 > n2){
        swap(a1,a2);
        swap(n1,n2);
    }
    
    ll l = 0,r = n1-1,thresh = (n1+n2+1)/2;
    while(l <= r){
        ll i1 = (l+r)/2;
        ll i2 = thresh - i1;
        
        ll mx1 = (i1 == 0)?INT_MIN:a1[i1-1];
        ll mn1 = (i1 == n1)?INT_MAX:a1[i1];

        ll mx2 = (i2 == 0)?INT_MIN:a2[i2-1];
        ll mn2 = (i2 == n2)?INT_MAX:a2[i2];

        if(mx1 <= mn2 && mx2 <= mn1){
            if((n1+n2)%2 == 0){
                //even 
                return (double)(max(mx1,mx2)+min(mn1,mn2))/2;
            }
            else
                return (double)max(mx1,mx2);
        }
        else if(mx1 > mn2)
            r = i1-1;
        else
            l = i1+1;
    }
    return -1.9; // ! will never execute this
}
void printArray(ll *a1,ll *a2,ll n1,ll n2){
    cout << "a1 : ";
    FOR(i,n1)
        cout << a1[i] <<" ";
    cout << "\n";
    cout << "a2 : ";
    FOR(i,n2)
        cout << a2[i] <<" ";
    cout << "\n";
}