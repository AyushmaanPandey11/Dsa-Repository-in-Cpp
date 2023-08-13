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
        // freeing memory
        if( this -> next != NULL )
        {
            next = NULL;
            delete next; 
        }
    }
};
void InsertionatTail( Node* &head, Node* &tail , int data )
{
    // if there is no node already 
    if( head == NULL )
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}
void display(Node* head)
{
    Node* temp = head;
    while ( temp!= NULL )
    {
        cout<<temp -> data<<" ";
        temp = temp ->next;
    } 
    cout<<endl;
}
Node* RemoveDuplication( Node* head )
{
    // if the list is empty
    if( head == NULL )
    {
        return NULL;
    }
    Node* curr = head;
    
    while( (curr != NULL) && (curr->next != NULL) )
    {
        Node* forward = curr->next;
        // duplicate element
        if( (curr -> data) == ( forward-> data) )
        {
            // removing the duplicate node from the list 
            Node* Nodetodelete = curr->next;
            curr->next = curr->next->next;
            delete Nodetodelete;
            curr = curr->next;
        }
        else
        {
            // no duplicate element
            curr = curr->next;
        }  
    }
    return head;
}
int main ()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    display(head);
    InsertionatTail(head, tail, 12);
    display(head);
    InsertionatTail(head, tail, 12);
    display(head);
    InsertionatTail(head, tail, 14);
    display(head);
    InsertionatTail(head, tail, 16);
    display(head);
    cout<<"The list after deleting duplicate element ";
    Node* uniquelist = RemoveDuplication(head);
    display(uniquelist);
    return 0;
}