// All operations are O(1)
#include<iostream>
using namespace std;
class node
{
    public:
   int data;
   node* next;
   node(int data)
   {
    this->data=data;
    next=NULL;
   }
};
class Stack
{
    public:
    node* top;
    Stack()
    {
        top=NULL;
    }   
    void push(int element)
    {
        node* temp= new node(element);
        if(!temp) // means heap mein memory allocate nahi ho paya
        {
            cout<<"Stack overflow"<<endl;
            return;
        }
        temp->next=top;
        top=temp;
    }
    void isEmpty()
    {
        if(top==NULL)
        {
          cout<<"The stack is empty from isEmpty"<<endl;
        }
        else
        cout<<"The stack is not empty"<<endl;
    }
    void pop()
    {
        if(top==NULL)
        {
            cout<<"Stack underflow"<<endl;
        }
        else{
            node* temp=top;
            top=top->next;
            delete(temp);
        }
    }
    int peek()
    {
        if(top!=NULL)
        {
            return top->data;
        }
        else{
            cout<<"The stack is empty from peek"<<endl;
            return -1;
        }
    }
    void displayStack()
    {
        if(top==NULL)
        {
            cout<<"Ths stack is empty from display"<<endl;
        }
        else
        {
            node* temp= top;
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
    }

};
int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.displayStack();
    st.push(4);
    st.push(5);
    st.displayStack();
    cout<<st.peek();
    st.isEmpty();
    st.pop();
    st.displayStack();
    cout<<st.peek();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.isEmpty();
    cout<<st.peek();
    st.displayStack();

    return 0;
}