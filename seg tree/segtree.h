#include<bits/stdc++.h>
using namespace std;

typedef  long long   ll;
typedef  long double ld;
#define  dbg(x) cout<<'d'<<'b'<<'g'<<'-'<<'>'<<x<<endl;

// Structure implementaion of SegTree
struct node
{
    int val;
    node * left;
    node * right;
    node(int x = 0)
    {
        val = x;
        left = right = NULL;
    }
};

typedef node * Node;


// _________________________________Traversals___________________________________
void preorder(Node root) {

    if(root == NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node root) {

    if(root == NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
void postorder(Node root) {

    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}
void levelorder(Node root) {
    
    queue<Node> q;
    if(root == NULL) return;

    q.push(root);

    while(!q.empty()){

        int n = q.size();
        for(int i=0; i<n; i++){
            Node cur = q.front();
            q.pop();
            if(cur->left != NULL) q.push(cur->left);
            if(cur->right != NULL) q.push(cur->right);
            cout<<cur->val<<" ";
            // cout<<cur->val<<"{"<<cur->range.first<<", "<<cur->range.second<<"}"<<" | ";
        }
        cout<<"\n";
    }
}
// _____________________________________________________________________________




Node rootnode;
int N;

int mid(int l, int r) { return (l+r)>>1; }

Node build_st(vector<int> &a, int l, int r)
{
    if(l==r) return new node(a[l]);

    int m = mid(l, r);

    // post order traversal
    Node cur = new node();
    cur->left = build_st(a, l, m);
    cur->right = build_st(a, m+1, r);

    // type of seg-tree //
    cur->val = cur->left->val + cur->right->val;

    return cur;
}

void build_st(vector<int> &a)
{
    N = a.size();
    rootnode = build_st(a, 0, N-1);
}

int query(Node root, int lq, int rq, int ls, int rs)
{
    if(lq > rs || rq < ls) return 0;
    if(ls>=lq && rs<=rq) return root->val;
    int m = mid(ls, rs);
    return query(root->left, lq, rq, ls, m) + query(root->right, lq, rq, m+1,rs);
}

int query(int l, int r) { return query(rootnode, l, r, 0, N-1); }


void update(Node root, int dif, int idx, int ls, int rs)
{
    if(idx < ls || idx > rs) return;
    
    if(ls == rs && ls == idx)
    {
        root->val += dif;
        return;
    }

    int m = mid(ls, rs);
    update(root->left, dif, idx, ls, m);
    update(root->right, dif, idx, m+1, rs);

    root->val += dif;
}

void update(vector<int> &a, int idx, int val) { update(rootnode, val-a[idx], idx, 0, N-1); }