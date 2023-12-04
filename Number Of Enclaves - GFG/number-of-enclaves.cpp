//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int row, int col, vector<vector<int>> &vis,vector<vector<int>> &grid, int delrow[], int delcol[] ){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, vis, grid, delrow, delcol);
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
          const int DELTA_SIZE = 4;
          int n = grid.size();
          int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delrow[DELTA_SIZE] = {-1, 0, 1, 0};
        int delcol[DELTA_SIZE] = {0, 1, 0, -1};

        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && grid[0][j] == 1) {
                dfs(0, j, vis, grid, delrow, delcol);
            }

            if (!vis[n - 1][j] && grid[n - 1][j] == 1) {
                dfs(n - 1, j, vis, grid, delrow, delcol);
            }
        }

        for (int j = 0; j < n; j++) {
            if (!vis[j][0] && grid[j][0] == 1) {
                dfs(j, 0, vis, grid, delrow, delcol);
            }

            if (!vis[j][m - 1] && grid[j][m - 1] == 1) {
                dfs(j, m - 1, vis, grid, delrow, delcol);
            }
        }
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                   cnt++;
                }
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends