#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    bool isThreaded;
    Node()
    {
        left=nullptr;
        right=nullptr;
        isThreaded= false;
    }
    Node(int val)
    {
        data=val;
        left=nullptr;
        right=nullptr;
        isThreaded= false;
    }
};

Node *create()
{

    int x;
    cout<<"\nEnter the data(-1)for no node:";
    cin>>x;
    if(x== -1)
        return 0;
    Node *newNode= new Node();
    newNode->data=x;
    cout<<"\nEnter the left child of "<<x<<":";
    newNode->left= create();
     cout<<"\nEnter the right child of "<<x<<":";
    newNode->right= create();
    return newNode;

}

Node *createThreaded(Node *root,Node *&prev)
{
    if(root==nullptr)
        return nullptr;
    if(root->left)
        createThreaded(root->left,prev);//processing left subtree
    if(prev !=nullptr && prev->right == nullptr)
    {
        prev->right=root;
        prev->isThreaded=true;
    }

    prev= root;
    if(!root->isThreaded)
        createThreaded(root->right,prev);

    return root;
}

Node *leftMost(Node *root)
{
    while(root!=nullptr && root->left != nullptr)
    {
        root= root->left;
    }
    return root;
}
void inorderTraversal(Node *root)
{
    Node *current= leftMost(root);
    while(current!= nullptr)
    {
        cout<<current->data<<" ";
        if(current->isThreaded)
            current=current->right;
        else
            current=leftMost(current->right);
    }

}
int main()
{
    Node *root= create();
    Node *prev= nullptr;
    root= createThreaded(root,prev);
    inorderTraversal(root);
}
