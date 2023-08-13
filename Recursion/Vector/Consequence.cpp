#include<iostream>
#include<vector>
using namespace std;

void solve( string str,string output , int idx , vector<string> &ans)
{
    // base case
    
        if( idx >= str.length() )
        {
            if( output.length() >0)
            {
                ans.push_back(output);
            }
            return ;
        }
    // recursion
    // exclude
    solve( str , output, idx+1 , ans );
    //include
    int element = str[idx];
    output.push_back(element);
    solve( str,output,idx+1,ans );
}
void consequences( string str , vector<string> &ans )
{
    
    string output;
    int idx =0;
    solve( str,output,idx,ans );
}
void display( string str )
{
    for( int idx =0; idx< str.length(); idx++)
    {
        cout<<str[idx]<<" ";
    }
    cout<<endl;
}
int main()
{
    string str = "abc";
    display(str);
    vector<string> ans;
    consequences(str,ans);
    cout<<"Consequences of the string str is :"<<endl;
    for( int idx =0; idx<ans.size() ; idx++)
    {
        cout<<"{"<<ans[idx]<<"}"<<" ";
    }
    return 0;
}