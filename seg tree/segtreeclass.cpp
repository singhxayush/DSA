#include <bits/stdc++.h>
using namespace std;

// Segment Tree using Pointers
// @author: Ankit Josh
// Tested on: https://cses.fi/problemset/task/1646

template <typename T>
class SegTree
{
public:
    T data;
    int size;
    SegTree *left;
    SegTree *right;

    // Constructor
    SegTree()
    {
        left = NULL;
        right = NULL;
    }

    // Destructor
    ~SegTree()
    {
        delete left;
        delete right;
    }

    void makeChild()
    {
        if (this->left == NULL)
            this->left = new SegTree();
        if (this->right == NULL)
            this->right = new SegTree();
    }

    // Initialize
    void init(int n)
    {
        size = 1;
        while (size < n)
        {
            size *= 2;
        }
    }

    // Merge
    T merge(T x, T y) { return (x + y); }
    // Leaf Node
    T single(int v) { return v; }

    // Build
    void build(SegTree<T> *root, vector<int> &arr, int lx, int rx)
    {
        if (lx == rx)
        {
            if (lx < (int)arr.size())
                root->data = single(arr[lx]);
            return;
        }

        int mid = (lx + rx) / 2;
        root->makeChild();
        build(root->left, arr, lx, mid);
        build(root->right, arr, mid + 1, rx);
        root->data = merge(root->left->data, root->right->data);
    }
    void build(SegTree<T> *root, vector<int> &arr)
    {
        build(root, arr, 0, size - 1);
    }

    // Update
    void set(SegTree<T> *root, int lx, int rx, int idx, int val)
    {
        if (lx == rx)
        {
            root->data = val;
            return;
        }

        int mid = (lx + rx) / 2;
        if (idx <= mid)
        {
            set(root->left, lx, mid, idx, val);
        }
        else
        {
            set(root->right, mid + 1, rx, idx, val);
        }
        root->data = merge(root->left->data, root->right->data);
    }
    void set(SegTree<T> *root, int idx, int val)
    {
        set(root, 0, size - 1, idx, val);
    }

    // Query
    T query(SegTree<T> *root, int lx, int rx, int l, int r)
    {
        if (rx < l || r < lx)
        {
            return 0;
        }
        if (lx >= l && rx <= r)
        {
            return root->data;
        }

        int mid = (lx + rx) / 2;
        T q1 = query(root->left, lx, mid, l, r);
        T q2 = query(root->right, mid + 1, rx, l, r);
        return merge(q1, q2);
    }
    T query(SegTree<T> *root, int l, int r)
    {
        return query(root, 0, size - 1, l, r);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    SegTree<long long> *st = new SegTree<long long>();
    st->init(n);
    st->build(st, a);
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << st->query(st, l, r) << endl;
    }
    delete st;
}