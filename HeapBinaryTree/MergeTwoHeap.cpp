#include<iostream>

using namespace std;

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
            void heapify( vector<int> hp, int size, int index )
            {
                int largest = index;
                int leftidx = 2*index + 1;
                int rightidx = 2*index + 2;
                // conditions
                // left
                if( index < size && ( hp[largest] < hp[leftidx] ) )
                {
                    largest = leftidx;
                }
                // right
                if( index < size && ( hp[largest] < hp[rightidx] ) )
                {
                    largest = rightidx;
                }
                // swapping to heapify
                if( index != largest )
                {
                    swap( hp[index],hp[largest] );
                    
                    heapify(hp,size,largest);
                }
            }
            vector<int> MergeHeap( vector<int> a, vector<int> b , int sizeofa , int sizeofb )
            {
                vector<int> ans(a+b);
                for( auto idx : a )
                {
                    ans.push_back( a[idx] );
                }
                for( auto idx : b )
                {
                    ans.push_back( b[idx] );
                }
                int size = (a+b)/2;
                for( int idx = size/2; idx >= 0 ; idx-- )
                {
                    heapify( ans,size,1);
                }
                return ans;
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
    return 0;
}