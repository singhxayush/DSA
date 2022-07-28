#include<iostream>
struct node
{
    int key;
    node * left;
    node * right;

    node(int x)
    {
        key = x;
        left = right = NULL;
    }
};

typedef node * Node;


void inorder(Node root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
        
    }
}

void postorder(Node root)
{
    if(root != NULL)
    {
        
    }
}