#include <iostream>
using namespace std;
struct node
{
  node *left;
  int data;
  node *right;
};
class BST
{
  public:
  node *newNode(int val)
  {
    node *ptr=new node;
    ptr->data=val;
    ptr->left =NULL;
    ptr->right = NULL;
    return ptr;
  }
  node* insert(node* node, int val)
  {
    if(node == NULL)
      return newNode(val);
    if(val< node->data)
      node->left = insert(node->left,val);
    else
      node->right = insert(node->right,val);
    return node;
  }
  node *inorderSucc(node* n)
  {
    node *ptr= n;
    while (ptr->left != NULL)
      ptr=ptr->left;
    return ptr;
  }
  node* deleteNode(node* root, int key)
  {
    if(root==NULL)
      return root;
    if(key<root->data)
      root->left = deleteNode(root->left, key);
    else if(key > root->data)
      root->right = deleteNode(root->right, key);
    else
    {
      if(root->left == NULL)
      {
        node *temp = root->right;
        delete root;
        return temp;
      }
      else if(root->right == NULL)
      {
        node *temp = root->left;
        delete root;
        return temp;
      }
      node* succ =inorderSucc(root->right);
      root->data = succ->data;
      root->right = deleteNode(root->right,succ->data);
    }
    return root;
  }
  void preorder(node *root)
  {
    if (root != NULL)
    {
      cout<<root->data<<" ";
      preorder(root->left);
      preorder(root->right);
    }
  }
  void inorder(node *root)
  {
    if (root != NULL)
    {
      inorder(root->left);
      cout<<root->data<<" ";
      inorder(root->right);
    }
  }
  void postorder(node *root)
  {
    if (root != NULL)
    {
      postorder(root->left);
      postorder(root->right);
      cout<<root->data<<" ";
    }
  }
};
int main()
{
  BST bst;
  node *root=NULL;
  int choice,val;
  do{
    cout<<"\nEnter your choice:\n1.Insert a node\t2.Delete a node\t3.Pre-order traversal\t4.Inorder traversal\t5.Postorder traversal\t 6.Exit\n";
    cin>>choice;
    switch(choice)
    {
      case 1: cout<<"\nEnter node to insert: ";
              cin>>val;
              root=bst.insert(root,val);
              break;
      case 2: cout<<"\nEnter node to delete: ";
              cin>>val;
              root=bst.deleteNode(root,val);
              break;
      case 3: cout<<"preorder traversal: ";
              bst.preorder(root);
              cout<<endl;
              break;
      case 4: cout<<"inorder traversal: ";
              bst.inorder(root);
              cout<<endl;
              break;
      case 5: cout<<"postorder traversal: ";
              bst.postorder(root);
              cout<<endl;
              break;
    }
  }while(choice!=6);
}
