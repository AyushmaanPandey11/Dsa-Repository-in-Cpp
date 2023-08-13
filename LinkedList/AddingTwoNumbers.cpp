#include<iostream>
using namespace std;
class Node
{
    public :
            int data;
            Node* next;
    Node(int d)
    {
        this -> data = d;
        this -> next = NULL;
    }
    ~Node()
    {
        //int value = this -> data;
        // freeing memory
        if( this -> next != NULL )
        {
            this -> next = NULL;
            delete next; 
            
        }
        //cout<< "Memory freed data is "<<value<<endl;
    }
};
void InsertionatHead( Node* &head, int data )
{
    // if there is no node already 
    if( head == NULL )
    {
        Node* temp = new Node(data);
        head = temp;
    }
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}
void insertionattail( Node* &head , Node* &tail , int data)
{
    // if list is empty
    if( head == NULL)
    {
        Node* temp = new Node(data);
        tail= temp;
        head = temp;
    }
    // if list is not empty
    else
    {
        Node* temp = new Node(data);
        tail ->next = temp;
        tail = temp;
    }
}
void display(Node* head)
{
    Node* temp = head;
    cout<<"Elements in the linkedlist are: ";
    while ( temp!= NULL )
    {
        cout<<temp -> data<<" ";
        temp = temp ->next;
    } 
    cout<<endl;
}
Node* reverse( Node* head )
{
    if( head == NULL || head -> next == NULL ) 
        return head;
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while( curr != NULL )
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next; 
    }
    return prev;
} 
Node* add( Node* &first , Node* &second )
{
    int carry  = 0;
    Node* anshead = NULL;
    Node* anstail = NULL;
    // loop goest until first , second reaches the end and carry is not zero
    while( first != NULL || second != NULL || carry != 0 )
    {
        // has the value from first 
        int value1 = 0;
        if( first != NULL )
            value1 = first -> data;
        // has value from second
        int value2 = 0;
        if( second != NULL )
            value2 = second -> data;
        // add all the values for the digit to store in the anshead
        int sum = carry + value1 + value2;
        // digit is inserted into the anshead ll which will display the answer
        int digits = sum % 10;
        insertionattail( anshead,anstail,digits );
        // carry is added for the next digit in the sum variable
        carry = sum/10;
        // forwarding the digits of first and second lists
        if( first != NULL  )
            first = first -> next;
        if ( second != NULL )
            second = second -> next;
    }
    return anshead;
}
Node* AddTwoList( Node* first , Node* second )
{
    // step 1 - reversing both first and second
    first = reverse(first);
    second = reverse(second);
    // add the two lists
    Node* ans = add( first , second );
    // reversing the ans node 
    ans = reverse( ans );
    return ans;
}
int main()
{
    Node* num1 = new Node(5);
    Node* num2 = new Node(4);
    InsertionatHead(num1,2);
    InsertionatHead(num1,5);
    InsertionatHead(num2,3);
    InsertionatHead(num2,3);
    cout<<"The first number: "<<endl;
    display(num1);
    cout<<"The second number: "<<endl;
    display(num2);
    Node* ans = AddTwoList(num1,num2);
    cout<<"Sum of the two  linkedlist is : "<<endl;
    display(ans);
    return 0;
}