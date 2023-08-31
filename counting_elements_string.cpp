#include <iostream>
using namespace std;
int len(char s[]){
int i=0;
while(s[i]!='\0'){
i++;
}
return i;
}
int main(){
    char s[]="helloworld";
    int length=len(s);
    cout<<"the length of the string \n"<<s<<"is \n"<<length;
    return 0;

}