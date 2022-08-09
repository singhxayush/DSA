/////// Tree Traversal ///////
/*
    Categories
        - Breadth first(or level order)
        - Depth first
            - inorder   - left root1 right
            - preorder  - root1 left right
            - postorder - left right root1 


    1st tree we are working on (root1 1) | Balaced Tree |

               1
             /   \
            2     3
           / \     \
          4   5     6
           \       / \
            9     7   8
           /
          10


    2nd tree we are working on (root 2) | Satisfies Children sum property |

               5
             /   \
            2     3
           / \   / \
          1   1 2   1
         /
        1

    3rd tree we are working on (root 2) | Height Balanced Tree |

               7
             /   \
            4     5
           / \   / 
          3   1 2   
          
*/
#include<iostream>
using namespace std;
#include"tree.h"

int main()
{
    //// TREE 1 with root 1 ////

    Node root1 = new node(1);

    root1->left = new node(2);
    root1->right = new node(3);

    root1->left->left = new node(4);
    root1->left->right = new node(5);
    root1->right->right = new node(6);

    root1->right->right->left = new node(7);
    root1->right->right->right = new node(8);
    root1->left->left->right = new node(9);

    root1->left->left->right->left = new node(10);
    

    // preorder(root1); cout<<endl;
    // inorder(root1); cout<<endl;
    // postorder(root1); cout<<endl;

    // cout<<"Height of tree : "<<height(root1)<<"\n";

    // int d;
    // cout<<"Enter distance :"; cin>>d;
    // cout<<"Nodes at distance "<<d<<" is "; node_at_distance_(d-1, root1); cout<<endl;

    // levelorder_naive(root1); cout<<endl;
    // levelorder(root1); cout<<endl;
    // levelorder_linebyline_1(root1); cout<<endl;
    // levelorder_linebyline_2(root1); cout<<endl;

    // cout<<"size :"<<getsize(root1)<<"\n";
    // cout<<"max : "<<getmax(root1); cout<<endl;

    // print_left_view_recursive(root1);
    print_left_view_iterative(root1);

///////////////////////////////////////////////////////////////////////////////////////////////////////////

    //// TRREE 2 with root 2 ////

    Node root2 = new node(5);

    root2->left = new node(2);
    root2->right = new node(3);

    root2->left->left = new node(1);
    root2->left->right = new node(1);
    root2->right->left = new node(2);
    root2->right->right = new node(1);

    root2->left->left->left = new node(1);

    // if(isCsum(root2)) cout<<"YES\n";
    // else cout<<"NO\n";

//////////////////////////////////////////////////////////////////////////////////////////////////////////

    //// TRREE 3 with root 3 ////

    Node root3 = new node(5);

    root3->left = new node(2);
    root3->right = new node(3);

    root3->left->left = new node(1);
    root3->left->right = new node(1);
    root3->right->left = new node(2);
    root3->right->right = new node(1);
}