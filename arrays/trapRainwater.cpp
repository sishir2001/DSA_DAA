// Find the amount of trapped rain water 
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
// typedef vector<ll> v_ll;

#define mod 1000000007 // 1e9+7
#define deb(x) cout << #x << " = "<<x<<"\n" // for debugging
#define deb2(x,y) cout << #x << " = "<<x << " , " << #y << " = " << y <<"\n" // for debugging 
#define FOR(a,end) for(int (a) = 0;(a) < (end);(a)++) // regular for loop
#define FOR_desc(a,end) for(int (a) = (end)-1;(a) >= 0;(a)--) // regular for loop decreasing
#define FOR_custom_more_desc(a,start) for(int (a) = (start);(a) > 0;(a)--) 
#define FOR_custom_more_or_equal_desc(a,start) for(int (a) = (start);(a) >= 0;(a)--) 
#define FOR_custom_less(a,end,start) for(int (a) = (start);(a) < (end);(a)++) // regular for loop
#define FOR_custom_less_or_equal(a,end,start) for(int (a) = (start);(a) <= (end);(a)++) // regular for loop

int *getLeftMax(int *a,int n);
ll trapRainWater(int *a,int n);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,n;
    cin >> T;
    while(T){
        cin >> n;
        int *a = new int[n];
        FOR(i,n){
            cin >> a[i];
        }
        cout << trapRainWater(a,n) << "\n";
        delete[] a;
        T--;
    }
    return 0;
}

int *getLeftMax(int *a,int n){

    // getting lmax for each element
    int *l_max = new int[n];
    int lMax = a[0];
    FOR_custom_less(i,n,1){
        lMax = max(lMax,a[i]);
        l_max[i] = lMax;
    }
    return l_max;

}

ll trapRainWater(int *a,int n){
    // *T(n) = O(n) 
    // *S(n) = O(n) : auxiliary space 
    // @param a: pointer to an array 
    // @param a: size of the array 

    ll tp_water = 0;
    int r_max = a[n-1],min_lr = a[n-1]; 
    int *l_max = getLeftMax(a,n);

    FOR_custom_more_desc(i,n-2){
        r_max = max(a[i],r_max);
        min_lr = min(l_max[i],r_max);
        tp_water += min_lr - a[i];
    }
    delete[] l_max;

    return tp_water;
}
