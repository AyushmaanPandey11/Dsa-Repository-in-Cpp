#include<iostream>
using namespace std;
/*
    1. Heap is a Data Structure that is a complete binary tree in the added elements are done from left child of the nodes and posses the two headp order property 
    2. Complete Bt is a binary tree where every level in completely filled except the lowest level and the the lowest level insertion done from the left child of nodes
    3. Two properties are :-
        1. Max Heap property - Where the value of the child node < value of the parent node
        2. Min Heap propery - where the valuye of he child node > value of the parent node
*/
class Heap
{
    public :
            int arr[100];
            int size;

    public : 
            Heap()
            {
                size = 0;
                // in Heaps, We dont use the first 0th index, thats why it is initialised as -1
                arr[0]=-1;
            }
            void insertion( int val )
            {
                // increamenting the size by one
                size = size + 1;
                // index initialisation and definition 
                int index = size;
                // storing the value inside the new block of array at the end
                arr[index]= val;
                // child and parent node
                while( index > 1 )
                {
                    // getting the parent node index in the array
                    int parent = index/2;
                    // checking for values between them 
                    if( arr[parent] < arr[index] )
                    {
                        swap( arr[parent], arr[index] );
                        index = parent;
                    }
                    else
                    {
                        return ;
                    }
                } 
            }
            void print()
            {
                cout<<"Values in the array are :"<<endl;
                for( int idx=1; idx<=size; idx++ )
                {
                    cout<<arr[idx]<<" ";
                }
                cout<<endl;
            }
            // deletion from front
            /*
            Algorithm 
            1. first put the last index vlaue to the first index  value 
            2. delete the last node value from the array 
            3. propoogate the root node to its correct position
            */
           void deleteFromFront()
           {
                // checking the size
                if( size == 0 )
                {
                    cout<<"Condition Underflow "<<endl;
                    return;
                }
                // first step 
                arr[1] = arr[size];
                // second step
                size--;
                // third step
                int idx=1; 
                // checking existence of left child
                while( idx < size )
                {
                    int leftchildidx = 2*idx;
                    int rightchildidx = 2*idx +1;
                    if( arr[leftchildidx] > arr[idx] && leftchildidx <= size && arr[leftchildidx]>arr[rightchildidx])
                    {
                        swap(arr[leftchildidx],arr[idx]);
                        idx = leftchildidx;
                    }
                    else if( arr[rightchildidx]>arr[idx] && rightchildidx <= size )
                    {
                        swap(arr[rightchildidx],arr[idx]);
                        idx = rightchildidx;
                    }
                    else
                    {
                        return;
                    }
                }
           }
};
int main()
{
    Heap h1; 
    h1.insertion(50);
    h1.insertion(55);
    h1.insertion(53);
    h1.insertion(52);
    h1.insertion(54);
    h1.print();
    h1.deleteFromFront();
    h1.deleteFromFront();
    h1.print();
    return 0;
}
