#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int p,a,b,c,d;
         for(int i=1;i<=n;i++)
    {
             switch(i)
        {
           
                case 1 :    p=n/100;
                            cout<<"number of 100 rupee notes are"<<p<<endl;
                            n=n%100;
                case 2 :
                            a=n/50;
                            cout    <<"number of 50 rupee notes are "<<a<<endl;
                            n=n%50;
                
                case 3 : 
                            b=n/20;
                            cout<<"number of 20 rupee notes are "<<b<<endl;
                            n=n%20;
               
                case 4 : 
                            c=n/10;
                            cout<<"number of 10 rupee notes are "<<c<<endl;
                            n=n%10;
    
                case 5 : 
                            d=n;
                            cout<<"number of 1 rupee coins are "<<d<<endl;
                            break; 
        }      
    }
        
    return 0;
}

