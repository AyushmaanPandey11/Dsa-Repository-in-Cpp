#include<iostream>
using namespace std;
int main ()
{
    int row;
    cout<<"Enter the number of rows in the array "<<endl;
    cin>>row;
    // array to store values of number of column each row to have
    int * numberOfCol = new int[row]; 
    // creation of the Jagged 2D Array
    int ** JArray = new int*[row];
    // for taking the values of numberOfCol in the array 
    for( int idx =0; idx < row ; idx++ )
    {
        cout<< "Enter the number of column in the row "<< idx << " : "<<endl;
        cin>>numberOfCol[idx];
        JArray[idx] = new int[numberOfCol[idx]];
    }
    // for taking the values in the array 
    for( int idx =0; idx < row ; idx++ )
    {   
        cout<<"enter the values in the row "<< idx <<endl;
        for(int idy =0 ; idy  < numberOfCol[idx]; idy++)
        {
            cin>>JArray[idx][idy];
        }
    }
    // showing the output of the array 
    cout<<"The Jagged Array is "<<endl;
    for(int idx=0; idx< row ; idx++)
    {   
        for(int idy=0; idy< numberOfCol[idx] ; idy++)
        {
            cout<< JArray[idx][idy]<<" ";
        }
        cout<< endl;
    }
    // releasing the memory 
    for( int idx =0; idx < row ; idx++)
    {
        delete [] JArray[idx];
    }
    delete [] numberOfCol;
    return 0;
}