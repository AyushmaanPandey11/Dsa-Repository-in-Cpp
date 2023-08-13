#include<iostream>
#include<vector>
using namespace std;

void solve( string digits , string output ,int idx , vector<string> &ans , string mapping[] )
{
    // base case 
    if( idx == digits.length() )
    {
        ans.push_back(output);
        return;
    }
    // taknig out the number from digits
    int number = digits[idx] - '0';
    string letter  = mapping[number];

    // maing the combinations .. keep in mind to make idx name seprate from the functio idx
    for( int idx1 =0; idx1 < letter.length(); idx1++ )
    {
        output.push_back(letter[idx1]);
        solve( digits,output,idx+1,ans,mapping );
        output.pop_back();
    }
}
void letterCombinations( string digits, vector<string> &ans )
{
    string output="";
    if( digits.length() == 0 )
        return; 
    int idx =0;
    string mapping[10] = { "", "", "abc", "def", "ghi" , "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(  digits , output , idx , ans, mapping );
} 
void display(  string digits )
{
    cout<<"The array is: ";
    cout<<"{ ";
    for( int idx =0; idx<digits.length(); idx++ )
    {
        cout<<digits[idx]<<" ";
    }
    cout<<"}"<<endl;
}
int main()
{
    string digits = "23";
    display(digits);
    vector<string> ans;
    cout<<"Consequences of the string str is :"<<endl;
    letterCombinations(digits,ans);
    for( int idx =0; idx < ans.size() ; idx++)
    {
        cout<<"{"<<ans[idx]<<"}"<<" ";
    }
    return 0;
}