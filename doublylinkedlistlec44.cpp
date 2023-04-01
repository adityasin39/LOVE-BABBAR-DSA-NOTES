#include<iostream>
using namespace std;
// CREATING A NODE
// IF THE DATA PART AND ADDRESS ARE NOT INITIALIZED THEN BOTH CONTAIN 0 BY DEFAULT
class Node
{
 public:
 int data;
 Node *next; // POINTER OF NODE TYPE
 Node* prev;
 Node(int data)
 {
    this->data=data;
    next=NULL;
    prev=NULL;
 }
 ~Node()
 {
    int value=data;
    cout<<"memory is freed for node with data "<<value<<endl;
 }
};
void insertAtHead(Node *&head,Node* &tail, int d)
{
    if(head==NULL)  // if initially linked list is empty
    {
    Node * temp= new Node(d);
    head=temp;
    tail=temp;
    }
    else{
    Node * temp= new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
    
}
void insertAtTail(Node *&tail,Node *&head, int d)
{
    if(tail==NULL) // if the linked list is initially empty
    {
    Node *temp=new Node(d);
    tail=temp;
    head=temp;
    }
    else{
    Node *temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    }
}
void insertAtMiddle(Node *&head,Node *&tail, int d, int pos) // this handles head and tail insertions too so this is a generalized one
{
    // this code handles empty linked list too even if you insert at head or tail
  Node *temp=new Node(d);
  Node *p=head;
  if(pos==1)
    {
        if(head==NULL)
        {
  Node *temp=new Node(d);
  head=temp;
  tail=temp;
        }
        else{
     temp->next=head;
     head->prev=temp;
     head=temp;
        }   
    }
    else{
  while(pos-2)
  {
     p=p->next;
     pos--;
  }
  if(p->next==NULL) insertAtTail(tail,head,d);
  else{
  temp->next=p->next;
  p->next->prev=temp;
  p->next=temp;
  temp->prev=p;
    }
    }
}
void deleteNode(Node *&head,Node *&tail, int pos)
{
    if(pos==1)
    {
        Node *curr=head;
        head=curr->next;
        curr->next->prev=NULL;
        curr->next=NULL;
        delete(curr);
    }
    else{

    Node* curr=head;
    Node *pre=curr;
    while(pos-1)
    {
        pre=curr;
        curr=curr->next;
        pos--;

    }
    if(curr->next==NULL)
    {
        cout<<"run toh ho raha hai"<<endl;
         pre->next=NULL;
         curr->prev=NULL;
         tail=pre;
         delete(curr);
    }
    else{
    pre->next=curr->next;
    curr->next->prev=pre;
    curr->next=NULL;
    curr->prev=NULL;
    delete(curr);
    }
    }
}
void getLength(Node *&head)
{
    Node *temp=head;
    int len=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        len++;
    }
  cout<<len<<endl;
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
    // Node *tail=NULL;
    insertAtHead(head,tail,6);
    print(head);
    insertAtHead(head,tail,7);
    print(head);
    insertAtTail(tail,head,8);
    print(head);
    insertAtTail(tail,head,9);
    print(head);
    insertAtMiddle(head,tail,2,3);
    print(head);
   insertAtMiddle(head,tail,15,1);
    print(head);

//   insertAtMiddle(head,15,6);
//     print(head);
    insertAtMiddle(head,tail,16,2);
    print(head);
//    insertAtMiddle(head,tail,20,2);
//    print(head);
   getLength(head);
   deleteNode(head,tail,3);
   getLength(head);
   print(head);
    
    return 0;
}