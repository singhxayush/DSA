/////// Tree Traversal ///////

/*

    Categories
        - Breadth first(or level order)
        - Depth first
            - inorder   - left root right
            - preorder  - root left right
            - postorder - left right root 

*/
/*
    tree we are working on

               1
             /   \
            2     3
           / \     \
          4   5     6
           \       / \
            9     7   8
           /
          10

*/
#include<iostream>
using namespace std;
#include"tree.h"

int main()
{
    Node root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);

    root->right->right->left = new node(7);
    root->right->right->right = new node(8);
    root->left->left->right = new node(9);

    root->left->left->right->left = new node(10);
    

    // preorder(root); cout<<endl;
    // inorder(root); cout<<endl;
    // postorder(root); cout<<endl;

    // cout<<"Height of tree : "<<height(root)<<"\n";

    // int d;
    // cout<<"Enter distance :"; cin>>d;
    // cout<<"Nodes at distance "<<d<<" is "; node_at_distance_(d-1, root); cout<<endl;

    // levelorder_naive(root); cout<<endl;
    levelorder(root); cout<<endl;
    levelorder_linebyline_1(root); cout<<endl;
}