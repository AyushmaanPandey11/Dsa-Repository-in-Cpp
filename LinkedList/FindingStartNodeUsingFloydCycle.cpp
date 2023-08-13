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
Node* FloydDetectionCycle( Node* head )
{
    if( head == NULL )
        return NULL;
    Node* slow = head;
    Node* fast = head;
    while( slow!= NULL && fast!= NULL )
    {
        fast = fast ->next;
        if( fast!= NULL )
        {
            fast = fast -> next;
        }
        slow = slow ->next;
        if( slow == head )
        {
            return slow;
        }
    }
    return NULL;
}
Node* FindingStartNode( Node* head )
{
    if( head == NULL)
        return NULL;
    Node* intersection = FloydDetectionCycle( head );
    Node* slow = head;
    while( slow!= intersection )
    {
        slow = slow ->next;
        intersection = intersection ->next;
    }
    return slow;
}
int main ()
{
    Node* tail = NULL;
    InsertionNode(tail,0,30);
    display(tail);
    InsertionNode(tail,30,20);
    display(tail);
    Node* second = tail ->next;
    InsertionNode(tail,20,10);
    display(tail);
    InsertionNode(tail,10,5);
    display(tail);
    InsertionNode(tail,5,4);
    display(tail);
    InsertionNode(tail,4,3);
    display(tail);
    InsertionNode(tail,3,2);
    display(tail);
    InsertionNode(tail,2,1);
    display(tail);
    tail = second;
    Node* startNodee = FindingStartNode( tail );
    cout<<"The start Node of the loop in the linked list is "<< startNodee->data<<endl;
    return 0;
}



