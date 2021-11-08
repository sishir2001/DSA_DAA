#include<stdio.h>
#include<stdlib.h>
// recursion is used for backtracking and backtracking is used for bruteforcing.
// time complexity = O(n^2)

void permu(char S[],int k){
    
    static int A[] ={0,0,0,0,0,0,0,0,0,0};
    static char res[10];
    int i =0;
    if(S[k]=='\0'){
        res[k] ='\0';
        printf("%s\n",res);
    }
    else{
        for(i=0;S[i]!='\0';i++){
            if(A[i] == 0){
                A[i] =1;
                res[k] = S[i];
                permu(S,k+1);
                A[i] = 0;
            }
        }
    }
}
void main(){
    char S[] ="ABCD";
    permu(S,0);
}
