#include<iostream>
#include<vector>
using namespace std;
 
vector<vector<int>> Rotation( vector<vector<int>> matrix )
{
    int startrow = 0 ;
    int startcol = 0 ;
    int endrow = matrix.size() - 1 ;
    int endcol = matrix[0].size() - 1;
    
    while ( startrow <= endrow && startcol <= endcol )
    {   
        int er = endrow;
        int ec = endcol;
        int sr = startrow;
        int sc = startcol;
        // 90 rotation of outer boundary elements...
        while( ( sr < endrow && sc < endcol )  &&  ( er > startrow && ec > startcol ) )
        {
        int element1 = matrix[sr][endcol];
        int element2 = matrix[endrow][ec];
        int element3 = matrix[er][startcol];
        matrix[sr][endcol] = matrix[startrow][sc];
        matrix[endrow][ec]= element1;
        matrix[er][startcol]=element2;
        matrix[startrow][sc]=element3;
        sr++;
        sc++;
        er--;
        ec--;
        }
        startrow++;
        startcol++;
        endrow--;
        endcol--;
    }
    return matrix;
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
    cout<< "the present of the element is "<<endl;
    for(int idx=0; idx < 3 ; idx++)
    {
        for(int idy= 0; idy < 3 ; idy++ )
        {
            cout<<mat[idx][idy]<<" ";
        }
        cout<<endl;
    }
    cout<<"rotated matrix is "<<endl;
    display(Rotation(to2Dvector(mat, 3,3))); 
    return 0;
}