#include <iostream>
using namespace std;
int findmaxpos(int arr[],int i,int j){
    int maxpos=arr[i];
    int pos=i;
    for (int  k = i+1; k < j; k++)
    {
      if (maxpos>arr[k])
      {
       maxpos=arr[k];
       pos=k;
      }
      
    }
    return pos;
    
}
int main(){
    int arr[]={1,2,7,8,7,-5,5,-48,1};
    int i=0, j=6;
    int pos=findmaxpos(arr,i,j);
    cout<<"the max position of "<<" "<<i<<" "<<"and"<<" "<<j<<"is"<<pos<<endl;
    return 0;
}