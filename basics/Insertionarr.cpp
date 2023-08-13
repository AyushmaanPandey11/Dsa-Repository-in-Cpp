#include<iostream>
using namespace std;
//displays the array,travsering
void display(int arr[],int size)
{
    for(int idx=0;idx<size;idx++)
    {   
        cout<<arr[idx]<<" ";
    }
    cout<<endl;
}
int insertion(int arr[],int size,int capacity,int element,int idx)
{   
    //checks for overflow
    if(size>=capacity)
    {
        return -1;
    }
    //shifting the elements towards right until it reaches to  
    for(int ins=size-1;ins>=idx;ins--)
    {
        arr[ins+1]=arr[ins];
    }
    arr[idx]=element;
    return 1;
}
int main ()
{
    int arr[5]={4,7,56,1};
    int size=4;
    int element =99;
    int idx=1;
    int capacity=5;
    display(arr,size);
    insertion(arr,size,capacity,element,idx);
    size+=1;
    cout<<"updated array is "<<endl;
    display(arr,size);
    return 0;
}