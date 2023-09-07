#include<iostream>
using namespace std;
class Heap
{
    public : 
        int size; 
        int arr[100];
    public: 
        Heap()
        {
            size =0;
            arr[0]=-1;
        }
        void insertion(int val)
        {
            size = size+1;
            int index = size;
            arr[index] = val;
            while( index > 1 )
            {
                int parent = index/2;
                if( arr[parent] < arr[index] )
                {
                    swap(arr[parent],arr[index]);
                    index = parent;
                }
                else
                    return;
            }
        }
        void print()
        {
            cout<<"Elements in the heap are : "<<endl;
            for( int idx =1; idx <= size; idx++ )
            {
                cout<<arr[idx]<<" ";
            }
            cout<<endl;
        }
        
};
void display(int arr[], int size)
        {
            cout<<"Elements in the heap are : "<<endl;
            for( int idx =1; idx <= size; idx++ )
            {
                cout<<arr[idx]<<" ";
            }
            cout<<endl;
        }
            /*
                Heapify 
                It's a algorithm for converting a normal set of array into a heap .
                heap can be of two forms 
                1. max heap.
                2. min heap  
            */
        void MaxHeapify(int arr1[], int size ,int idx)
        {
            int largest = idx;
            int leftchildidx = 2*idx;
            int rightchildidx= 2*idx +1;
            if( arr1[largest] < arr1[leftchildidx] && leftchildidx <= size )
            {
                largest = leftchildidx;
            }
            else if( arr1[largest] < arr1[rightchildidx] && rightchildidx <= size )
            {
                largest = rightchildidx;
            }
            if( largest != idx )
            {
                swap(arr1[largest],arr1[idx]);
                MaxHeapify(arr1,size,largest);
            }
        }
int main()
{
    int arr1[6] = {-1, 5, 2, 3, 8, 0};
    // n=5 as we are not including zeroth index
    int n=5;
    display(arr1,n);
    for (int idx = n / 2; idx > 0; idx--)
    {
        MaxHeapify(arr1,n, idx);
    }

    cout << "Elements in the heap are after Heapifying : " << endl;
    for (int idx = 1; idx <= n; idx++)
    {
        cout << arr1[idx] << " ";
    }
    cout << endl;

    return 0;
}
