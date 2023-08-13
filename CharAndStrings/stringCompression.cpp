#include<iostream>
#include<vector>
using namespace std;


void stringCompression(vector<char> str)
{
    int first=0;
    int ansindex=0;
    int size = str.size();
    while ( first< size)
    {   
        int second = first + 1;
        while ( second < size && (str[second] == str[first]))
        {
            second++;
        }
        str[ansindex++] = str[first];
        int count = second - first ;
        if (count > 1)
        {
            string cnt = to_string(count);
            for(char ch: cnt)
            {
                str[ansindex++] = ch;
            }
        }
        first = second;
    }
    cout<<"The compressed string is ";
    for(int idx=0; idx<str.size();idx++)
    {
        cout<<str[idx];
    }
}
void display(vector<char> arr)
{   
    cout<<"the given string is ";
    for(int idx=0; idx<arr.size();idx++)
    {
        cout<<arr[idx];
    }
    cout<<endl;
}
int main()
{
    vector<char> ch ;
    ch.push_back('a');
    ch.push_back('a');
    ch.push_back('b');
    ch.push_back('b');
    ch.push_back('c');
    display(ch);
    stringCompression(ch);
    return 0;
}