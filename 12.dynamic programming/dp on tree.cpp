#include"DynamicProgramming.h"

int main()
{
//*-----------------------|D O T|-----------------------
/*

            1
          /   \
         2     3
        / \     \
       4   5     6
        \       / \
         9     7   8
        /     / \   \
      10     11 12  13

*/
    Node root = new node(1);

    // left sub tree
    root->l = new node(2);
    root->l->l = new node(4);
    root->l->r = new node(5);
    root->l->l->r = new node(9);
    root->l->l->r->l = new node(10);

    // right sub tree
    root->r = new node(3);
    root->r->r = new node(6);
    root->r->r->l = new node(7);
    root->r->r->r = new node(8);
    root->r->r->l->l = new node(11);
    root->r->r->l->r = new node(13);
    root->r->r->r->r = new node(13);

    int res = INT_MIN;
    // maxDiameter(root, res);
    // pr2("max diameter :", res);

    
}