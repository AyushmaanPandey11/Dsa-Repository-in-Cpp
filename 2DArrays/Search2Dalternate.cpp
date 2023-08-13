#include<iostream>
#include<vector>
using namespace std;

bool searchmatrix( vector<vector<int>> matrix, int target )
{
    int row = matrix.size();
    int col = matrix[0].size();
    int startrow = 0;
    int startcol = col - 1;
    while( startrow < row && startcol>= 0 )
    {   
        int element = matrix[startrow][startcol];
        if( element == target ) 
        {
            return 1;
        }
        if ( element < target )
        {
            startrow++;
        }
        else 
        {
            startcol--;
        }
    } 
    return 0;
}
vector<vector<int>> to2Dvector(int arr[][3], int mrow ,int ncol)
{   
    vector<vector<int>> ans;
    for( int row =0; row < mrow ; row++)
        {   
            vector<int> temp;
            for( int col =0 ; col < ncol ; col++)
                {
                    temp.push_back(arr[row][col]);
                }
            ans.push_back(temp);
        }
    return ans;
}
int main()
{
    vector<vector<int>> matrix;
    int mat[3][3];
    cout<<"Enter elements in the matrix "<<endl;
    
    for( int row =0; row < 3 ; row++)
    {
        for( int col =0 ; col < 3 ; col++)
        {
            cin>>mat[row][col];
        }
    }
    cout<< " the present of the element is " << searchmatrix(to2Dvector(mat, 3,3), 0); 
    return 0;
}