// In this method we will use swapping and there will be no need of extra array!

#include<stdio.h>
void swap(char *a,char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}
void permutation(char S[],int l,int h){
    if(l == h){
        printf("%s\n",S);
    }
    else
    {
        for(int i =l;i<=h;i++){
            swap(&S[i],&S[l]);
            permutation(S,l+1,h);
            swap(&S[i],&S[l]);
        }
    }
    
}
void main(){
    char S[] = "ABC";
    // for length of the string.
    int i =0;
    for(;S[i]!='\0';i++){

    }
    i-=1;
    permutation(S,0,i);    
}
