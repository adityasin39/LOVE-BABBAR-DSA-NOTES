#include<iostream>
#include<queue>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
// the time complexity of insertion is logn as this is similar to binary search because the height of the tree would be logn so at most logn comparisions will be made in average case and in worst case O(n) will be the complexity
Node* insertIntobst(Node* root, int data)
{
    if(root==NULL)
    {
        root=new Node(data);
        return root;
    }
    if(data<root->data)
    {
        root->left=insertIntobst(root->left,data);
    }
    if(data>root->data)
    {
        root->right=insertIntobst(root->right,data);
    }
    return root;
}
void takeInput(Node*& root) // we will be getting a stream of data
{
    // by reference aaega as we are not returning root here
    cout<<"Enter the data to be inserted in bst"<<endl;
    int data;
    while(data!=-1)
    {
      cin>>data;
      if(data!=-1)
       root=insertIntobst(root,data);
    }
}
Node* minvalue(Node* root)// the leftmost value is the minimum value
{
    Node* temp=root;
    while(temp->left)
    {
        temp=temp->left;
    }
    return temp;
}
Node* maxvalue(Node* root)// the rightmost value is the maximum value
{
    Node* temp=root;
    while(temp->right)
    {
        temp=temp->right;
    }
    return temp;
}
// deletion is done recursively
// first we find out the node to be deleted by using bst property
Node* deletefromBST(Node* root, int key)
{
    if(root==NULL) return NULL;
    if(root->data==key)
    {
       if(root->left==NULL && root->right==NULL) // for leaf nodes
       {
           delete root;
           return NULL;
       }
       else if(root->left==NULL && root->right!=NULL)// for 1 child and that too right subtree
       {
         Node* temp=root;
         temp=root->right;
         delete root;
         return temp;
       }
       else if(root->right==NULL && root->left!=NULL)// for 1 child and that too left subtree
       {
          Node* temp=root;
         temp=root->left;
         delete root;
         return temp;
       }
       else{// for 2 children
       // in this case we have two options: either find out the inorder predecessor or successor and then copy the value into the node to be deleted and then delete the inorder predecessor or successor recursively
          Node* temp=root->left;
          while(temp->right)
          {
            temp=temp->right;
          }
          root->data=temp->data;
         // Node* temp1=temp;
          root->left=deletefromBST(root->left,temp->data);
          return root;
           
       }
    }
    else if(root->data>key) root->left= deletefromBST(root->left,key);
    else root->right=deletefromBST(root->right,key);
    return root;
}
void levelOrdertraversalwithseparator(Node* root)
{
   queue<Node*> q;
   q.push(root);
   q.push(NULL);
   while(!q.empty())
   {
    Node* temp=q.front();
    q.pop();
    if(temp!=NULL){
      cout<<temp->data<<" ";
      if(temp->left!=NULL)
      q.push(temp->left);
      if(temp->right!=NULL)
      q.push(temp->right);
    }
    else 
    {
        cout<<endl;
        if(!q.empty()) q.push(NULL);
    }
   }
}
void inorder(Node* root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node* root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root)
{
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
  Node* root=NULL;
  takeInput(root);  
  cout<<"This is the level order traversal"<<endl;
  levelOrdertraversalwithseparator(root);
  cout<<"This is the inorder traversal"<<endl;
  inorder(root);
  cout<<endl;
  cout<<"This is the preorder traversal"<<endl;
  preorder(root);
  cout<<endl;
  cout<<"This is the postorder traversal"<<endl;
  postorder(root);
  cout<<endl;
  cout<<"The min value is "<<minvalue(root)->data<<endl;
  cout<<"The max value is "<<maxvalue(root)->data<<endl;
  Node* root1=deletefromBST(root,12);
  cout<<"This is the level order traversal"<<endl;
  levelOrdertraversalwithseparator(root1);
  cout<<"This is the inorder traversal"<<endl;
  inorder(root1);
  cout<<endl;
  cout<<"This is the preorder traversal"<<endl;
  preorder(root1);
  cout<<endl;
  cout<<"This is the postorder traversal"<<endl;
  postorder(root1);
  cout<<endl;
  cout<<"The min value is "<<minvalue(root1)->data<<endl;
  cout<<"The max value is "<<maxvalue(root1)->data<<endl;
    return 0;
}