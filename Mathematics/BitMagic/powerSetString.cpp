// for a given string , generate all the powersets = set of all the subsets 
#include<iostream>
#include<cmath>
using namespace std;

void powerSetStringRecursive(string str,int i = 0,string res = ""){
    // !T(n) = O(2^n)
    // !S(n) = O(2^n)
    if(i > str.length()){
        return ;
    }
    if(i == str.length()){
        cout << res <<"\n";
        return;
    }
    powerSetStringRecursive(str,i+1,res);// left branch for not appending anything
    powerSetStringRecursive(str,i+1,res+str[i]); // right branch for appending the current index character 
}
void powerSetStringIterative(string str){
    // !T(N) = O(2^n)
    int upperBound = pow(2,str.length());
    for(int i = 0;i<upperBound;i++){
        string res = "";
        int count = 0,j = i;
        while(j > 0){
            // !T(n) = thetha(no of bits)
            if((j&1) == 1){
                res = res + str[count];
            }
            count ++;
            j = j>>1;
        }
        cout << res << "\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    powerSetStringRecursive(str);
    cout <<"\n";
    powerSetStringIterative(str);
    return 0;
}