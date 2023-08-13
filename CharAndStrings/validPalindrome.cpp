#include<iostream>
using namespace std;
/*  valid palindrome
    1.from the sentence, remove all the space and non alphanumeric char
    2.convert to lowercase
    3.Check the palindrome and display the output 
*/
//  checks each char of the string and return returns in 1 or 0..
bool onlyAplhanumeric(char ch)
{
    if( (ch >= 'a' && ch <= 'z') && (ch >= 0 && ch <= 9) && (ch >= 'A' && ch <= 'Z') )
    {
        return 1;
    }
    else 
    return 0;
}

char tolowercase(char ch)
{
    if( (ch >= 'a' && ch <= 'z') && (ch >= 0 && ch <= 9) )
    {
        return 1;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
 bool checkpalindrome( string str)
{
    int start = 0; 
    int end = str.length() - 1 ;
    while ( start <= end )
    {
        if( str[start] != str[end] )
        {
            return 0 ;
        }
        else 
        {
            start++;
            end--;
        }
    }
    return 1;
}

int ispalindrome(string str)
{
    string temp = "";
    for(int idx=0 ; idx < str.length() ; idx++)
    {
        if(onlyAplhanumeric( str[idx] ) )
        {
            temp.push_back(str[idx]);
        }
    }
    // to convert the temp string to lower case
    for( int idx=0 ; idx < str.length() ; idx++ )
    {
        temp[idx] = tolowercase(temp[idx]);
    }
    return checkpalindrome(temp);
}

int main()
{   
    string str;
    cout<<"enter the sentence to check for palindrome "<<endl;
    cin>>str;
    cout<<"the sentence is palindrome(1) or not(0) "<<ispalindrome(str);
    return 0;

}