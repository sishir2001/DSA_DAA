// finding the duplicates using bitwise operations.
// here only for the lower case.
// time complexity - O(n)
#include<stdio.h>
#define NTERM '\0'
void duplicates(char *p){
    int H = 0; // bitset of 4 bytes = 32 bits , as we require 26 bits for lowercase alphabets.
    for(int i=0;p[i]!=NTERM;i++){
        int a =1;
        a = a<<(p[i]-'a');// for masking and merging
        if((a&H)==0)// condition inside the if is masking in bits 
        H = H|a;// merging in bits
        else
        {
            printf("%c ",p[i]);// printing the duplicates.
        }
        
    }
}
void main(void){
    char *s = "finding",*a = "sishir";
    duplicates(s);
    printf("\n");
    duplicates(a);
}