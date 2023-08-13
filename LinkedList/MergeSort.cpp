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
Node* getMiddle( Node* head )
{
    if( head == NULL )
        return head;
    Node* slow = head;
    Node* fast = head -> next;
    while( fast != NULL && fast -> next != NULL )
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}
Node* Merge(Node* left, Node* right)
{
    // base case
    if( left == NULL )
        return right;
    if( right == NULL )
        return left;
    Node* ans = new Node(-1);
    Node* temp = ans;
    // loop for condition checking
    while( left != NULL && right != NULL )
    {
        if( (left -> data) < (right -> data) )
        {
            temp -> next = left;
            temp = temp -> next;
            left = left -> next;
        }
        else
        {
            temp -> next = right;
            temp = temp -> next;
            right = right -> next;
        }
    }
    while( left != NULL )
    {
        temp -> next = left;
        temp = temp -> next;
        left = left -> next; 
    }
    while( right != NULL )
    {
        temp -> next = right;
        temp = temp -> next;
        right = right -> next;
    }
    ans = ans -> next;
    return ans;
}
Node* MergeSorting( Node* head )
{
    // if the list has zero or one element .......  BASE CASE   
    if( head == NULL || head -> next == NULL )
        return head;
    Node* mid = getMiddle(head);
    Node* left = head;
    Node* right = mid -> next;
    mid -> next = NULL;
    // recursive calling 
    left = MergeSorting(left);
    right = MergeSorting(right);
    // merging the two linked list 
    Node* result = Merge(left,right);
    return result;
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
int main()
{
    Node* num1 = new Node(5);
    InsertionatHead(num1,2);
    InsertionatHead(num1,1);
    InsertionatHead(num1,3);
    InsertionatHead(num1,8);
    display(num1);
    Node* mid = getMiddle(num1);
    cout<<"Middle element is: "<<mid -> data<<endl;
    cout<<"After Sorting through MergeSort  "<<endl;
    display(MergeSorting(num1));
    return 0;
}