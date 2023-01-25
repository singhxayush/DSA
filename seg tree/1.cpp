#include "segtree.h"
int main()
{
    vector<int> a{1, 5, -1, 2, 1, 4, -3, 6, 2, 5};
    build_st(a);
    levelorder(rootnode);

    // int sum = querySt(root, 1, 1, 0, a.size()-1); cout<<sum<<"\n";

    // Stree * st = new Stree();
    // st->construct_st(st, a);
}