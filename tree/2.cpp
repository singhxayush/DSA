/////// Tree Traversal ///////

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
    // print_left_view_iterative(root1);

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

    Node root3 = new node(7);

    root3->left = new node(4);
    root3->right = new node(5);
    root3->left->left = new node(3);
    root3->left->right = new node(1);
    root3->right->left = new node(2);
    root3->right->right = new node(6);
    root3->left->right->left = new node(8);
    root3->left->right->left->left = new node(9);//node added for disbalance
    
    // cout<<"Height of tree : "<<height(root3)<<"\n";

    // cout<<"is balanced :"; // naive
    // isbalanced_naive(root3)?cout<<"yes\n":cout<<"no\n";

    // cout<<"is balanced :"; // efficient
    // (isbalanced(root3)!=-1)?cout<<"yes\n":cout<<"no\n";

    // cout<<"max width : "<<max_width(root3);

    //// FLATTENING THE TREE
    // Node head = BTtoDLL_in(root3); printlist(head);

    inorder(root3);
    // Node head = BTtoDLL_pre(root3); printlist(head);
    // preorder(root3);

cout<<"";
}