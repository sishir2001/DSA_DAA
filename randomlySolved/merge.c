// merging of two arrays.
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool isSort(int *q,int n){
    for(int i =0;i<n-1;i++)
    {
        if(q[i]>q[i+1])
        return false;
    }
    return true;
}

void merge(int *a,int m,int *b,int n,int *c){
    int i,j,k;
    i = j = k =0;
    while(i<m && j<n){
        if(a[i]<=b[j]){
            if(a[i] == b[j])
                j++;
            c[k++] = a[i++];
        }
        else if(a[i]>b[j])
            c[k++] = b[j++];          
    }
    while(i<m)
        c[k++] = a[i++];
    while(j<n)
        c[k++] = b[j++];
    for(i=0;i<k;i++)
        printf("%d ",c[i]);
}
void main(void){
    int m,n;
    printf("Enter the size of A and B arrays:");
    scanf(" %d %d",&m,&n);
    int *A = (int *)malloc(m*sizeof(int)),*B= (int *)malloc(n*sizeof(int)),*C = (int *)malloc((m+n)*sizeof(int));
    //A
    printf("\nEnter the sorted elements of A:\n");
    for(int i = 0;i<m;i++)
    scanf(" %d",&A[i]);

    //B
    printf("\nEnter the sorted elements of B:\n");
    for(int i = 0;i<n;i++)
    scanf(" %d",&B[i]);

    if(isSort(A,m)&&isSort(B,n))  {
        merge(A,m,B,n,C);// merging the two arrays in C;
        printf("\n");
    }
    else
    {
        printf("Not Sorted Arrays.");
    }
    

    

}
