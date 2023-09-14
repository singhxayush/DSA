#include <bits/stdc++.h>
using namespace std;

#define sz(x) (sizeof(x)/sizeof(x[0]))
#define pr(x) cout<<x<<endl;
#define pr2(x, y) cout<<x<<' '<<y<<endl;
#define pr3(x, y, z) cout<<x<<' '<<y<<' '<<z<<endl;


bool visited[1000] = {0};


//*------------------------------------------------------------------------------------------------------


int matrix[1000][1000];

void storeGraph_adj(int n, vector<pair<int, int>> vertices, bool isDirected = false) //* n = number of nodes
{
    int m = vertices.size();
    for(int i=0; i<m; i++)
    {
        int u = vertices[i].first;
        int v = vertices[i].second;
        matrix[u][v] = 1;
        if(!isDirected) matrix[v][u] = 1;
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
            if(matrix[i][j]) cout<<"|"<<matrix[i][j]<<"|\t";
            else cout<<" "<<matrix[i][j]<<"\t";
        }
        cout<<"\n\n";
    }
}

//*------------------------------------------------------------------------------------------------------


vector<unordered_set<int>> adjList;

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
    adjList = temp;
    temp.clear();
}
void print_array_list(int n)
{
    cout<<"\n";
    for(int i=0; i<=n; i++) 
    {
        cout<<i<<" → ";
        if(adjList[i].empty()) cout<<"NULL";
        else for(auto x : adjList[i]) cout<<x<<" "; cout<<"\n";
    }
    cout<<"\n";
}

//*------------------------------------------------------------------------------------------------------


//? TRAVERSALS 

//* Breadth First Search (BFS) | T.C = O(N + 2E)
vector<int> BFS(int n, vector<pair<int, int>> vertices, int root)
{
    // Store the vertices in Array List adjList
    storeGraph_arraylist(n, vertices);
    print_array_list(n);

    // Store root node in the queue
    queue<int> q;
    q.push(root);

    // Tracking Visited Nodes
    visited[root] = 1;

    // Vector to store BFS result
    vector<int> res;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        res.push_back(node);

        for(auto it : adjList[node])
        {
            if(!visited[it])
            {
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    return res;
}


//* Depth First Search (DFS)
vector<int> DFS(int n, vector<pair<int, int>> vertices, int root)
{
    static vector<int> dfs;
    dfs.push_back(root);
    visited[root] = 1;

    for(auto it : adjList[root])
    {
        if(!visited[it])
        {
            DFS(n, vertices, it);
        }
    }

    return dfs;
}


//*------------------------------------------------------------------------------------------------------

//? Number of Provinces
//! https://practice.geeksforgeeks.org/problems/number-of-provinces/1

//? Number of Islands
//! https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

//? Flood Fill Algo
//! https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

//? Rotten Oranges
//! https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1k


//*------------------------------------------------------------------------------------------------------


//? Detect cycle in an undirected graph (using BFS!)
//! https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

bool isCycle_bfs(int n, vector<pair<int, int>> vertices, int root = 1)
{
    // Store the vertices in Array List adjList (doesnt deal with components)
    storeGraph_arraylist(n, vertices);
    print_array_list(n);

    // Store root node in the queue as {current node, parent node}
    queue<pair<int, int>> q;
    q.push({root, -1});

    // Tracking root
    visited[root] = 1;

    while(!q.empty())
    {
        int curNode = q.front().first;
        int parNode = q.front().second;
        q.pop();

        for(auto adjNode : adjList[curNode])
        {
            if(!visited[adjNode])
            {
                visited[adjNode] = 1;
                q.push({adjNode, curNode});
            }
            else if(parNode != adjNode)
            {
                return true;
            }
        }
    }

    return false;
}


// for discrete components BFS
bool detect_cycle_in_a_component(int n, vector<pair<int, int>> vertices, int root)
{
    queue<pair<int, int>> q;

    q.push({root, -1});
    visited[root] = 1;

    while(!q.empty())
    {
        int curNode = q.front().first;
        int parNode = q.front().second;
        q.pop();

        for(auto adjNode : adjList[curNode])
        {
            if(!visited[adjNode])
            {
                visited[adjNode] = 1;
                q.push({adjNode, curNode});
            }
            else if(parNode != adjNode)
            {
                return true;
            }
        }
    }

    return false;
}
bool isCycle_with_components(int n, vector<pair<int, int>> vertices, int root)
{
    storeGraph_arraylist(n, vertices);
    print_array_list(n);

    for(int i=1; i<=n; i++) 
    if(!visited[i] && isCycle_bfs(n, vertices, root)) return true;
    
    return false;
}


//? Detect cycle in an undirected graph (using DFS!)
bool isCycle_dfs_solve(int node, int parent)
{
    visited[node] = 1;

    for(auto adjNode : adjList[node])
    {
        if(!visited[adjNode])
        {
            if(isCycle_dfs_solve(adjNode, node)) return 1;
        }
        else if(adjNode != parent) return 1;
    }

    return 0;
}
bool isCycle_dfs(int n, vector<pair<int, int>> vertices)
{
    storeGraph_arraylist(n, vertices);
    print_array_list(n);

    for(int i=1; i<=n; i++)
    {
        if(!visited[i]){
            if(isCycle_dfs_solve(i, -1)) return 1;
        }
    }

    return 0;
}


//*------------------------------------------------------------------------------------------------------

//? Distance of Nearest cell having 1
//! https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
//! https://leetcode.com/problems/01-matrix/



//*------------------------------------------------------------------------------------------------------
