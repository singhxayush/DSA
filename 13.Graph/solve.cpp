//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int dx[4] = {-1, 0, +1, 0};
int dy[4] = {0, +1, 0, -1};

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size(), m = grid[0].size();
	    
	    queue<pair<int, int>> q;
	    
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<m; j++)
	        {
	            if(grid[i][j] == 1) q.emplace(i, j);
	            else grid[i][j] = -1;
	        }
	    }
	    
	    while(!q.empty())
	    {
	        auto [row, col] = q.front();
	        q.pop();
	        
	        for(int i=0; i<4; i++)
	        {
	            int nrow = row + dx[i];
	            int ncol = col + dy[i];
	            
	            if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && grid[nrow][ncol] == -1)
	            {
	                grid[nrow][ncol] = grid[row][col] + 1;
	                q.emplace(nrow, ncol);
	            }
	        }
	    }
	    return grid;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends