#include<bits/stdc++.h>
using namespace std;

typedef  long long   ll;
typedef  long double ld;
#define  all(x) x.begin(), x.end()
#define  rall(x) x.rbegin(), x.rend()
#define  testcases int tt; cin>>tt; while(tt--)

#define  dbg(x) cout<<'d'<<'b'<<'g'<<'-'<<'>'<<x<<endl;
#define  pr(x) cout<<x<<endl;
#define  pr2(x, y) cout<<x<<' '<<y<<endl;
#define  pr3(x, y, z) cout<<x<<' '<<y<<' '<<z<<endl;

// Structure implementaion of tree
struct node
{
    int val;
    node * l;
    node * r;
    node(int x = 0)
    {
        val = x;
        l = r = NULL;
    }
};

typedef node * Node;

void preorder(Node root) {

    if(root == NULL) return;
    cout<<root->val<<" ";
    preorder(root->l);
    preorder(root->r);
}
void inorder(Node root) {

    if(root == NULL) return;
    inorder(root->l);
    cout<<root->val<<" ";
    inorder(root->r);
}
void postorder(Node root) {

    if(root == NULL) return;
    postorder(root->l);
    postorder(root->r);
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
            if(cur->l != NULL) q.push(cur->l);
            if(cur->r != NULL) q.push(cur->r);
            cout<<cur->val<<"{"<<cur->range.first<<", "<<cur->range.second<<"}"<<" | ";
        }
        cout<<"\n";
    }
}



Node build_st(vector<int> a, int left, int right)
{
    if(left == right) return new node(a[left]);

    int mid = (left+right)/2;
    Node cur = new node();
    cur->l = build_st(a, left, mid);
    cur->r = build_st(a, mid+1, right);
    cur->val = min(cur->l->val, cur->r->val);
    cur->val = (cur->l->val + cur->r->val);

    return cur;
}

int querySt(Node root, int lq, int rq, int ls, int rs)
{
    if(ls > rq || rs < lq) return 0;
    if(ls <= lq && rs >= rq) return root->val;
    mid = (ls + rs)>>1;
    return querySt(root->l, lq, rq, ls, mid) + querySt(root->r, lq, rq, mid+1, rs);
}


// class Stree
// {
//     public:

//         int val;
//         Stree *l, *r;
//         ~Stree(int x){ l = r = NULL; val = x; };
//         // ~Stree(){ l = r = NULL; };

//         void construct_st(Stree * root, int ls, rs)
//         {
//             if(ls == rs)
//             {
//                 root->data = a[ls];
//                 return;
//             }
//             int mid = (ls + rs) >> 1;

//             if(root->l == NULL) 

//             construct_st(root->l, ls, mid);
//             construct_st(root->r, mid + 1, rs);
//             root->data = 
//         }
//         void construct_st(Stree * root, vector<int> a)
//         {
//             int n = a.size();
//             int x = ceil(2, log2(n));
//             int size = pow(2, x);
//             construct_st(root, 0, size-1);
//         }

//         int query(Stree * root, int lq, int rq)
//         {

//         }
// };