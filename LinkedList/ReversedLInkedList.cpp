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
            delete next; 
            this -> next = NULL;
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
Node* ReverseLinkedlist( Node* &head )
{
    // case of empty list or single node list 
    if( head == NULL || head ->next == NULL )
    {
        return head;
    }
    // it will return head address
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    while ( curr != NULL )
    {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
void display( Node* head )
{
    cout<<"ELements in the linked list are: ";
    Node* temp = head;
    while( temp != NULL )
    {
        cout<< temp ->data<<" ";
        temp = temp ->next;
    }
    cout<<endl;
}
void ReverseRecursion( Node* &head , Node* curr, Node* prev )
{
    // base case
    if( curr == NULL )
    {
        head = prev;
        return ;
    }
    Node* forward = curr ->next;
    // recursive calling
    ReverseRecursion(head, forward , curr);
    curr ->next = prev;
}
Node* Reverse1( Node* head )
{
    // base case
    if( head == NULL || head -> next == NULL )
    {
        return head;
    }
    Node* newHead = Reverse1( head -> next );
    head ->next ->next = head;
    head ->next = NULL;
    return newHead;
}
int main ()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    Node* prev = NULL;
    display(head);
    InsertionatHead(head,tail,20);
    display(head);
    InsertionatHead(head,tail,30);
    display(head);
    InsertionatHead(head,tail,40);
    display(head);
    InsertionatHead(head,tail,50);
    display(head);
    InsertionatHead(head,tail,60);
    display(head);
    //cout<<"Reversing the linked list while loops "<<endl;
    //display(ReverseLinkedlist(head));
    cout<<"recursion technique reversing "<<endl;
    //ReverseRecursion(head,head,prev);
    display(Reverse1(head));
    return 0;
}