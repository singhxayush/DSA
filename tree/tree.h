// Creating Node
#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;

// Node definition
struct node
{
    int val;
    node * l;
    node * r;
    node(int x)
    {
        val = x;
        l = r = NULL;
    }
};

typedef node * Node;

// dfs traversals - working on 1st tree(root1)
void preorder(Node root) {

    if(root == NULL) return;
    cout<<root->val<<" ";
    preorder(root->l);
    preorder(root->r);
}

void postorder(Node root) {

    if(root == NULL) return;
    postorder(root->l);
    postorder(root->r);
    cout<<root->val<<" ";
}