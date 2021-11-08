// for sorted array.
#include<iostream>
void find_pair(int *q,int sum,int i,int j){
    int count = 0;// taking two counters i and j , i = lower bound and j = upperbound.time complexty = O(n);
    while(i<j){
        if(q[i] + q[j] == sum){
            std::cout<<"("<<q[i]<<","<<q[j]<<") ";
            i++;j--;count++;
        }
        else if(q[i] + q[j] > sum)
        --j;
        else 
        i++;
    }
    if(count == 0)
    std::cout<<"No pair found!";
}
int main(){
    int n,sum;
    std::cout<<"Enter the size of the sorted array:";
    std::cin>>n;

    int *p = new int[n];// heap allocation.
    std::cout<<"Enter the elements of the array(sorted):";
    for(int i = 0;i<n;i++){
        std::cin>>p[i];
    }
    std::cout<<"Enter the sum:";
    std::cin>>sum;

    // finding the pair.
    find_pair(p,sum,0,n-1);
    
}