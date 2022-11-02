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

