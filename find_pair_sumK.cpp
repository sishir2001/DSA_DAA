// for unsorted array.by hashing.time complexity O(n)
#include<iostream>
void find_pair(int *q,int n,int sum,int sizeofhash){
    int *h = new int[sizeofhash];//bitset
    
    //initializing the elements of h to 0
    for(int i = 0;i<=sizeofhash;i++)
    h[i] = 0;

    // finding the pairs.
    for(int i=0;i<n;i++){
        ++h[q[i]];
        int key = sum - q[i];
        if(h[key] !=0 && key!=q[i])
        std::cout<<"("<<q[i]<<","<<key<<") ";
    }
}
int main(){
    int n,sum;
    
    std::cout<<"Enter the size of the array:";
    std::cin>>n;

    int *p = new int[n],max = 0;// heap allocation.
    std::cout<<"Enter the elements of the array:";
    for(int i=0;i<n;i++){
    std::cin>>p[i];
    if(max < p[i])
    max = p[i];
    }

    std::cout<<"Enter the sum:";
    std::cin>>sum;

    // finding the pair
    find_pair(p,n,sum,max+1);

}