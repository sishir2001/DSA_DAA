// calculate no of subsets is equal to given sum

#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef vector<ll> v_ll;
typedef vector<int> v_int;

#define PB push_back
#define mod 1000000007 // 1e9+7
#define deb(x) cout << #x << " = "<<x<<"\n" // for debugging
#define deb2(x,y) cout << #x << " = "<<x << " , " << #y << " = " << y <<"\n" // for debugging 
#define FOR(a,n) for(int (a) = 0;(a) < (n);(a)++) // regular for loop

int subset_sum(v_int &a,int sum,int i=0,int res =0,int count = 0){
    //*T(N) = O(2^n)
    //*S(N) = O(n)
    // ! can be optimized by dynamic programming
    /*
        @param a : array of integers, reference for space utilization
        @param sum : given sum
        @param i : recursion variable
        @param res : calculating the sum of subsets
        @param count : keeping track of subsets whose sum == given sum
    */

    int n = a.size();// size of the vector

    if(i == n){

        if(res == sum)
            count = count +1;

        return count;
    }
    // optimization : calculating only those subsets whose res <= sum
    if(res > sum)
        return count;

    int left_count = subset_sum(a,sum,i+1,res,count);// left branch of tree
    int right_count = subset_sum(a,sum,i+1,res+a[i],count);// right branch of tree
    return left_count + right_count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,n,x,sum;
    cin >> T;
    v_int a;
    while(T){
        cin >> n;
        while(n--){
            cin >> x;
            a.PB(x);
        }
        cout << "sum : ";
        cin >> sum;
        cout << subset_sum(a,sum);
        T--;
    }
    return 0;
}
