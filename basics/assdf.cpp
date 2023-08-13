
#include <iostream>
using namespace std;
 void totalbits(int a,int b)
 {
        int count1=0;
        int count2=0;
        int count=0;
        while(a!=0)
        {
            if(a&1)
            {
                count1++;
            }
        a=a>>1;
        }
        while(b!=0)
        {
            if(b&1)
            {
                count2++;
            }
            b=b>>1;
        }
        count=count1+count2;
        cout<<"Total number of 1 bits are "<<count;

        return ;
 }

int main()
{
    int a,b;
    cout<<"enter the values of a and b"<<endl;
    cin>>a>>b;
    totalbits(a,b);
    
    return 0;
}