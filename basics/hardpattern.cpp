#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter a value"<<endl;
    cin>>n;
    int i=1;
    while(i<=n)
    {
        int j=1;
        while(j<=(n+1)-i)
        {
            cout<<j;
            j=j+1;
        }
          int star=1;
        while(star<=i-1)
        {
            cout<<"**";
            star=star+1;
        } 
        int k=1;
         int value=n-i+1;
        while(k<=n-i+1)
        {
           
            cout<<value; 
            value=value-1;
            k=k+1;
        } 
        cout<<endl;
        i=i+1;
    }
}