 // ! https://www.geeksforgeeks.org/find-the-two-repeating-elements-in-a-given-array/
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


 void findDuplicates(int *arr,int size){
     // find the duplicates that only occur twice
     // n+2 will be the size of the array, the elemnents will be in the range 1-n
     // using Bitwise XOR 
     int XOR = 0,xArrayXOR= 0,yArrayXOR = 0,rangeXOR = 0,arrayXOR=0,xRangeXOR= 0,yRangeXOR = 0; // x and y are the two repeating twice elements , XOR = x^y
     // x^y = arrayXOR ^ rangeXOR (1-n)  

     //? traversing the array 
     FOR(i,size){
         arrayXOR ^= arr[i];
     } 
     // rangeXOR
     FOR_custom_less(i,size-1,1){
         rangeXOR ^= i;
     }
     XOR = arrayXOR^rangeXOR;

     // now we need to divide the array into two according to the right most set bit of XOR
     int setBit = XOR & ~(XOR-1);

     // ? traversing the array
     FOR(i,size){
        // dividing the array into two
        if((arr[i] & setBit)){
            xArrayXOR ^= arr[i];
        }
        else
            yArrayXOR ^= arr[i];
     }

     FOR_custom_less(i,size-1,1){
        if((i & setBit)){
            xRangeXOR ^= i;
        }
        else
            yRangeXOR ^= i;
     }
     cout << "x : "<<(xArrayXOR^xRangeXOR)<<"\n"; 
     cout << "y : "<<(yArrayXOR^yRangeXOR) << "\n"; 
 }
 
void findDuplicates1(int *arr,int n);
void findDuplicates2(int *arr,int n);

 int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     int T,n;
     cin >> T;
     while(T){
         cin >> n;
         int *a = new int[n];
         FOR(i,n){
             cin >> a[i];
         }
        //  findDuplicates(a,n);
        //  findDuplicates1(a,n);
         findDuplicates2(a,n);
         T--;
     }
     return 0;
 }
 
void findDuplicates1(int *arr,int n){
    // this will modify the array 
    // !T(N) = O(n)
    // !S(n) = O(1)
    FOR(i,n){
        if(arr[abs(arr[i])] > 0){
            // make it negative
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        }
        else{
            // we have found the repeating element 
            cout << abs(arr[i])<<" ";
        }
    }
    cout << "\n";
}
void findDuplicates2(int *arr,int n){
    // ? T(n) = theta(n)
    // ? S(n) = theta(1)
    // ! useful technique when we want to calculate frequencies of an array which has limited range elements
    
    // * increase every arr[i]-1 th index by n-1 , as the range of elements is 1 to n-2 .
    // * when traversed again,divided with n-1 , if it is >= 2 , then it has occurred more than one time
    int m = n-1;
    // adding the array
    // cout << "Before adding : "<<"\n";
    // FOR(i,n)
    //     cout << arr[i] << " ";
    FOR(i,n){
        int index = (arr[i]%m)-1;
        arr[index] += m;
        if(arr[index]/m >= 2)
            cout << index+1 <<" ";
    }
    cout << "\n";
    // FOR(i,n) cout << arr[i] << " ";
    // cout << "\n";
    // // checking for duplicates 
    // FOR(i,n){
    //     int check = arr[i]/m;
    //     if(check >= 2){
    //         cout << i+1 << " ";
    //     }
    // }
    // cout << "\n";
}