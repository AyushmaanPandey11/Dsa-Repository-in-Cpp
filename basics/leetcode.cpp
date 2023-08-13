#include<iostream>
using namespace std;
int uniquearr(int arr[],int n)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        
        ans=ans^arr[i];
    }
    for(int i=0;i<(n-1);i++)
    {
        ans=ans^arr[i];
    }
    return ans;

}
int main()
{
    int a[5]={5,1,2,3,1};
    int b=uniquearr(a,5);
    cout<<endl;
    cout<<b;
    return 0;
}