#include<iostream>
#include<vector>
using namespace std;

bool isSafe( int newx, int newy , int num , vector<vector<int>> visited , vector<vector<int>> m  )
{
    if( (newx >=0 && newx <= num-1) && ( newy >=0 && newy <= num -1 ) && ( visited[newx][newy] == 0 ) && ( m[newx][newy]==1 ) )
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Solve ( vector<vector<int>> m , int num , int &npaths , vector<string> &totalpaths, int srcx , int srcy , vector<vector<int>> visited , string path )
{
    // you have reached srcx,srcy here in first it is 1 in (0,0).
    // base case is that you have reached destination
    if( srcx == num -1 && srcy == num -1 )
    {
        totalpaths.push_back(path);
        npaths++;
        return ;
    }
    visited[srcx][srcy]=1;
    // movement of the rat in 4 directions
    // down
    int newx = srcx+1;
    int newy = srcy;
    if( isSafe( newx, newy , num , visited , m) )
    {
        path.push_back('D');
        Solve( m , num , npaths, totalpaths , newx , newy , visited , path );
        path.pop_back();
    }
    // up 
    newx = srcx-1;
    newy = srcy;
    if( isSafe( newx, newy , num , visited , m) )
    {
        path.push_back('U');
        Solve( m , num ,npaths,  totalpaths , newx , newy , visited , path );
        path.pop_back();
    }
    // left
    newx = srcx;
    newy = srcy-1;
    if( isSafe( newx, newy , num , visited , m) )
    {
        path.push_back('L');
        Solve( m , num ,npaths,  totalpaths , newx , newy , visited , path );
        path.pop_back();
    }
    // right
    newx = srcx;
    newy = srcy+1;
    if( isSafe( newx, newy , num , visited , m) )
    {
        path.push_back('R');
        Solve( m , num ,npaths,  totalpaths , newx , newy , visited , path );
        path.pop_back();
    }
    visited[srcx][srcy]=0;
}
void Paths( vector<vector<int>> m , int num , vector<string> &totalpaths, int &npaths )
{
    // if the source location is blocked 
    if( m[0][0] == 0 )
    {
        return ;
    }
    int srcx = 0;
    int srcy = 0;
    // making the visited array and initializing it to zero
    vector<vector<int>> visited = m;
    for( int idx = 0; idx < num ; idx++)
    {
        for( int idy =0; idy < num ; idy++ )
        {
            visited[idx][idy] = 0; 
        }
    }
    string path = "";
    Solve( m , num , npaths, totalpaths , srcx , srcy , visited , path );
}
void display( vector<vector<int>> m , int num )
{
for( int idx=0; idx< num ; idx++)
    {
        for( int idy=0; idy < num; idy++ )
        {
            cout<<m[idx][idy]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int num =4;
    vector<vector<int>> m(num, vector<int>(num));
    int npaths=0;
    vector<string> totalpaths;
    int arr[4][4] = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    // storing values from arr to m
    for( int idx=0; idx< num ; idx++)
    {
        for( int idy=0; idy < num; idy++ )
        {
            m[idx][idy]=arr[idx][idy];
        }
    }
    display(m,num);
    Paths(m, num,totalpaths,npaths);
    cout<<"Total number of paths is: "<<npaths<<endl;
    cout<<"All the possible paths are :";
    for( int idx =0; idx<totalpaths.size() ; idx++)
    {
        cout<<"{"<<totalpaths[idx]<<"}"<<" ";
    }
    
    return 0;
}
