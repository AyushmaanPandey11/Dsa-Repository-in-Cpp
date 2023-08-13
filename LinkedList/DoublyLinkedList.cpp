#include<iostream>
using namespace std;
class Node
{
    public : int data;
             Node* next;
             Node* prev;
    Node(int d)
    {
        this ->data = d;
        this ->next = NULL;
        this ->prev = NULL;
    }
    ~Node()
    {
        int val = this -> data ;
        if(next != NULL)
        {
            this -> next = NULL;
            delete next; 
        }
        cout<<"Memory Released of the data is "<<val<<endl;
    }
};
void print( Node* head )
{
    cout<<"Elements in the linked list are: ";
    Node* temp = head;
    while( temp != NULL )
    {
        cout<<temp ->data<<" ";
        temp = temp ->next;
    }
    cout<<endl;
} 
int length( Node* head )
{
    int len = 0;
    Node* temp = head;
    while( temp!= NULL )
    {
        len++;
        temp = temp-> next;
    }
    return len;
} 
// Insertion operations 
void insertionathead( Node* &head, Node* &tail, int data )
{
    // if the list is empty
    if( head == NULL )
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    // not empty
    else
    {
        Node* temp = new Node(data);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
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
        temp -> prev = tail;
        tail = temp;
    }
}
void insertionatposition ( Node* & head, Node* &tail, int position , int data )
{
    // inserting at head 
    if( position == 1)
    {
        insertionathead(head, tail, data);
        return ;
    }
    // traversalling for the count
    int cnt = 1;
    Node* temp = head;
    while ( cnt < position - 1 )
    {
        cnt++;
        temp = temp -> next ;
    }
    // insertion at last
    if( temp -> next == NULL )
    {
        insertionattail(head, tail, data);
        return ;
    }
    // insertion in the middle
    Node * NodetoInsert = new Node(data);
    NodetoInsert -> next = temp -> next;
    temp -> next -> prev = NodetoInsert;
    temp -> next = NodetoInsert;
    NodetoInsert -> prev = temp;
}
void deleteNode( Node* &head, int position)
{
    // if postion is first
    if( position == 1)
    {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        // deleting node anywhere middle or last 
        Node* curr = head;
        Node* prev = NULL;
        int cnt =1;
        while( cnt < position )
        {
            cnt++;
            prev = curr;
            curr = curr -> next;
        }
        curr -> prev = NULL;
        prev -> next = curr -> next;
        //curr->next -> prev = prev;
        curr -> next = NULL;
        delete curr;
    }
}
int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    insertionathead(head,tail,20);
    print(head);
    insertionattail(head,tail,5);
    print(head);
    insertionatposition(head,tail,2,15);
    print(head);
    cout<<"Length of the linked list is "<<length(head)<<endl;
    deleteNode(head,3);
    print(head);
    return 0;
}