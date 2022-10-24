// Creating Node
#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;
struct node
{
    int key;
    int depth;
    node * l;
    node * r;
    node(int x)
    {
        key = x;
        l = r = NULL;
    }
};

typedef node * Node;


// DFS Traversals
bool dfstraversal = true;
void inorder(Node root)
{
    if(dfstraversal)
    {
        cout<<"InOrder : ";
        dfstraversal = false;
    }
    if(root != NULL)
    {
        inorder(root->l);
        cout<<root->key<<" ";
        inorder(root->r);
    }
}

void postorder(Node root)
{
    if(dfstraversal)
    {
        cout<<"PostOrder : ";
        dfstraversal = false;
    }
    if(root != NULL)
    {
        inorder(root->l);
        inorder(root->r);
        cout<<root->key<<" ";
    }
}

void preorder(Node root)
{

    if(dfstraversal)
    {
        cout<<"PreOrder : ";
        dfstraversal = false;
    }
    if(root != NULL)
    {
        cout<<root->key<<" ";
        preorder(root->l);
        preorder(root->r);
    }
}


// Height of Binary Tree
int height(Node root)
{
    if(root == NULL) return 0;
    else return max(height(root->l), height(root->r))+1;
}

void node_at_distance_(int k, Node root)
{
    if(root != NULL)
    {
        if(k==0) cout<<root->key<<" ";
        else
        {
            node_at_distance_(k-1, root->l);
            node_at_distance_(k-1, root->r);
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
        if(cur->l != NULL) q.push(cur->l);
        if(cur->r != NULL) q.push(cur->r);
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
        if(cur->l != NULL) q.push(cur->l);
        if(cur->r != NULL) q.push(cur->r);
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
            if(cur->l != NULL) q.push(cur->l);
            if(cur->r != NULL) q.push(cur->r);
        }
        cout<<endl;
    }
}

// Size of a given binary TREE
int getsize(Node root) // TC : O(N) | AS : O(H)
{
    if(root == NULL) return 0;
    else return 1 + getsize(root->l) + getsize(root->r);
}

// Maximum in binary tree
int getmax(Node root)
{
    if(root == NULL) return INT_MIN;
    else return max(root->key, max(getmax(root->l), getmax(root->r)));
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
    left_view_recursive(root->l, level+1);
    left_view_recursive(root->r, level+1);
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
            if(curr->l!=NULL) q.push(curr->l);
            if(curr->r!=NULL) q.push(curr->r);
        }
    }
}

//children sum property
bool isCsum(Node root)
{
    if(root == NULL) return true;
    if(root->l == NULL && root->r==NULL) return true;
    int sum = 0;
    if(root->l != NULL) sum += root->l->key;
    if(root->r != NULL) sum += root->r->key;
    return (root->key == sum && isCsum(root->l) && isCsum(root->r));
}

// Check if tree is Height balanced or not
// binary tree in which the height of the l and r subtree of any node differ by not more than 1.
bool isbalanced_naive(Node root) // O(N^2)
{
    if(root==NULL) return true;
    int lh = height(root->l);
    int rh = height(root->r);
    return (abs(lh-rh)<=1 && isbalanced_naive(root->l) && isbalanced_naive(root->r));
}

int isbalanced(Node root) // O(N)
{
    if(root==NULL) return 0;
    int lh = isbalanced(root->l);
    if(lh==-1) return -1;
    int rh = isbalanced(root->r);
    if(rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    else return (max(lh, rh) + 1);
}

int max_width(Node root) // A.S. Theta(width) | T.C. Theta(N)
{
    if(root == NULL) return 0;
    queue<Node> q;
    q.push(root);

    int res = 0;

    while(q.empty() == false)
    {
        int count = q.size();
        res = max(res, count);
        for(int i=0; i<count; i++)
        {
            Node curr = q.front();
            q.pop();
            if(curr->l != NULL) q.push(curr->l);
            if(curr->r != NULL) q.push(curr->r);
        }
    }
    return res;
}

// Flatten The Tree section
Node BTtoDLL_in(Node root)
{
    static Node prev = NULL;
    static Node head = NULL;
    if(root == NULL) return root;
    BTtoDLL_in(root->l);
    if(prev == NULL) head = root;
    else
    {
        root->l = prev;
        prev->r = root;
    }
    prev = root;
    BTtoDLL_in(root->r);
    return head;
}

void printlist(Node head)
{
    cout<<"LIST : "; while(head->l != NULL) {
        cout<<head->key<<" ";
        head = head->l;
    } cout<<endl;
}