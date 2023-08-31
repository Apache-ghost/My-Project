#include <iostream>
using namespace std;
void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[i]=temp;
}
int main(){
    int arr[]={1,23,5,58,9,};
    int i=0,j=4;
    int n=sizeof(arr);
    cout<<"before swapping "<<endl;
    for (int  k= 0; k < n; k++)
    {
        cout<<arr[k]<<" "<<endl;
    }
    swap(arr,i,j);

    cout<<"after swapping "<<endl;
    for (int  k = 0; k < n; k++)
    {
        cout<<arr[k]<<" "<<endl;
        return 0;
    
    

}
    