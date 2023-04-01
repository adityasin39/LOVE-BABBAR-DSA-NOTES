// TC of push, pop, peek, isEmpty is O(1)
#include<iostream>
using namespace std;
class Stack{
 private:
 int size;
 int top;
 int *arr;
 public:
 Stack(int size)
 {
    this->size=size;
    top=-1;
    arr= new int[size];
 }
 void push(int element)
 {
    if(top<size-1)
    {
        top++;
        arr[top]=element;
    }
    else{
        cout<<"Stack overflow"<<endl;
    }
 }
 void pop()
 {
    if(top>=0)
    {
        top--;
    }
    else
    {
        cout<<"Stack underflow"<<endl;
    }
 }
 int peek()
 {
    if(top>=0)
    {
        return arr[top];
    }
    else{
        cout<<"The stack is empty"<<endl;
        return -1;
    }
 }
 void isEmpty()
 {
    if(top==-1)
    {
        cout<<"Stack is empty"<<endl;
        
    }
    else
    {
       cout<<"Stack is not empty"<<endl;
    }

 }
};
int main(){
    Stack st(5);
    st.push(3);
    st.push(5);
    st.push(2);
    st.push(6);
    st.push(1);
   cout<<st.peek()<<endl;
    st.pop();
    st.isEmpty();
   cout<<st.peek()<<endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout<<st.peek()<<endl;
    st.isEmpty();
    return 0;
}