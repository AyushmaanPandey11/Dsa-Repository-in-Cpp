#include<iostream>
using namespace std;

bool findTarget ( int matrix[][3], int target ,int row, int col)
{
    for(int idx=0; idx < row ; idx++)
    {
        for(int idy= 0; idy  < col ; idy++ )
        {
            if(matrix[idx][idy] == target )
            {
                return 1 ;
            }
        } 
    }
    return 0;
}
int main ()
{
    int matrix[3][3] ;
    cout<<" enter values in the matrix"<<endl;

    for(int row=0; row <3; row++)
    {
        for(int col= 0; col < 3 ; col++ )
        {
            cin>>matrix[row][col];
        } 
    }
    int target = 12;
    cout << " the presence of the value " << target <<" is " << findTarget(matrix, target, 3, 3); 
    



    return 0;
}