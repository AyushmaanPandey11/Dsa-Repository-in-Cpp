#include<iostream>
using namespace std;
class Node
{
    public : int data;
             Node* next ;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    ~Node()
    {
        int val = this ->data;
        if( this -> next != NULL )
        {
            next = NULL;
            delete next;
        }
        cout<<"Memory released of data "<<val<<endl;
    }
};
// here we are using data to find instead of position
void InsertionNode( Node* &tail , int element , int d)
{
    // if the list is empty
    if( tail == NULL )
    {
        Node* NewNode = new Node(d);
        tail = NewNode;
        NewNode -> next = NewNode;
    }  
    else
    {
        // list is not empty .. curr starts from the first node
        Node* curr = tail ;
        while( curr ->data != element )
        {
            curr = curr -> next; 
            // element not found
            if (curr == tail)
            {
                cout << "Element not found in the linked list." << endl;
                return;
            }
        }
        
        // element found 
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr->next = temp;
    }
}
void display( Node* tail )
{
    Node* temp = tail;
    if( tail == NULL )
    {
        cout<<"Empty list"<<endl;
        return ;
    }
    else
    {
    cout<<"Elements present is the linked list are: ";
    do 
    {
        cout<< temp->data <<" ";
        temp = temp ->next;
    }while( temp != NULL && temp != tail );
    }
    cout<<endl;
}
// DELETION OPERATIONS
void deleteNode( Node* &tail , int value )
{
    if( tail == NULL )
    {
        cout<<"List is empty"<<endl;
        return ;
    }
    else
    { // not empty list 
        Node* prev = tail;
        Node* curr = prev -> next;
        while( curr -> data != value )
        {
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr ->next;
        // only node exists
        if( prev == curr )
        {
            tail = NULL;
        }
        // last position
        if( tail == curr )
        {
            tail = prev;
        } 
        curr ->next = NULL;
        delete curr;
    }
}
int main ()
{
    Node* node1 = new Node(30);
    Node* tail = node1;
    display(tail);
    InsertionNode(tail,30,20);
    display(tail);
    InsertionNode(tail,20,10);
    display(tail);
    InsertionNode(tail,10,0);
    display(tail);
    deleteNode(tail,30);
    display(tail);
    return 0;
}