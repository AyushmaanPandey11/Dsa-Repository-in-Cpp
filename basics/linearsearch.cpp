#include<iostream>
using namespace std;

void linearsearch(int arr[],int size,int key)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==key)
        {
            cout<<"the element is present in the array at "<<i<<endl;
        }
    }
}
int main ()
{   
    int a[10]={4,56,71,7,44 ,12 ,23,65,76,10};
    int key;
    cout<<"enter the element to search in the array ";
    cin>>key;
     linearsearch(a,10,key);
    return 0;
}