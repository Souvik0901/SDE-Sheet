// using DFS
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


//using bfs
void bfs(vector<vector<char>>& grid, int i, int j) {
    int m = grid.size();
    int n = grid[0].size();
    
    queue<pair<int,int>> q;
    q.push({i, j});
    grid[i][j] = '0'; // mark visited
    
    // Directions (up, down, left, right)
    vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
    
        for (auto [dx, dy] : dirs) {
            int nx = x + dx;
            int ny = y + dy;
    
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1') {
                grid[nx][ny] = '0';   // mark visited
                q.push({nx, ny});     // add to queue
            }
        }
    }
}


int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                count++;          // found new island
                bfs(grid, i, j);  // sink the whole island
            }
        }
    }
    return count;
}

