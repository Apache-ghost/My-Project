#include <iostream>
using namespace std;
void substring(char sub[],char s[],int i,int j){
    int k=0;
    for (int  index = i; index<= j; index++)
    {
       Sub[k] = S[index]; 
    }
    Sub[k] ='\0';
}
int main(){
    char s[]="hellow world";
    char sub[7];
    int i=0,j=7;
    substring(sub,s,i,j)
    cout<<"the substring of the of \n"<<s<<" "<<"between position 0 and 7 is \n"<<sub;
    return 0;
}