#include<iostream>
using namespace std;

bool alphanumeric(char ch)
{
    if( (ch >= 'a' && ch <= 'z') && (ch >= 'A' && ch <= 'Z') && (ch >= 0 && ch <= 9) )
    {
        return 1;
    }
    
    return 0; 
}
char tolowercase(char string )
{
    if( (string >= 'a' && string <= 'z') && (string >= 0 && string <= 9) )
    {
        return string;
    }
    else 
    {
        char lower = string - 'A' + 'a';
        return lower;
    } 
}
bool check(string str)
{
    int start = 0;
    int end = str.length()-1;
    while (start <= end )
    {
        if(str[start] != str[end])
        {
            return 0;
        }
        else 
        {
            start++;
            end--;
        }
    }
    return 1;
     
}

bool palindrome(string str)
{
    string str1 = "";
    for( int idx = 0 ; idx < str.length() ; idx++ )
    {
        if(alphanumeric(str[idx]))
        {
            str1.push_back(str[idx]);
        }
    } 
    for( int idx = 0; idx < str1.length(); idx++)
    {
        str1[idx] = tolowercase(str1[idx]); 
    }
    return check(str1);
}
int main()
{
    string str ;
    cout<<" enter the sentence"<<endl;
    cin>>str;
    cout<<"the word is palindrome or not ignoring the special characters "<<palindrome(str);
    return 0;
}
