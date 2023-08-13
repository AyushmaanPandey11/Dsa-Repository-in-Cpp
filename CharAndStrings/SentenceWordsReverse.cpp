#include<iostream>
#include<cstring>
using namespace std;

string sentenceWordrev( string str )
{   
    int start = 0;
    int end = str.length() - 1 ;
    int first=0;
    while( start <= end )
    {   
        
        if(str[start] == ' ')
        {   
            int last = start-1;
            while(first <= last )
            {  
                swap(str[first++],str[last--]);
            }
            first = start+1;  
        }
       
        start++;   
    }
    return str;
}
int main()
{
    string str;
    getline(cin,str);
    cout << " the output is "<< sentenceWordrev(str);
    return 0;
}