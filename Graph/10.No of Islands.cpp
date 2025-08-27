class Solution {
public:

    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        
        // boundary check + if water already
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
            return;

        // mark as visited (sink the land)
        grid[i][j] = '0';

        // explore neighbors (up, down, left, right)
        dfs(grid, i + 1, j); // down
        dfs(grid, i - 1, j); // up
        dfs(grid, i, j + 1); // right
        dfs(grid, i, j - 1); // left
    }


    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;          // found new island
                    dfs(grid, i, j);  // sink the whole island
                }
            }
        }
        return count;
    }
};
