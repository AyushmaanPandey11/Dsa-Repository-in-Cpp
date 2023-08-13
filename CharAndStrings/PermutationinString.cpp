#include<iostream>
using namespace std;

bool compare(int arr1[26], int arr2[26])
{      
    for( int idx=0 ; idx<26 ; idx++ )
    {
        if(arr1[idx] != arr2[idx])
        {
            return 0;
        }  
    }  
    return 1;
}
bool checkPermutation( string str1, string str2 )
{   
    // for storing the values of str1 char values
    int arr1[26] = {0};
    for(int idx=0; idx < str1.length(); idx++ )
    {
        int index = str1[idx] - 'a';
        arr1[index]++;
    }
    // traversing the arr2 string of windowsize of arr1
    int arr2[26] = {0};
    int windowsize = str1.length();
    int idx = 0 ;
    // runnig the first window 
    while(idx < str2.length() && idx < windowsize)
    {
        int index = str2[idx] - 'a' ;
        arr2[index]++;
        idx++;
    }
    if ( compare( arr1 , arr2 ) )
    {
        return 1 ;
    }
    // now it goes to the next window with first ch is deleted and now char is added
    // new char is added and then checked 
    while(idx < str2.length())
    {   
        char newchar = str2[idx]; //idx in str2[idx] as in last function idx is already incremented
        int index2 = newchar - 'a' ;
        arr2[index2]++;
    // removing the old char from the window    
        char oldchar = str2[idx - windowsize];
        index2 = oldchar - 'a';
        arr2[index2]--;
        idx++; 
        if( compare ( arr1, arr2 ) )
        {
            return 1 ;
        }       
    }
     
    return 0;
}
int main()
{
    string str1 = "adidasd";
    string str2 = "as";
    cout <<" the presence of the str2 in str1 is " << checkPermutation( str2, str1 );
    return 0 ;   
}