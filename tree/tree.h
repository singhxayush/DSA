// Creating Node
#include<queue>
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