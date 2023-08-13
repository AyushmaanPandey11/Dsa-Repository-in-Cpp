#include<iostream>
using namespace std;
bool Palindrome( string str , int start, int end )
{
    if( start > end )
    {
        return true;
    }
    // if not a palindrome
    if( str[start] != str[end] )
        return false;
    // recursive call
    else
    {
        return Palindrome(str, start+1 , end-1);
    }
}
bool Palindrom( string &str, int idx)
{
    if( idx > (str.length() - idx -1))
        return true;
    if( str[idx] != str[ str.length()-1-idx])
    {
        return false;
    }
    // recursive call
    else
    {
        idx++;
        return Palindrom(str,idx);
    }
}
void display( string &str )
{
    for( int idx =0 ; idx < str.length() ; idx++ )
    {
        cout<< str[idx] << " ";
    }
    cout<<endl;
}
int main()
{
    string str = "malayalam";
    cout<< " the string is: ";
    display(str);
    //cout<<"checking whether the element is palindrone or not: "<<Palindrome(str,0 , str.length()-1 );
    cout<<"checking whether the element is palindrone or not: "<<Palindrom(str, 0 );
    return 0;
}