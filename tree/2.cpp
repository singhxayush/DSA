/////// Tree Traversal ///////

#include"tree.h"

int main()
{
    //// TREE 1 with root 1 ////

    Node root1 = new node(1);
    root1->l = new node(2);
    root1->r = new node(3);
    root1->l->l = new node(4);
    root1->l->r = new node(5);
    root1->r->r = new node(6);
    root1->r->r->l = new node(7);
    root1->r->r->r = new node(8);
    root1->l->l->r = new node(9);
    root1->l->l->r->l = new node(10);
    
    // preorder(root1);
    postorder(root1);

///////////////////////////////////////////////////////////////////////////////////////////////////////////

    //// TRREE 2 with root 2 ////

    Node root2 = new node(5);
    root2->l = new node(2);
    root2->r = new node(3);
    root2->l->l = new node(1);
    root2->l->r = new node(1);
    root2->r->l = new node(2);
    root2->r->r = new node(1);
    root2->l->l->l = new node(1);


//////////////////////////////////////////////////////////////////////////////////////////////////////////

    //// TRREE 3 with root 3 ////

    Node root3 = new node(7);

    root3->l = new node(4);
    root3->r = new node(5);
    root3->l->l = new node(3);
    root3->l->r = new node(1);
    root3->r->l = new node(2);
    root3->r->r = new node(6);
    root3->l->r->l = new node(8);
    root3->l->r->l->l = new node(9);//node added for disbalance































cout<<"\n";
}