#include<iostream>
using namespace std;
int getmin(int num[],int n)
{
    int mini=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int mini=min(mini,num[i]);
    }
    return mini;
}
int getmax(int num[],int n)
{
    int maxi=INT_MAX;
    for(int i=0;i<n;i++)
    {
         int maxi=max(maxi,num[i]);
    }
    return maxi;
}




int main()
{
    int num[10];
    int size;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cin>>num[i];
    }

    cout<<"minimum value is "<<getmin(num, size);
    cout<<"maximum value is "<<getmax(num, size);
    return 0;
}