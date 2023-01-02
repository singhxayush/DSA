#include"tree.h"

int main()
{
    //// TREE 1 with root 1 ////

    Node     root1 = new node(1);
             root1->l = new node(2);
    Node p = root1->r = new node(3);
             root1->l->l = new node(4);
    Node y = root1->l->r = new node(5);
             root1->r->r = new node(6);
             root1->r->r->l = new node(7);
             root1->r->r->r = new node(8);
    Node x = root1->l->l->r = new node(9);
             root1->r->r->l->l = new node(11);
             root1->r->r->l->r = new node(13);
             root1->r->r->r->r = new node(13);
             root1->l->l->r->l = new node(10);

    // string r1 = "1 2 3 4 5 N 6 N 9 7 8 10";
    // Node root1 = buildTree(x1);

    // preorder(root1);
    // inorder(root1);
    // postorder(root1);
    // levelorder(root1);
    // i_preorder(root1);
    // i_inorder(root1);
    // i_postorder_2stack(root1);
    // int dia = INT_MIN; diameter(root1, dia); cout<<dia<<endl;
    // zig_zag(root1);
    // boundary_traversal_anticlockwise(root1);
    // vertical_order(root1);
    // top_view(root1);
    // bottom_view(root1);
    // right_view(root1);
    // cout<<lca(root1, x, y)->val<<"\n";
    // childern_sum_update(root1); levelorder(root1);

    distanceK(root1, p, 3);

//////////////////////////////////////////////////////////////////////////////////////////

    //// TRREE 2 with root 2 ////

    Node root2 = new node(5);
    root2->l = new node(2);
    root2->r = new node(3);
    root2->l->l = new node(1);
    root2->l->r = new node(1);
    root2->r->l = new node(2);
    root2->r->r = new node(1);
    root2->l->l->l = new node(1);


/////////////////////////////////////////////////////////////////////////////////////////

    //// TRREE 3 with root 3 ////

    Node root3 = new node(7);
    root3->l = new node(4);
    root3->r = new node(5);
    root3->l->l = new node(3);
    Node temp = root3->l->r = new node(1);
    root3->r->l = new node(2);
    root3->r->r = new node(6);
    root3->l->r->l = new node(8);
    root3->l->r->l->l = new node(9); // node added for disbalance

    // if(is_balanced(root3)==-1) cout<<"false\n"; else cout<<"true\n";
    // vector<int> path; if(root_to_node(root3, 9, path)) for(auto x : path) cout<<x<<" "; else cout<<"false";


/////////////////////////////////////////////////////////////////////////////////////////

    //// TREE 4 with root 4 ////

    // string r4 = "-10 9 20 N N 15 7";
    // string r4 = "10 2 -25 20 1 3 4";
    // Node root4 = buildTree(r4);

    // int pathsum = INT_MIN; path_sum(root4, pathsum); cout<<pathsum<<endl;

    // cout<<is_identical(root4, root3);


/////////////////////////////////////////////////////////////////////////////////////////
    
    //// TREE 5 with root 5 ////

    // string r5 = "7 5 5 1 2 2 1";
    // string r5 = "7 5 5 1 N N 1 N 2 2 N";
    // Node root5 = buildTree(r5); cout<<IsSymmetric(root5);


}