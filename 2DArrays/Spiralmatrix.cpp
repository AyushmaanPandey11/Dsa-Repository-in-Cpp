#include<iostream>
#include<vector>
using namespace std;

void display( vector<vector<int>> matrix ) 
{   
    
    for(int idx=0; idx < matrix.size() ; idx++)
    {
        for(int idy= 0; idy < matrix[0].size() ; idy++ )
        {
            cout<<matrix[idx][idy]<<" ";
        }
        cout<<endl;
    }
}
void show( vector<int> matrix ) 
{   
    
    for(int row=0; row< matrix.size() ; row++)
    {
        for(int col= 0; col < 3; col++ )
        {
            cout<<matrix[col]<<" ";
        }
        cout<<endl;
    }
}

vector<int> spiralmatrix(vector<vector<int>> matrix )
{   
    vector<int> answer;
    int count=0;
    int row = matrix.size();
    int col = matrix[0].size();
    int total= row*col;
    // initializing indices
    int startrow=0;
    int startcol=0;
    int endrow= row-1;
    int endcol= col-1;

    while(count<total)
    {
        for(int idx = startcol; count<total && idx <= endcol; idx++ )
        {
            answer.push_back(matrix[startrow][idx]);
            count++;
        }
        startrow++;
        for(int idx = startrow;  count<total && idx <= endrow ; idx++ )
        {
            answer.push_back(matrix[idx][endcol]);
            count++;
        }
        endcol--;
        for(int idx = endcol ;  count<total && idx >=startcol ; idx--)
        {
            answer.push_back(matrix[endrow][idx]);
            count++;
        }
        endrow--;
        for(int idx = endrow;  count<total && idx >= startrow ; idx--)
        {
            answer.push_back(matrix[idx][startcol]);
            count--;
        }
        startcol++;
    } 
  
    return answer;
}

int main()
{
    vector<vector<int>> matrix;
    int arr[3][3];
    cout<<" enter values in the matrix"<<endl;
    for(int row=0; row <3; row++)
    {   
        vector<int> temp;
        for(int col= 0; col < 3 ; col++ )
        {
            cin>>arr[row][col];
        } 
    }
    for(int row=0; row <3; row++)
    {   
        vector<int> temp;
        for(int col= 0; col < 3 ; col++ )
        {
            temp.push_back(arr[row][col]);
        } 
        matrix.push_back(temp);
    }
    display(matrix);
 
    return 0;
}