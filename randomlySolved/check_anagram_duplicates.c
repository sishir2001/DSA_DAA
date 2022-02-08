// checking anagram of the string with duplicate values.
#include<stdio.h>
int length(char *q){
    int i =0;
    for(;q[i]!='\0';i++){
    }
    return i;
}
void check_anagram(char *s,char *p){
    if(length(s) == length(p)){// checking the size.

        int H[] = {[0 ... 25] = 0};// initializing the hash table to 0.
        // setting the bits for string s
        for(int i =0;i<length(s);i++){
            ++H[s[i] -'a'];
        }
        // checking it with p
        int check= 0;
        for(int i=0;i<length(p);i++){
            if(H[p[i]-'a'] == 0)
            {
                check++;
                printf("%s %s are not anagrams\n ",s,p);
                break;
            }
        }
        if(check == 0)
        printf("%s %s are anagrams\n",s,p);
    }
    else
    {
        printf("%s %s are not an anagram\n",s,p);
    }
    
}
void main(void){
    
    check_anagram("verbose","observe");
    check_anagram("sishir","hfradd");
    check_anagram("sishir","sishir");
    check_anagram("stew","west");
}