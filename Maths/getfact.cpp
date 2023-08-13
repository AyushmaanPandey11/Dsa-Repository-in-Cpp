#include<iostream>
#include<math.h>
using namespace std;
int getfactorial(int num)
{
    int m = 10^9 + 7;
    long long ans = 1;
    for(int idx= 0 ; idx <= num ; idx++)
    {
        ans = ((ans%m)*(idx%m))%m;
    }
    return ans;
}
int main ()
{
    int number;
    cout<<"enter the number"<<endl;
    int ans = getfactorial(number);
    cout<<" the remainder is "<<ans;
    return 0;
}