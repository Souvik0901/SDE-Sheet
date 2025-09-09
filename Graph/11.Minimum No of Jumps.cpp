#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minJumps(vector<int>& A, int x, int y) {
    int n = A.size();
    if (x == y) return 0;

    vector<bool> visited(n, false);
    queue<pair<int, int>> q; // {index, steps}
    
    q.push({x, 0});
    visited[x] = true;

    while (!q.empty()) {
        auto [curr, steps] = q.front();
        q.pop();

        // Possible jumps
        vector<int> nextIndices = {curr + A[curr], curr - A[curr]};
        
        for (int next : nextIndices) {
            if (next == y) return steps + 1;
            
            if (next >= 0 && next < n && !visited[next]) {
                visited[next] = true;
                q.push({next, steps + 1});
            }
        }
    }
    
    return -1; // unreachable
}

int main() {
    vector<int> A = {2, 3, 1, 1, 4};
    int x = 0;
    int y = 4;
    
    int result = minJumps(A, x, y);
    cout << "Minimum jumps from " << x << " to " << y << ": " << result << endl;

    return 0;
}




//You're given an array A of size N.

//You're at index x and want to reach index y.

// At each step, from index i, you can jump to:

// i + A[i] if it's within bounds

// i - A[i] if it's within bounds

// Find the minimum number of jumps needed to go from x to y.

// This is a typical shortest path problem on an implicit graph, where each index is a node and jumps define edges. A BFS (Breadth-First Search) is ideal because it explores nodes layer by layer, ensuring the shortest path is found.
