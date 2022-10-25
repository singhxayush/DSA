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

void inorder(Node root) {

    if(root == NULL) return;
    inorder(root->l);
    cout<<root->val<<" ";
    inorder(root->r);
}

void postorder(Node root) {

    if(root == NULL) return;
    postorder(root->l);
    postorder(root->r);
    cout<<root->val<<" ";
}

void level_order(Node root) {
    
    queue<Node> q;
    if(root == NULL) return;

    q.push(root);

    if(!q.empty()){
        int n = q.size();
        for(int i=0; i<n; i++){
            Node temp = q.front();
            cout<<temp->val<<" ";
            q.pop();
            if(!temp->l) q.push(temp->l);
            if(!temp->r) q.push(temp->r);
        }
        cout<<"\n";
    }
}