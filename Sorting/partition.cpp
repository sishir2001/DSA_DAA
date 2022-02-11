// when given an index , placing the element of the index in its correct position
#include<bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long l;
typedef unsigned long ul;
typedef long long ll;
typedef unsigned long long ull;

typedef vector<l> v_l;
typedef vector<ul> v_ul;
typedef vector<ll> v_ll;
typedef vector<ull> v_ull;
typedef vector<int> v_int;
typedef vector<uint> v_uint;

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

int partition(ll *a,ll l,ll h,ll p);
int Lpartition(ll *a,ll l,ll r);
void printArray(ll *a,ll n);
void quickSort(ll *a,ll l,ll r);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll T,n,p;
    cin >> T;
    while(T){
        cin >> n >> p;
        ll *a = new ll[n];
        FOR(i,n){
            cin >> a[i];
        }

        quickSort(a,0,n-1);
        printArray(a,n);

        delete []a;
        T--;
    }
    return 0;
}

void quickSort(ll *a,ll l,ll r){
    if(l >= r)
        return;

    ll p = Lpartition(a,l,r);
    quickSort(a,l,p-1);
    quickSort(a,p+1,r);
}
int partition(ll *a,ll l,ll h,ll p){

    // !T(N) = O(N);
    // !S(N) = O(1);

    // @param a : pointer to an array
    // @param n : size of the array
    // @param p : index of the element that needs to be placed at its correct position
    ll r = -1;
    FOR_less_or_equal(i,h,l){
        if(i == p)
            continue;
        if(a[i] <= a[p]){
            if(r != -1){
                swap(a[i],a[r]);
                r = i;
            }
        }
        else{
            if(r == -1){
                r = i;
            }
        }
    }
    if(r != -1){
        swap(a[r],a[p]);
        p = r;
    }
    return p;
}

void printArray(ll *a,ll n){
    FOR(i,n){
        cout << a[i] <<" ";
    }
    cout << "\n";
}

int Lpartition(ll *a,ll l,ll r){
    // ? Lumuto's partition
    // !T(N) = O(N)
    // !S(N) = O(1)

    ll pivot = a[r],i = l-1;
    FOR_less_or_equal(j,r-1,l){
        if(a[j] < pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}