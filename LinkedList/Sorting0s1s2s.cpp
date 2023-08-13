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
void Sorting( Node* head )
{
    int zerocnt = 0; 
    int onecnt = 0;
    int twocnt = 0;
    Node* temp = head;
    while( temp!= NULL )
    {
        if( temp ->data == 0 )
        {
            zerocnt++;
        }
        else if( temp -> data == 1 )
        {
            onecnt++;
        }
        else if( temp ->data ==2 )
        {
            twocnt++;
        }
        temp = temp ->next;
    }
    temp = head;
    while( temp != NULL )
    { 
        if( zerocnt != 0 )
        {
            temp ->data = 0;
            zerocnt--;
        }
        else if( onecnt != 0 )
        {
            temp ->data = 1;
            onecnt--;
        }
        else if( twocnt != 0 )
        {
            temp ->data = 2;
            twocnt--;
        }
        temp = temp ->next;
    }
}
// approach two - No data replacement allowed , using pointers 
void insertattailptr( Node* &tail, Node* curr )
{
    //cout <<"\n"<< tail ->data <<"\n";
    tail ->next = curr;
    tail = curr;
}
Node* SortingUsingPointers( Node* &head )
{
    Node* zerohead = new Node(-1);
    Node* zerotail = zerohead;
    Node* onehead = new Node(-1);
    Node* onetail = onehead;
    Node* twohead = new Node(-1);
    Node* twotail = twohead;
    Node* curr = head;
    while( curr != NULL )
    {
        int val = curr->data;
        if( val == 0 )
        {
            //cout<<"Inside 0";
            insertattailptr(zerotail,curr);
        }
        else if( val == 1 )
        {
            //cout<<"Inside 1";
            insertattailptr(onetail,curr);
        }
        else if( val == 2 )
        {
            //cout<<"Inside 2";
            insertattailptr(twotail,curr);
        }
        curr = curr -> next;    
    }
    // merging the three lists
    if( onehead->next != NULL )
    {
        zerotail->next = onehead ->next;
    }
    else
    {
        zerotail ->next = twohead ->next;
    }
    onetail -> next = twohead ->next;
    twotail -> next = NULL;
    head = zerohead -> next;
    // deleting the created linked list
    delete zerohead;
    delete onehead;
    delete twohead;
    return head;
}
int main ()
{
    Node* node1 = new Node(1);
    cout<<"Elements in the linkedlist are: " <<node1 -> data<< endl;
    Node* head = node1;
    Node* tail = node1;
    InsertionatTail(head,tail,0);
    display(head);
    InsertionatTail(head,tail,2);
    display(head);
    InsertionatTail(head,tail,1);
    display(head);
    InsertionatTail(head,tail,2);
    display(head);
    InsertionatTail(head,tail,0);
    display(head);
    //Sorting( head );
    SortingUsingPointers(head);
    cout<<"After Sorting the linked list "<<endl;
    display(head);
    return 0;
}