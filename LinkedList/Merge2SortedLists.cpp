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
Node* solve( Node* first, Node* second )
{
    // only one element in the first node, directly linking it to second list
    if( first -> next == NULL )
    {
        first -> next = second;
        return first;
    }
    Node* curr1 = first;
    Node* next1 = curr1 -> next;
    Node* curr2 = second;
    Node* next2 = curr2 -> next;
    while( (next1 != NULL) && (next2 != NULL) )
    {
        if( (curr2 -> data >= curr1 -> data) && ( curr2 -> data <= next1 -> data) )
        {
            curr1 -> next = curr2;
            curr2 -> next = next1;
            // update positioning ptrs in right place
            curr1 = curr2;
            curr2 = next2;  
            next1 = curr1 -> next;
            next2 = curr2 -> next; 
        }
        else
        {
            curr1 = next1;
            next1 = next1 -> next;
            if( next1 -> next == NULL )
            {
                next1 -> next = curr2;
                return first;
            }
        }
    }
    return first;
}
Node* Mergelinkedlist( Node* first, Node* second )
{
    if( first == NULL )
        return second;
    if( second == NULL )
        return first;
    if( first ->data >= second ->data )
    {
        return solve( second , first );
    }
    else if( second ->data >= first ->data )
    {
        return solve( first , second );
    }
    return first;
}
int main ()
{
    Node* node1 = new Node(5);
    Node* node2 = new Node(6);
    cout<<"First Node: "<<endl;
    Node* head1 = node1;
    Node* head2 = node2;
    InsertionatHead(head1,3);
    InsertionatHead(head1,1);
    display(head1);
    cout<<"Second Node: "<<endl;
    InsertionatHead(head2,4);
    InsertionatHead(head2,2);
    display(head2);
    cout<<"After merging the two lists: "<<endl;
    Node* newHead = Mergelinkedlist(head1,head2);
    display(newHead);
    return 0;
}