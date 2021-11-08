#include<stdio.h>
// palindromes in string 
void check_palindrome(char *s){
    int i =0;
    for(;s[i]!='\0';i++){

    }
    i=i-1;
    int count =0;
    for(int j=0;j<i;j++,i--){
        if(s[j] != s[i]){
        count =1;
        printf("%s is not a palindrome\n",s);
        break;
        }
    }
    if(count == 0)
    printf("%s is a palindrome\n",s);
}

void main(void){
    char s[] = "madam",a[] = "sisihri",d[] = " madam madam ";
    check_palindrome(s);
    check_palindrome(a);
    check_palindrome(d);
}
