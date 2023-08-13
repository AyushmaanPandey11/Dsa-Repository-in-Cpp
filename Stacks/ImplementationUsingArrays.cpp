#include<iostream>
using namespace std;
class Stack
{
    public: 
        int *arr;
        int top;
        int size;
    public : 
        Stack( int size )
        {
            this -> size = size;
            arr = new int[size];
            top = -1;
        }
        void push( int element )
        {
            // base case
            if( size - top > 1 )
            {
                top++;
                arr[top] = element;
            }
            else
            {
                cout<<"Stack Overflow"<<endl;
            }
        }
        void pop()
        {
            // condition before popping 
            if( top >= 0 )
            {
                int ans = arr[top];
                cout<<"Popped element is: "<<ans<<endl;
                top--;
            }
            else
            {
                cout<<"Stack Underflow "<<endl;
            }
        }
        int peek()
        {
            if( top >= 0 && top < size )
            {
                return arr[top];
            }
            else
            {
                cout<<"Stack is Empty"<<endl;
            }
            return -1;
        }
        bool isempty()
        {
            if( top == -1 )
            {
                return false;
            }
            else
            {
                return true;
            }
        }
};
void display( Stack st )
{
    cout<<"Elements in the stack are: "<<endl;
    for( int idx =0; idx <= st.top ; idx++ )
    {
        cout<<st.arr[idx]<<" ";
    }
    cout<<endl;
}
int main()
{
    Stack st(5);
    st.push(5);
    st.push(10);
    st.push(20);
    st.push(25);
    st.push(30);
    display(st);
    st.pop();
    display(st);
    int peak = st.peek();
    cout<<"Peek elements is:"<<peak;
    return 0;
}