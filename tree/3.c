// traversal in binary tree

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>

struct node
{
    int data;
    struct node * right;
    struct node * left;
};

struct node * createnode(int data)
{
    struct node * n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data; 
    n->left  = NULL; n->right = NULL; 
    return n;
}
void preorder(struct node * root)
{
    if(root!=NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node * root)
{
    if(root != NULL)
    {
        // printf("%d ", root->data);
        postorder(root->left);
        // printf("%d ", root->data);
        postorder(root->right);
        printf("%d(x) ", root->data);
    }
}
void inorder(struct node * root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
/* 

        4
       / \
      1   6
     / \
    5   2

*/

int main()
{
    // construct the root node using function
    struct node * p = createnode(4);
    struct node * p1 = createnode(1);
    struct node * p2 = createnode(6);
    struct node * p3 = createnode(5);
    struct node * p4 = createnode(2);
    
    // linking the root to the left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // preorder(p);
    // postorder(p);
    inorder(p);
}