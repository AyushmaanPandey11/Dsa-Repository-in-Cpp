#include<iostream>
using namespace std;
int main()
{
        int n;
        cout<<"enter a value";
        cin>>n;
        int i=0;
        int sum=0;
        while(i<=n)
        {
            sum=sum+i;
            i=i+1;
        }
        cout<<"the sum is "<<sum<<endl;
        int j=0;
        cout<<"and the number below it are "<<endl;
        while(j<=n)
        {
         cout<<j<<endl;
         j=j+1;
        }
}