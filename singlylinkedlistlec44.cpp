// a singly linked list allows traversal of data in only one way
#include<iostream>
using namespace std;
// CREATING A NODE
// IF THE DATA PART AND ADDRESS ARE NOT INITIALIZED THEN BOTH CONTAIN 0 BY DEFAULT
class Node
{
 public:
 int data;
 Node *next; // POINTER OF NODE TYPE
 Node(int data)
 {
    this->data=data;
    next=NULL;
 }
 ~Node()
 {
    int value=data;
    cout<<"memory is freed for node with data "<<value<<endl;
 }
};
void insertAtHead(Node *&head, int d)
{
    if(head==NULL)  // if initially linked list is empty
    {
    Node * temp= new Node(d);
    head=temp;
    }
    else{
    Node * temp= new Node(d);
    temp->next=head;
    head=temp;
    }
    
}
void insertAtTail(Node *&tail, Node *&head, int d)
{
    if(tail==NULL && head==NULL) // if the linked list is initially empty
    {
    Node *temp=new Node(d);
    tail=temp;
    }
    else if(tail==NULL)  // if the linked list was initilaly empty but after some insertions at head, the tail is still NULL
    {
        Node* p=head;
        while(p->next!=NULL)
        {
         p=p->next;
        }
        tail=p;
    }
    Node *temp=new Node(d);
    tail->next=temp;
    tail=temp;
}
void insertAtMiddle(Node *&head, int d, int pos) // this handles head and tail insertions too so this is a generalized one
{
    // this code handles empty linked list too even if you insert at head or tail
  Node *temp=new Node(d);
  Node *p=head;
  if(pos==1)
    {
     temp->next=head;
     head=temp;   
    }
    else{
  while(pos-2)
  {
     p=p->next;
     pos--;
  }
  temp->next=p->next;
  p->next=temp;
    }
}
void deleteNode(Node *&head,Node *&tail, int pos)
{
    if(pos==1)
    {
        Node *curr=head;
        head=curr->next;
        curr->next=NULL;
        delete(curr);
    }
    else{

    Node* curr=head;
    Node *prev=curr;
    while(pos-1)
    {
        prev=curr;
        curr=curr->next;
        pos--;

    }
    if(curr==tail) tail=prev;
    prev->next=curr->next;
    curr->next=NULL;
    delete(curr);
    }
}

void print(Node *head)
{
    Node * temp=head;
    while(temp!=NULL) // temp and temp->next are different
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
      cout<<endl;
}
int main(){
    // insertion wale case mein do cases liye hai case 1: when the linked list is empty
    // case 2: when the linked list initially has 1 element
    Node * node1= new Node(5); // OBJECT IS CREATED DYNAMICALLY TO ALLOCATE MEMORY IN HEAP AND VALUE IS PASSED TO THE CONSTRUCTOR
    // cout<<node1->data<<endl; // AS NODE1 IS A POINTER SO WE USE -> // PRINTS 5
    // cout<<node1->next<<endl;// PRINTS 0 AS NEXT IS NULL HERE

   Node * head=node1;
   Node * tail=node1;
    // Node *head=NULL;
    //Node *tail=NULL;
    insertAtHead(head,6);
    print(head);
    insertAtHead(head,7);
    print(head);
    insertAtTail(tail,head,8);
    print(head);
    insertAtTail(tail,head,9);
    print(head);
    insertAtMiddle(head,2,3);
    print(head);
   //insertAtMiddle(head,15,7);
//   insertAtMiddle(head,15,6);
//     print(head);
    insertAtMiddle(head,16,1);
    print(head);
   insertAtMiddle(head,20,2);
   print(head);
   deleteNode(head,tail,8);
   print(head);
   cout<<"head "<<head->data<<endl;
   cout<<"tail "<<tail->data<<endl;
    
    return 0;
}