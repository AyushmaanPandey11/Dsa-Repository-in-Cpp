#include<iostream>
#include<math.h>
using namespace std;

void  Power(int x)
{   
        int p=0;
        while(x!=0)
        {
            if(x&1)
            {
                p++;
            }   
            x=x>>1;
        }
        if(p==1)
        {
            cout<<"numberis the power of 2"<<endl;
        }
        else
        {
            cout<<"number is not a pwer of 2"<<endl;
        }

}


int main()
{   
    int x;
    cout<<"enter the number to find "<<endl;
    cin>>x;
    Power(x);
    
    return 0;
}