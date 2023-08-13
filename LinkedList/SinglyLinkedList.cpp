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
        int value = this -> data;
        // freeing memory
        if( this -> next != NULL )
        {
            this -> next = NULL;
            delete next; 
        }
        cout<< "Memory freed data is "<<value<<endl;
    }
};
void InsertionatHead( Node* &head, Node* &tail , int data )
{
    // if there is no node already 
    if( head == NULL )
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}
void InsertionatTail( Node* &head, Node* &tail, int data)
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
    tail = tail -> next;
}
void display(Node* &head)
{
    Node* temp = head;
    while ( temp!= NULL )
    {
        cout<<temp -> data<<" ";
        temp = temp ->next;
    } 
    cout<<endl;
}
void InsertionatPostion( Node* &head, Node* &tail, int postion, int d)
{
    // to insert at head 
    if( postion == 1)
    {
        InsertionatHead(head,tail,d);
        return;
    }
    int cnt = 1;
    Node* temp = head;
    while( cnt < postion -1 )
    {
        temp = temp ->next;
        cnt++;
    }
    // creating the newNode
    Node* NewNode = new Node(d);
    NewNode -> next = temp -> next;
    temp -> next = NewNode; 
}
void DeleteNode( int position , Node* &head)
{
    // deleting starting node
    if( position == 1 )
    {
        Node* temp = head;
        head = head ->next;
        temp ->next = NULL;
        delete temp;
    }
    else
    {
        // delete anywhere middle or last node
        Node* prev = NULL;
        Node* curr = head;
        int cnt=1;
        while( cnt < position )
        {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        // deleting the node , curr is at the postion and prev is one behind it
        prev ->next = curr -> next;
        // freeing address stored and memory
        curr -> next = NULL;
        delete curr;
    }
}
int main ()
{
    Node* node1 = new Node(10);
    cout<< node1 -> data<< endl;
    Node* head = node1;
    Node* tail = node1;
    InsertionatHead(head, tail, 12);
    display(head);
    InsertionatTail(head,tail,8);
    display(head);
    InsertionatPostion(head,tail,4,6);
    display(head);
    DeleteNode(4,head);
    display(head);
    return 0;
}