#include<iostream>
using namespace std;
class Stack
{
    public: 
        int data;
        Stack* next;
        Stack* prev;
        Stack* top;
    public:
        Stack( int data )
        {
            this -> data = data;
            next = NULL; 
            prev = NULL;
            top = this;
        }
        ~Stack()
        {
            this -> next = NULL;
            this -> prev = NULL;
            delete next;
            delete prev;
        }
        void push( int element )
        {   
            Stack* NewNode = new Stack(element);
            // if the top is a nullptr 
            if( top == NULL )
            {
                top = NewNode;
            }
            // if there is an element
            top -> next = NewNode;
            NewNode -> prev = top;
            top = NewNode;
        }
        void Isempty( Stack* top )
        {
            if( top == NULL )
            {
              cout<<"stack is empty";  
            }
            else
            {
                cout<<"Stack is not empty ";
            }
            cout<<endl;
        }
        void pop()
        {
            if( top == NULL )
            {
                cout<<"Stack underflow"<<endl;
            }
            int value = top -> data;
            Stack* NodeToDel = top;
            top -> prev -> next = NULL;
            top = NodeToDel -> prev;
            cout<<"The delete element is: "<<value<<endl;
            delete NodeToDel;
        }
        void peek( Stack* top )
        {
            if( top == NULL )
            {
                cout<<"There is no element in the stack "<<endl;
            }
            else
            {
                cout<<"Peek element is: "<<top -> data<<endl;
            }   
        }
        void display( Stack* top )
        {
            Stack* temp = top;
            cout<<"Elements in the stack are: ";
            while ( temp != NULL )
            {
                cout<<temp -> data<<" ";
                temp = temp -> prev;
            }
            cout<<endl;
        }
};

int main()
{
    Stack* node1 = new Stack(5);
    Stack* head = node1;
    node1->push(10);
    node1->push(15);
    node1->push(20);
    node1->display( node1 -> top );
    node1 -> Isempty(node1 -> top);
    node1 -> pop();
    node1->display( node1 -> top );
    node1->peek(node1 -> top);
    return 0;
}