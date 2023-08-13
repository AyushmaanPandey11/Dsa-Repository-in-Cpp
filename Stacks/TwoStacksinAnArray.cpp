#include<iostream>
using namespace std;
class TwoStacks
{
    public : 
        int *arr;
        int top1;
        int top2;
        int size;
    public: 
        TwoStacks( int s )
        {
            this -> size = s;
            top1 = -1;
            top2 = s;
            arr = new int[s];
        }
        void push1( int element )
        {
            if( top2 - top1 > 1 )
            {
                top1++;
                arr[top1] = element;
            }
            else
            {
                cout<<"Stack Overflow "<<endl;
            }
        }
        void push2( int element )
        {
            if( top2 - top1 > 1 )
            {
                top2--;
                arr[top2] = element;
            }
        }
        void pop1()
        {
            if( top1 >= 0 )
            {
                int ans = arr[top1];
                cout<<"Popped element from left is: "<<ans<<endl;
                top1--;
            }
            else
            {
                cout<<"Stack is empty"<<endl;
            }
        }
        void pop2()
        {
            if( top2 < size )
            {
                int ans = arr[top2];
                cout<<"Popped element from left is: "<<ans<<endl;
                top2++;
            }
            else
            {
                cout<<"Stack is empty"<<endl;
            }
        }
};
void display( TwoStacks st )
{
    cout<<"Elements in the stack are:";
    for( int idx =0; idx < st.size; idx++ )
    {
        cout<<st.arr[idx]<<" ";
    }
    cout<<endl;
}
int main()
{
    TwoStacks st(5);
    st.push1(5);
    st.push1(10);
    st.push1(15);
    st.push2(20);
    st.push2(25);
    display(st);
    return 0;
}