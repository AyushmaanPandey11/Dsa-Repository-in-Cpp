#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the value "<<endl;
    cin>>n;
    int i=1;
    while(i<=n)
    {  
        int space=i-1;
        while(space)
        {
            cout<<" ";
            space=space-1;
        }
        int j=1;
   
        while(j<=n-i+1)
        {   // int star=n+1-i;
            cout<<j;
          //  star=star-1;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
        
    }
}