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
int getlength( Node* head )
{
    int cnt=0;
    while( head!= NULL)
    {
        cnt++;
        head = head ->next;
    }
    return cnt;
}
int getmiddleElement( Node* head )
{
    int len = getlength(head);
    int ans = len/2;
    int cnt =0;
    Node* temp = head;
    while( cnt < ans )
    {
        cnt++;
        temp = temp ->next;
    }
    return temp->data;
}
int GetMiddle1( Node* head )
{
    if( head == NULL || head ->next == NULL)
        return head ->data;
    // 2 nodes exists
    if( head ->next ->next == NULL )
        return head ->next ->data;
    Node* slow = head;
    Node* fast = head ->next;
    while( fast != NULL )
    {
        fast = fast ->next ;
        if( fast != NULL )
        {
            fast = fast ->next;
        }
        slow = slow ->next;
    }
    return slow -> data;
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
    //cout<<" middle element is "<<getmiddleElement(head);
    cout<<"Middle element is : "<<GetMiddle1(head);
    
    return 0;
}