// Creating Node
#include<iostream>
#include<queue>
#include<stack>
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

    while(!q.empty()){

        int n = q.size();
        for(int i=0; i<n; i++){
            Node cur = q.front();
            q.pop();
            if(cur->l != NULL) q.push(cur->l);
            if(cur->r != NULL) q.push(cur->r);
            cout<<cur->val<<" ";
        }
        cout<<"\n";
    }
}

void i_preorder(Node root) {

    if(!root) return;

    stack<Node> st;

    st.push(root);

    while(!st.empty()) {
        int n = st.size();
        for(int i=0; i<n; i++) {
            Node cur = st.top();
            st.pop();
            if(cur->r != NULL) st.push(cur->r);
            if(cur->l != NULL) st.push(cur->l);
            cout<<cur->val<<" ";
        }
    }
}

