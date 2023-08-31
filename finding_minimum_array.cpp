#include <iostream>
using namespace std;
int findmin(int arr[] ,int i,int j) {
    int min=arr[i];
    for (int k = 1+i; k < j; k++)
    {
        if (arr[k]<min)
        {
           min=arr[k];
        }
        
    }
    return min;
}
int main(){
   int arr[]={1,2,8,7,-8,-78,3,-100,5};
    int i=0,j=5;
    int min=findmin(arr,i,j);
    cout<<"the min value at poition"<<" "<<i<<"and position"<<" "<<j<<" is "<<min<<endl;
    return 0;

}