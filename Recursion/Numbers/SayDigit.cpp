#include<iostream>
using namespace std;
void saydigit(int number , string arr[])
{
    // base cases 
    if(number == 0)
        return ;
    // processing
    int digit = number%10;
    number = number/10;

    // recursive function calling 
    saydigit(number, arr);
    cout<<arr[digit]<<" ";
}
int main()
{
    string arr[10] = {"ZERO" , "ONE " , "TWO" , "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    int number ;
    cout<<"enter the number "<<endl;
    cin>>number;
    cout<<"the number in words is " <<endl;
    saydigit(number,arr);
    return 0;

}