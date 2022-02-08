#include<stdio.h>

char find_non_repeating(char* arr,int len){
    char result ;
    int gotFirst = -1; // if 0 then got the first non repeating character .
    int HashArray[26] = {0};
    for(int i= 0;i<len;i++){
        // traversing string for character count in HashArray. 
        HashArray[arr[i]-97]++;
    }

    for(int j = 0;j<len;j++){
        // selecting the second non repeating character .
        if((HashArray[arr[j]-97] == 1) && (gotFirst == -1)){
            // this condition is for first non-repeating character 
            gotFirst = 0;
            continue;
        }
        else if(HashArray[arr[j]-97] == 1 && gotFirst == 0){
            // condition for second non-repeating character 
            printf("\n %d ",j);
            result = arr[j];
            break;
        }
    }
    return result;
}
int main(){
    char arr[6] = {'a','a','b','b','c','d'};
    char re = find_non_repeating(arr,6);
    printf("\n%c",re);
    return 0;
}
