#include "segtree.h"
int main()
{
    vector<int> a{1, 5, -1, 2, 1, 4, -3, 6, 2, 5};
    Node root = build_st(a, 0, a.size()-1);

    // levelorder(root);

    int sum = querySt(root, 1, 9); cout<<sum<<"\n";
}