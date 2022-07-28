// linked representation of binary tree

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
    struct node * n; //creating a node pointer 
    n = (struct node *)malloc(sizeof(struct node));// allocating memory in the heap
    n->data = data; 
    n->left  = NULL; n->right = NULL; //setting the left and children to null
    return n; // finally returning the created node!
}

int main()
{
/* 
    struct node * p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = 1;
    p->left  = NULL;
    p->right = NULL;

    struct node * p1;
    p1 = (struct node *)malloc(sizeof(struct node));
    p1->data = 2;
    p1->left = NULL;
    p1->right = NULL;

    struct node * p2;
    p2 = (struct node *)malloc(sizeof(struct node));
    p2->data = 3;
    p2->right = NULL;
    p2->left = NULL;

    // linking the root to the left and right children
    p->left = p1;
    p->right = p2;
*/

    // construct the root node using function
    struct node * p = createnode(4);
    struct node * p1 = createnode(5);
    struct node * p2 = createnode(5);
    
    // linking the root to the left and right children
    p->left = p1;
    p->right = p2;
}