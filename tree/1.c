/* 
    root - topmost node
    parent - node which connects to the child
    child - node which is connected by another node is its child
    lead/external node - nodes with no children
    internal node - node with atleast one child

    depth(of a node) - no of edges from root to the that node
    height - no of edges from the given node to the deepest leaf

    siblings - node belonging to the same parent
    ancestors/descendents - 
*/

/* 
    BINARY TREE : A tree in which degree of each node is less than or equal to 2

    A tree with n nodes has n-1 Why n-1?
    Because in a tree, there is one and only edge corresponding to all the nodes except the root node. The root node has no parent, hence no edge pointing to it. Therefore, a total of n-1 edges.

    The degree of a node in a tree is the number of children of a node.
    The degree of a tree is the highest degree of a node among all the nodes present in the tree.

*/

/* 
    Types of binary tree :
    1. full or strict binary tree - all nodes have either 0 or 2 children. Binary trees as we said earlier have a degree of 2 or less than 2. But a strict binary tree is a binary tree having all of its nodes with a degree of 2 or 0. That is each of its nodes either have 2 children or is a leaf node

    2. perfect binary tree - A perfect binary tree has all its internal nodes with degree strictly 2 and has all its leaf nodes on the same level. A perfect binary tree as the name suggests appears exactly perfect.

    Every leaf node above in both the examples are on the same level and all the internal nodes have a degree 2. Below illustrated is a binary which is not a perfect binary tree because the colored node is an internal node and has a degree of just 1, although each leaf node is on the same level


    3. complete binary tree
    all levels are completly filled except possibly last level + last level must have its as left as possible

    4. Degenerate tree - The easiest of all, degenerate trees are binary trees where every parent node has just one child and that can be either to its left or right

    5. Skewed trees are binary trees where every parent node has just a single child and that child should be strict to the left or to the right for all the parents. Slewed trees having all the child nodes aligned to the left are called left-skewed trees, and skewed trees having all the child nodes aligned to the right are called right-skewed trees. 
    
*/