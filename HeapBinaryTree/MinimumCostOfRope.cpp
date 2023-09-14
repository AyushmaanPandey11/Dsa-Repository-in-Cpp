#include<iostream>
#include<queue>
using namespace std;

            /*
                    Minimum cost rope problem
                - There are N number of roppes and sum of connecting two rope is sum of their length.
                  Problem is to find the minimum cost of connecting the ropes.
                - Solution is to adding the first two smallest numbers that is the top of min heap and adding it to a variable
                  sum and to the minheap as it is also a rope of two ropes, then deleting the top 2 element and do this a loop till its size becomes 1.
            */
           int mincost( int arr[], int size )
           {
                // minheap creation
                priority_queue<int,vector<int>,greater<int>> pq;
                // adding all the number of ropes lenth in the minheap
                for( int idx=0; idx<size; idx++ )
                {
                    pq.push(arr[idx]);
                }
                int cost=0;
                while( pq.size() > 1 )
                {
                    int first = pq.top();
                    pq.pop();
                    int second = pq.top();
                    pq.pop();
                    int sum = first + second;
                    cost += sum;
                    // pushing again to the minheap
                    pq.push(sum);
                }
                return cost;
           }
           void display( int arr[], int size )
           {
                for( int idx=0; idx<size; idx++ )
                {
                    cout<<arr[idx]<<" ";
                }
                cout<<endl;
           }
           
int main()
{
    int ropes[5] = { 5, 10 , 20 , 15 , 25 };
    int size = 5;
    cout<<" The given ropes are : ";
    display(ropes,size);
    cout<<"Minimum cost taken to connect 5 ropes to a single one :"<<mincost(ropes,size);
    cout<<endl;
    return 0;
}