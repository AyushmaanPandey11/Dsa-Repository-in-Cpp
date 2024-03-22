#include<iostream>
#include<cstring>
using namespace std;

string sentenceWordrev( string str )
{   
    int idx = 0;
    int end = str.length() - 1 ;
    int first=0;
    while( idx <= end )
    {   
        
        if(str[idx] == ' ')
        {   
            int last = ( idx == end ) ? idx : idx-1;
            while(first <= last )
            {  
                swap(str[first++],str[last--]);
            }
            first = idx+1;  
        }
       
        idx++;   
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