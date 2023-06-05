#include <bits/stdc++.h>
using namespace std;

#define sz(x) (sizeof(x)/sizeof(x[0]))
#define pr(x) cout<<x<<endl;
#define pr2(x, y) cout<<x<<' '<<y<<endl;
#define pr3(x, y, z) cout<<x<<' '<<y<<' '<<z<<endl;

//*--------------------------------------------------------------------------------------------


int G1[100][100];

void storeGraph_adj(int n, vector<pair<int, int>> vertices, bool isDirected = false) //* n = number of nodes
{
    int m = vertices.size();
    for(int i=0; i<m; i++)
    {
        int u = vertices[i].first;
        int v = vertices[i].second;
        G1[u][v] = 1;
        if(!isDirected) G1[v][u] = 1;
    }
}
void print_adj_matrix(int n)
{
    cout<<"\t";
    for(int i=0; i<=n; i++) cout<<"["<<i<<"]\t"; cout<<"\n\n";
    for(int i=0; i<=n; i++)
    {
        cout<<"["<<i<<"]\t";
        for(int j=0; j<=n; j++){
            if(G1[i][j]) cout<<"|"<<G1[i][j]<<"|\t";
            else cout<<" "<<G1[i][j]<<"\t";
        }
        cout<<"\n\n";
    }
}

//*------------------------------------------------------------------------------------------------------

vector<unordered_set<int>> G2;

void storeGraph_arraylist(int n, vector<pair<int, int>> vertices, bool isDirected = false) //* n = number of nodes
{
    vector<unordered_set<int>> temp(n+1);
    int m = vertices.size();
    for(int i=0; i<m; i++)
    {
        int u = vertices[i].first;
        int v = vertices[i].second;
        temp[u].insert(v);
        if(!isDirected) temp[v].insert(u);
    }
    G2 = temp;
    temp.clear();
}
void print_array_list(int n)
{
    cout<<"\n";
    for(int i=0; i<=n; i++) 
    {
        cout<<i<<" → ";
        for(auto x : G2[i]) cout<<x<<" "; cout<<"\n";
    }
    cout<<"\n";
}

//*------------------------------------------------------------------------------------------------------

//? TRAVERSALS 

// Breadth First Search (BFS)
vector<int> BFS(int n, vector<pair<int, int>> vertices, int root)
{
    // Store the vertices in Array List G2
    storeGraph_arraylist(n, vertices);
    print_array_list(n);

    // Store root node in the queue
    queue<int> q;
    q.push(root);

    // Tracking Visited Nodes
    bool vis[n+1] = {0};
    vis[root] = 1;

    // Vector to store BFS result
    vector<int> res;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        res.push_back(node);

        for(auto it : G2[node])
        {
            if(!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return res;
}