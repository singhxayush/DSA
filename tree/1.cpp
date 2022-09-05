/////// Binary Tree ///////

/*

    Degree of every node is atmost 2

*/

#include<iostream>
#include"tree.h"
// struct node
// {
//     int key;
//     node * left;
//     node * right;

//     node(int x)
//     {
//         key = x;
//         left = right = NULL;
//     }
// };

#include<iostream>
using namespace std;
int main()
{
    Node root = new node(1);
    
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
}