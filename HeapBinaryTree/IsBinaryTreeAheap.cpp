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
            /*
                    IS BINARY TREE A HEAP 
                    CONDITIONS TO SATISFY
                    1. IS IT A CBT?
                    2. DOES IT FOLLOW MAX ORDER PROPERTY
            */
           int countnodes( Node* root )
           {
                if( root == NULL )
                    return 0;
                int ans = 1 + countnodes(root->left) + countnodes(root->right);
                return ans;
           }
           bool isCBT( Node* root , int index , int count )
           {
                if( root == NULL )
                {
                    return true;
                }
                // index for beyong the count meaing child nodes does not exists
                if( index >= count )
                {
                    return false;
                }
                // recursive calling
                bool left = isCBT(root,2*index+1,count); // left child node
                bool right = isCBT(root,2*index+2,count); // right child node          
                
                return left&&right;
           }
           bool isMaxHeap( Node* root )
           {
                // leaf node condition
                if( root -> left == NULL && root -> right == NULL )
                    return true;
                // right child node is empty
                if( root -> right == NULL )
                {
                    return ( root->val > root->left->val );
                }
                else // both child nodes exists
                {
                    // recursive calling 
                    bool left = isMaxHeap(root->left);
                    bool right = isMaxHeap(root->right);
                    
                    return ( (left&&right) && (root->val > root->right->val) && (root->val > root->left->val) ); 
                }
           }
           bool isHeap( Node* root )
           {
                int index =0; 
                int count = countnodes(root);
                return ( isMaxHeap && isCBT );
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
