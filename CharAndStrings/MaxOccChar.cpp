#include<iostream>
using namespace std;
char MaxOccCharacter(string str)
{
    int arr[26]={0};
    int idxcount=0;
    // in the arr[] it stores the number of occ of char in the string
    for( int idx=0; idx<str.length() ; idx++ )
    {
        char ch = str[idx];
        idxcount = ch - 'a';
        arr[idxcount]++;
    }
    //finds max occ of the char 
    // maxi takes the value of occurence, to check it with other elements occ, ans takes maxi indx to give the char
    int maxi= -1; 
    int ans=0;
    for( int idx=0; idx<26; idx++ )
    {
        if( maxi < arr[idx] )
        {
            maxi = arr[idx];
            ans = idx;
        }
    }
    return ('a' + ans);
}
int main()
{
    string str;
    cout<<"Enter the string "<<endl;
    cin>> str;
    cout<< " The maximum occurence of the character in the string is "<< MaxOccCharacter(str)<<endl;
    return 0;
}