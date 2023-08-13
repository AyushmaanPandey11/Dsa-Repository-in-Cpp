#include<iostream>
using namespace std;

int main ()
{

    int row , col ;
    cout<<"Enter the values of the rows and column of the 2D array "<<endl;
    cin>>row>>col;
    // creation of the 2D array heap 
    int** arr = new int*[row];
    for( int idx = 0 ; idx < row ; idx++)
    {
        arr[idx] = new int[col];
    }

    // for taking values in the array 
    cout<<"Enter the elements to be displayed in the 2D array"<<endl;
    for( int idx = 0 ; idx < row ; idx++)
    {
        for( int idy= 0 ; idy < col ; idy++ )
        {
            cin>>arr[idx][idy];
        }
    }

    // for showing the output of the array
    cout<<endl; 
    for( int idx=0 ; idx < row ; idx++ )
    {
        for( int idy=0; idy < col ; idy++ )
        {
            cout<<arr[idx][idy]<<" ";
        }
        cout<<endl;
    }

    // releasing the memory from the heap 
    for ( int idx =0 ; idx< row ; idx++ )
    {
        delete [] arr[idx];
    }
    delete [] arr;

    return 0 ;
}