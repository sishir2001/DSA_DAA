// minimum consecutive flips 

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

void minConsecFlipsNaive(vi nums);
void minConsecFlipsEffi(vi nums);
void printStatement(int l,int h);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,x,n;
    vi nums; // vector
    cin >> T;
    while(T){
        cin >> n;
        FOR(i,n){
            cin >> x;
            nums.PB(x);
        }
        minConsecFlipsNaive(nums);
        cout << "\n";
        minConsecFlipsEffi(nums);
		nums.clear();
        T--;
    }
    return 0;
}


void minConsecFlipsNaive(vi nums){
    // *T(n) = thetha(2n)
    // *S(n) = thetha(1)
    // First counting minimum consecutives of 1 and 0's 
    // Second prinitng the indexes of the minimum
    int c[] = {0,0}; // ? for keeping the count
    int size = nums.size();
    c[nums[0]]++; // ? incrementing the count of first element of nums 
    // * counting the minimum groups of 1 and 0
    FOR_custom_less(i,size,1){
        if(nums[i]!=nums[i-1])
            c[nums[i]]++;
    }

    int flip = (c[0] <= c[1])?0:1;
    int l = -1,h = -1;
    FOR(i,size){
        if(nums[i] == flip){
            if(l == -1)
                l = i;
            h = i;
        }
        else{
            if(l != -1){
                printStatement(l,h);
                l = -1;
                h = -1;
            }
        }
    }
    if(l != -1)
        printStatement(l,h);
}
void printStatement(int l,int h){
    cout << "From " << l <<" to "<< h << "\n";
}

void minConsecFlipsEffi(vi nums){
    // ! only one traversal of the array 
    // at max the difference between is 1 . 0 or 1 
    //* always the second occuring group will have minimum groups to flip
    // *T(n) = O(n)
    // *S(n) = O(1)

    int size = nums.size(),k = 0,l = -1,h = -1,flip = -1;
    FOR_custom_less(i,size,1){
        if(k == 0 && nums[i] != nums[i-1]){
            // this is the first occurence of the second group
            k = 1;
            l = i;
            h = i;
            flip = nums[i];
        }
        else if(k != 0){
            if(nums[i] == flip){
                if(l == -1)
                    l = i;
                h = i;
            }
            else if(nums[i] != flip && l != -1){
                printStatement(l,h);
                l = -1;
                h = -1;
            }
        }
    }
    if(l != -1)
        printStatement(l,h);
}