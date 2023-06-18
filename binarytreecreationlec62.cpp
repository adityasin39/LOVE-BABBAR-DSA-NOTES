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
    this->left=NULL;
    this->right=NULL;
}
};
Node* buildTree(Node* root)
{
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    if(data==-1) return NULL;
    root=new Node(data);
    root->left=buildTree(root->left);
    root->right=buildTree(root->right);
    return root;
}
// level order traversal is also called as breadth first search and is done by using queue;
void levelOrdertraversal(Node* root)
{
   queue<Node*> q;
   q.push(root);
   while(!q.empty())
   {
      cout<<q.front()->data<<" ";
      if(q.front()->left!=NULL)
      q.push(q.front()->left);
      if(q.front()->right!=NULL)
      q.push(q.front()->right);
      q.pop();
   }
}
// here in the above case we printed the tree but it didnt look like a tree
// So, this can be done by using a separator by pushing Null and it gives the feel of level order traversal
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

Node* buildtreewithlevelordertraversal(Node* root)
{
    queue<Node*> q;
    cout<<"Enter the data for root"<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        cout<<"Enter the data for left child of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){
        temp->left=new Node(leftdata);
        q.push(temp->left);
        }
        cout<<"Enter the data for right child of "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){
        temp->right=new Node(rightdata);
        q.push(temp->right);
        }
    }
    return root;

}
int main(){
    Node* root=NULL;
    root=buildTree(root);
    levelOrdertraversal(root);
    cout<<endl;
    levelOrdertraversalwithseparator(root);
    cout<<"The inorder traversal is "<<endl;
    inorder(root);
    cout<<"The preorder traversal is "<<endl;
    preorder(root);
    cout<<"The postorder traversal is "<<endl;
    postorder(root);
     root=buildtreewithlevelordertraversal(root);
   levelOrdertraversalwithseparator(root);
    return 0;
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1