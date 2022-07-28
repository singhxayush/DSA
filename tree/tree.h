// Creating Node
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