#include<iostream>
using namespace std;

int length( char string[] )
{
    int count=0;
    for (int idx=0 ; string[idx] != '\0'; idx++)
    {           
        count++;
    }
    return count;
}
void reverse(char name[], int size )
{
    int start=0;
    int end = size - 1;
    while(start <  end )
    {
        swap(name[start++],name[end--]);
    }
    cout<<"The reverse of the word is "<<name<<endl;
}
char tolowercase(char string )
{
    if( string >= 'a' && string <= 'z' )
    {
        return string;
    }
    else 
    {
        char lower = string - 'A' + 'a';
        return lower;
    } 
}
bool checkpalindrome( char string[], int size )
{
    int start = 0; 
    int end = size -1 ;
    while ( start <= end )
    {
        if( tolowercase(string[start]) != tolowercase(string[end]) )
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


int main()
{
    char name[20];
    cout<<" Enter a word please "<<endl;
    cin>>name;
    cout<<"the Length of the word is "<<length(name)<<endl;
    int len= length(name);
    reverse(name,len);
    cout<<"The word is palindrome or not "<<checkpalindrome(name, len);
    return 0;
}