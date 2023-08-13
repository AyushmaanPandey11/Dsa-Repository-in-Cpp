#include<iostream>
using namespace std;
class Node
{
    public : 
        int data;
        Node* next;
    Node( int d)
    {
        this ->data = d;
        this ->next = NULL;
    }
};
void Insertionathead( Node* &head, Node* &tail , int d )
{
    if( head == NULL )
    {
        Node* NewNode = new Node(d);
        head = NewNode;
        tail = NewNode;
    }
    Node* temp = new Node(d);
    temp ->next = head;
    head = temp;
}
void display( Node* head )
{
    cout<<"Elements in the linked list are: ";
    Node* temp = head;
    while( temp!= NULL )
    {
        cout<<temp ->data<<" ";
        temp = temp ->next;
    }
    cout<<endl;
}
Node* KReverse( Node* head, int k )
{
    // if the list is empty
    if( head == NULL )
    {
        return NULL;
    }
    // reversing first K nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    int cnt = 0;
    while( curr!= NULL && cnt < k ) // as we can't reverse a NULL address element
    {
        forward = curr ->next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }
    // recursive calling
    if( forward != NULL )
    {
        head -> next = KReverse( forward , k );
    }
    return prev ;  // prev here is the head of new list 
 }

int main()
{
    Node* node1 = new Node(50);
    Node* head = node1;
    Node* tail = node1;
    Node* prev = NULL;
    display(head);
    Insertionathead(head,tail,40);
    display(head);
    Insertionathead(head,tail,30);
    display(head);
    Insertionathead(head,tail,20);
    display(head);
    Insertionathead(head,tail,10);
    display(head);
    Insertionathead(head,tail,0);
    display(head);
    Node* newHead = KReverse(head,2);
    cout<<" The reverse linked list in K groups: ";
    display( newHead );
    return 0;
}