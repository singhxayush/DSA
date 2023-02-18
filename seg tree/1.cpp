#include "segtree.h"
int main()
{
    // vector<int> a{1, 5, -1, 2, 1, 4, -3, 6, 2, 5};
    vector<int> a{3, 2, 4, 5, 1, 1, 5, 3};
    build_st(a);
    
    levelorder(rootnode);
    cout<<query(2-1, 4-1)<<"\n";

    // sum_update(a, 2, 1);
    // levelorder(rootnode);
    // cout<<query(0, 2)<<"\n";

}