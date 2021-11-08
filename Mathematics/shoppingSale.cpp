// Problem from gfg 
#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	//code
	int T;
	cin >> T;
	while(T){
	    int N,K;
	    cin >> N >> K;
	    int arr[N];
	    for(int i = 0;i<N;i++){
	        cin >> arr[i];
	    }
	    // logic 
	    // sort the array and and calculate the cost 
	    sort(arr,arr+N);
	    unsigned long long cost = 0; // calculating the cost of the graphs 
        
        for(int i = 0;i<N;i++){
            if((i+1)%K == 0){
                N-=1;
            }
            cost += arr[i];
        }

	    cout << cost<<endl;
	    T--;
	}
	return 0;
}