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
Node* getMiddle( Node* head )
{
    //if list has 0 or 1 element only
    if( head == NULL || head -> next == NULL )
        return head;
    Node* slow = head;
    Node* fast = head -> next;
    while( fast != NULL && fast -> next != NULL )
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    // when fast reaches end of the list, slow will be at the middle
    return slow;
}
Node* reverse( Node* head )
{
    Node* curr = head;
    Node* next = NULL;
    Node* prev = NULL;
    // for explaination of while loop, do dry run
    while( curr != NULL )
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPalindrome( Node* head )
{
    // if there is only one element which is palindrome
    if( head -> next == NULL )
    {
        return true;
    }
    Node* getMid = getMiddle(head);
    Node* temp = getMid -> next;
    getMid -> next = reverse(temp);
    // traversing and checking each node from head1 and head2 after reversing
    Node* head1 = head;
    Node* head2 = getMid -> next;
    while( head2 != NULL )
    {
        if( head1 -> data != head2 -> data )
        {
            return false;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    // rearranging the reversed elements
    temp = getMid -> next;
    getMid -> next = reverse(temp);
    return true;
} 
int main()
{
    Node* head = new Node(1);
    InsertionatHead(head,2);
    InsertionatHead(head,3);
    InsertionatHead(head,3);
    InsertionatHead(head,2);
    InsertionatHead(head,1);
    display(head);
    Node* getmid = getMiddle(head);
    cout<<"Middle node is: "<<getmid -> data <<endl;
    if( isPalindrome(head) )
    {
        cout<<"Linked list is Palindrome "<<endl;
    }
    else
    {
        cout<<"Linked list is not Palindrome"<<endl;
    }
    //cout<<"The given linked list is palindrome(1) or not(0): "<<isPalindrome(head);
    return 0;
}