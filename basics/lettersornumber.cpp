#include<iostream>
using namespace std;
int main()
{
    char n;
    cout<<"enter a value "<<endl;
    cin>>n;
    if(n>=65 && n<=90)
    {
        cout<<"the value is a Uppercase character";
    }
    else if(n>=97 && n<=122)
    {
        cout<<"the value is a Lowercase character";
    }
    else
    {
        cout<<"the value is a integer datatype";
    }
}
