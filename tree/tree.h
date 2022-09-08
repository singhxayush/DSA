// Creating Node
#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;
struct node
{
    int key;
    node * left;
    node * right;

    node(int x)
    {
        key = x;
        left = right = NULL;
    }
};

typedef node * Node;



// DFS Traversals

void inorder(Node root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

void postorder(Node root)
{
    if(root != NULL)
    {
        inorder(root->left);
        inorder(root->right);
        cout<<root->key<<" ";
    }
}

void preorder(Node root)
{
    if(root != NULL)
    {
        cout<<root->key<<" ";
        inorder(root->left);
        postorder(root->right);
    }
}



// Height of Binary Tree

int height(Node root)
{
    if(root == NULL) return 0;
    else return max(height(root->left), height(root->right))+1;
}

void node_at_distance_(int k, Node root)
{
    if(root != NULL)
    {
        if(k==0) cout<<root->key<<" ";
        else
        {
            node_at_distance_(k-1, root->left);
            node_at_distance_(k-1, root->right);
        }
    }
}



//Breadth First search - Level order traversal
// time complexity - Theta(N)
// auxilary space - Theta(W) | W -> width of binary tree | 1<=W<=N

void levelorder_naive(Node root)
{
    int h = height(root);
    for(int i=1; i<=h; i++)
    {
        node_at_distance_(i-1, root);
    }
}

void levelorder(Node root)
{
    if(root == NULL) return;
    queue<Node> q;
    q.push(root);

    while(q.empty() == false)
    {
        Node cur = q.front();
        q.pop();
        cout<<cur->key<<" ";
        if(cur->left != NULL) q.push(cur->left);
        if(cur->right != NULL) q.push(cur->right);
    }
}

void levelorder_linebyline_1(Node root)
{
    if(root == NULL) return;
    queue<Node> q;
    q.push(root);
    q.push(NULL);

    while(q.size() > 1)
    {
        Node cur = q.front();
        q.pop();
        if(cur == NULL)
        {
            cout<<endl;
            q.push(NULL);
            continue;
        }
        cout<<cur->key<<" ";
        if(cur->left != NULL) q.push(cur->left);
        if(cur->right != NULL) q.push(cur->right);
    }
}

void levelorder_linebyline_2(Node root) // T.C. O(N) | A.S. Theta(W-width of tree) or O(N)
{
    if(root == NULL) return;
    queue<Node> q;
    q.push(root);
    while(q.empty()==false)
    {
        int count = q.size();
        for(int i=0; i<count; i++)
        {
            Node cur = q.front();
            q.pop();
            cout<<cur->key<<" ";
            if(cur->left != NULL) q.push(cur->left);
            if(cur->right != NULL) q.push(cur->right);
        }
        cout<<endl;
    }
}


// Size of a given binary TREE
int getsize(Node root) // TC : O(N) | AS : O(H)
{
    if(root == NULL) return 0;
    else return 1 + getsize(root->left) + getsize(root->right);
}

// Maximum in binary tree
int getmax(Node root)
{
    if(root == NULL) return INT_MIN;
    else return max(root->key, max(getmax(root->left), getmax(root->right)));
}

// Left view of Binary Tree
int maxlevel = 0;
void left_view_recursive(Node root, int level)
{
    if(root == NULL) return;
    if(maxlevel <level)
    {
        cout<<root->key<<" ";
        maxlevel = level;
    }
    left_view_recursive(root->left, level+1);
    left_view_recursive(root->right, level+1);
}
void print_left_view_recursive(Node root)
{
    left_view_recursive(root, 1);
}

void print_left_view_iterative(Node root){
    if(root==NULL) return;
    queue<Node> q;
    q.push(root);
    while(q.empty()==false)
    {
        int count=q.size();
        for(int i=0;i<count;i++)
        {
            Node curr=q.front();
            q.pop();
            if(i==0) cout<<curr->key<<" ";
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
        }
    }
}


//children sum property
bool isCsum(Node root)
{
    if(root == NULL) return true;
    if(root->left == NULL && root->right==NULL) return true;
    int sum = 0;
    if(root->left != NULL) sum += root->left->key;
    if(root->right != NULL) sum += root->right->key;
    return (root->key == sum && isCsum(root->left) && isCsum(root->right));
}

// Check if tree is Height balanced or not
// binary tree in which the height of the left and right subtree of any node differ by not more than 1.
bool isbalanced_naive(Node root) // O(N^2)
{
    if(root==NULL) return false;
    int lh = height(root->left);
    int rh = height(root->right);
    return (abs(lh-rh)<=1 && isbalanced_naive(root->left) && isbalanced_naive(root->right));
}