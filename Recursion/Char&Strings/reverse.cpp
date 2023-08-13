#include<iostream>
using namespace std;
void reverse( string &str , int start , int end)
{
    // base case
    if(start > end)
        return ;
    swap(str[start] , str[end]);
    start++;
    end--;
    // recursion 
    reverse(str,start,end);
}
void rev( string &str, int idx)
{
    // base case
    if( idx > (str.length() - idx -1))
        return ;
    // for the last element idx use " size - 1 - idx".
    swap( str[idx] , str[ (str.length()-1-idx) ]);
    idx++;
    //recursion 
    rev(str,idx);
}
int main()
{
    string str = "Ayushmaan" ;
    //reverse(str,0,str.length()-1);
    rev(str,0);
    cout<<"reverse of the given string is :"<<str<<endl;
    
    return 0;
}