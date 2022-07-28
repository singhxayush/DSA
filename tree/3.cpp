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

    inorder(root); cout<<endl;
}