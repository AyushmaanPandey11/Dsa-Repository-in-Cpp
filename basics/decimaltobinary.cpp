#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter a decimal value"<<endl;
    cin>>n;
    int bin=0;
    int ans=0;
    int i=0;
    while(n!=0)
    {  
        int bit=(n&1);
        ans=(bit*pow(10,i))+ans;  
        i++;
        n=n>>1;  
    }  
     cout<<"binary value of the number is "<<ans;
}