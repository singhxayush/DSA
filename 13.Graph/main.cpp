#include"graph.h"

int main()
{
// check out 01basics.cpp first

// ----------------- Initializaiton -----------------
    // int n = 5;
    // int m = 6;
    // vector<pair<int, int>> vertices;
    // vertices.push_back({1, 2});
    // vertices.push_back({1, 3});
    // vertices.push_back({2, 4});
    // vertices.push_back({3, 4});
    // vertices.push_back({2, 5});
    // vertices.push_back({4, 5});

    // for(pair x : vertices) cout<<x.first<<" "<<x.second<<"\n";

    // storeGraph_adj(n, vertices);
    // print_adj_matrix(n);

    // storeGraph_arraylist(n, vertices);
    // print_array_list(n);


// ----------------- Traversals -----------------

    //? BFS
    int n = 8;
    vector<pair<int, int>> vertices; // refer to graph on Page 5(Notes)
    vertices.push_back({1, 2});
    vertices.push_back({1, 6});
    vertices.push_back({2, 3});
    vertices.push_back({2, 4});
    vertices.push_back({6, 7});
    vertices.push_back({6, 8});
    vertices.push_back({4, 5});
    vertices.push_back({7, 5});

    // int root = 1;
    // int root = 6;
    int root = 5;
    vector<int> bfs = BFS(n, vertices, root);
    for(auto x : bfs) cout<<x<<" "; cout<<"\n";
}