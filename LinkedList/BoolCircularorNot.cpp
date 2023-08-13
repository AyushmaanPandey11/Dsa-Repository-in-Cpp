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
            delete next;
            next = NULL;
        }
        cout<<"Memory released of data"<<val<<endl;
    }
};
// here we are using data to find instead of position
void InsertionNode( Node* &tail , int element , int d )
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
        Node* curr = tail  ;
        while( curr ->data != element )
        {
            curr = curr -> next; 
        }
        // element not found
        if (curr == tail && curr->data != element )
        {
            cout << "Element not found in the linked list." << endl;
            return;
        }
        // element found 
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr->next = temp;
    }
}
void display( Node* &tail )
{
    Node* temp = tail ;
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
        }   while( temp != tail && temp!= NULL) ;
    }
    cout<<endl;
}
bool IsCircularOrNot( Node* head )
{
    // if the list is empty 
    if( head == NULL )
    {    
        return true;
    }
    Node* temp = head ->next;
    while( temp != NULL && temp != head )
    {
        temp = temp -> next;
    }
    if( temp == head )
    {
        return true;
    }
    return false;    
}

int main ()
{
    Node* tail = NULL;
    InsertionNode(tail,0,30);
    display(tail);
    InsertionNode(tail,30,20);
    display(tail);
    InsertionNode(tail,20,10);
    display(tail);
    cout<<"Is the list cirular(1) or not (0): "<<IsCircularOrNot(tail); 
    return 0;
}