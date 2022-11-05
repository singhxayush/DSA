#include <bits/stdc++.h>
using namespace std;

// Node definition
struct node
{
    int val;
    node * l;
    node * r;
    node(int x)
    {
        val = x;
        l = r = NULL;
    }
};

typedef node * Node;

// Function to Build Tree from level order traversal
Node buildTree(string str)
{
    if (str.length() == 0 || str[0] == 'N') return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; ) ip.push_back(str);

    Node root = new node(stoi(ip[0]));

    queue<Node> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        Node currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if (currVal != "N") {
            currNode->l = new node(stoi(currVal));
            queue.push(currNode->l);
        }

        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        if (currVal != "N") {

            currNode->r = new node(stoi(currVal));
            queue.push(currNode->r);
        }
        i++;
    }
    return root;
}





// dfs traversals - working on 1st tree(root1)
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
            cout<<cur->val<<" ";
        }
        cout<<"\n";
    }
}

void i_preorder(Node root) {

    if(!root) return;

    stack<Node> st;

    st.push(root);

    while(!st.empty()) {
        int n = st.size();
        for(int i=0; i<n; i++) {
            Node cur = st.top();
            st.pop();
            if(cur->r != NULL) st.push(cur->r);
            if(cur->l != NULL) st.push(cur->l);
            cout<<cur->val<<" ";
        }
    }
}

void i_inorder(Node root) {

    if(!root) return;

    stack<Node> st;

    Node cur = root;

    while(true) {
        if(cur != NULL) {
            st.push(cur);
            cur = cur->l;
        }
        else {
            if(st.empty()) break;
            cur = st.top();
            st.pop();
            cout<<cur->val<<" ";
            cur = cur->r;
        }
    }
}

void i_postorder_2stack(Node root) {

    if(!root) return;

    stack<Node> st, res;

    st.push(root);

    Node cur;

    while(!st.empty()) {
        cur = st.top();
        st.pop();
        res.push(cur);
        if(cur->l != NULL) st.push(cur->l);
        if(cur->r != NULL) st.push(cur->r);
    }
    while(!res.empty()) { cout<<res.top()->val<<" "; res.pop(); }
}

int is_balanced(Node root) {
    if(root == NULL) return 0;

    int lh = is_balanced(root->l);
    if(lh == -1) return -1;

    int rh = is_balanced(root->r);
    if(rh == -1) return -1;

    if(abs(lh-rh)>1) return -1;

    return 1+max(lh, rh);
}

int diameter(Node root, int &dia) {

    if(root == NULL) return 0;

    int ll = diameter(root->l, dia); // left length
    int rl = diameter(root->r, dia); // right length
    dia = max(dia, rl+ll);

    return 1 + max(ll, rl);    
}

// maximum path sum
// a path is such that every node will be appear only once in it
int path_sum(Node root, int &res) {

    if(root == NULL) return 0;

    int lsum = max(0, path_sum(root->l, res));
    int rsum = max(0, path_sum(root->r, res));
    res = max(res, (lsum + rsum + root->val));
    
    // cout<<"Node :"<<root->val<<" "<<lsum<<" "<<rsum<<" "<<res<<"\n";
    return (root->val + max(lsum, rsum));
}

bool is_identical(Node root1, Node root2) {
    if(root1 == NULL || root2 == NULL) return (root1 == root2);

    return (root1->val == root2->val) &&
            is_identical(root1->l, root2->l) &&
            is_identical(root1->r, root2->r);
}

void zig_zag(Node root) {
    queue<Node> q;

    q.push(root);

    int x = 0;

    while(!q.empty()){
        int n = q.size();
        vector<int> temp;
        while(n--) {
            Node cur = q.front();
            temp.push_back(cur->val);
            q.pop();

            if(cur->l != NULL) q.push(cur->l);
            if(cur->r != NULL) q.push(cur->r);
        }

        if(x) reverse(temp.begin(), temp.end());
        for(auto x : temp) cout<<x<<" "; 
        x^=1;
    }
    cout<<"\n";
}


// Boundary traversal AntiClockWise

bool is_leaf(Node root) {
    if(root->l == NULL && root->r == NULL) return true;
    return false;
}
void left_boundary(Node root, vector<int> &v) {
    Node cur = root->l;
    while(cur) {
        if(!is_leaf(cur)) v.push_back(cur->val);
        if(cur->l) cur = cur->l;
        else cur = cur->r;
    }
}
void leaf_boundary(Node root, vector<int> &v) {
    if(is_leaf(root)) {
        v.push_back(root->val);
        return;
    }
    if(root->l) leaf_boundary(root->l, v);
    if(root->r) leaf_boundary(root->r, v);
}
void right_boundary(Node root, vector<int> &v) {
    Node cur = root->r;
    stack<int> st;
    while(cur) {
        if(!is_leaf(cur)) st.push(cur->val);
        if(cur->r) cur = cur->r;
        else cur = cur->l;
    }
    while(!st.empty()){
        v.push_back(st.top());
        st.pop();
    }
}
void boundary_traversal_anticlockwise(Node root) {

    if(root == NULL) return;
    vector<int> res;
    res.push_back(root->val);
    left_boundary(root, res);
    if(!is_leaf(root)) leaf_boundary(root, res);
    right_boundary(root, res);
    for(auto x : res) cout<<x<<" ";
}


//vertical order traversal
// same level nodes must be in sorted order
// we do level order traversal with root, x level and y level parameters as tuple udner queue
// we maintain a data structure of from map<int, map<int, multiset<int>>>
//                                           |        |             |
//                  stores level wise : verticle   horizontal     values

void vertical_order(Node root) {

    map<int, map<int, multiset<int>>> m;

    queue<pair<Node, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while(!q.empty()) {

        auto cur = q.front();
        q.pop();
        int x = cur.second.first;
        int y = cur.second.second;
        m[x][y].insert((cur.first)->val);

        if(cur.first->l) q.push({(cur.first)->l, {x-1, y+1}});
        if(cur.first->r) q.push({(cur.first)->r, {x+1, y+1}});
    }

    // vector<vector<int>> res;

    vector<int> v;
    for(auto x1 : m) {
        for(auto x2 : x1.second) v.insert(v.end(), x2.second.begin(), x2.second.end());
        // res.push_back(v);
    }
    for(auto x : v) cout<<x<<" ";
    // for(int i=0; i<res.size(); i++) {
    //     for(int j=0; j<res[i].size(); j++) cout<<res[i][j]<<" ";
    //     cout<<"\n";
    // }
}

void top_view(Node root) {

    if(root == NULL) return;
    queue<pair<Node, int>> q;
    map<int, int> m;
    q.push({root, 0});

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = cur.second;
        Node temp = cur.first;

        if(m.find(x)==m.end()) m[x] = temp->val;

        if(temp->l) q.push({temp->l, x-1});
        if(temp->r) q.push({temp->r, x+1});
    }

    for(auto x : m) cout<<x.second<<" ";
}


void bottom_view(Node root) {

    if(root == NULL) return;
    queue<pair<Node, int>> q;
    map<int, int> m;
    q.push({root, 0});

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = cur.second;
        Node temp = cur.first;

        m[x] = temp->val;

        if(temp->l) q.push({temp->l, x-1});
        if(temp->r) q.push({temp->r, x+1});
    }

    for(auto x : m) cout<<x.second<<" ";
}