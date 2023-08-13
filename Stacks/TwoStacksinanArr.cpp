#include<iostream>
using namespace std;
class TwoStacks
{
    public : 
            int size;
            int *arr;
            int top1;
            int top2;
    public: 
            TwoStacks(int size)
            {
                this->size = size;
                arr = new int[size];
                top1 = -1;
                top2 = size;
            }
            void push1( int element )
            {
                // condition for space to push values
                if( top1 - top2 > 1 )
                {
                    top1++;
                    arr[top1] = element;    
                }
                else
                {
                    cout<<"No Spaces to push the values"<<endl;
                }
            }
            void push2( int element )
            {
                // condition for second stack
                if( top2 - top1 > 1 )
                {
                    top2--;
                    arr[top2] = element;
                }
                else
                {
                    cout<<"No Spaces to push the values"<<endl;
                }
            }
            int pop1()
            {
                if( top1 >= 0 )
                {
                    int pop = arr[top1];
                    top1--;
                    return pop;
                }
                else
                {
                    return -1;
                }
            }
            int pop2()
            {
                if( top2 < size )
                {
                    int pop = arr[top2];
                    top2++;
                    return pop;
                }
                else
                {
                    return -1;
                }
            }
};