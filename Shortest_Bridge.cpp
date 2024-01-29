/*
  This is the solution to the question where I have tried a BFS solution for finding the shortest path to second Island. 
  First I have found the first Island usinf the DFS and stored its coordinates and then from those cordinates I have done the BFS traversal
  
  It is important to note that we const use Dikshtra here because it is implemented on single source to single destination

  # Hope it helps
*/


// TC O(n) for DFS + O(n) for BFS
// SC O(n*m)
class Solution {
public:
    int m, n;
    vector<vector<int>> dir = {{-1,0},{0,-1},{0,1},{1, 0}};
    
    bool isSafe(int i, int j) {
        return (i < m && i >= 0 && j < n && j >= 0);
    }
    
    //DFS
    void dfs(vector<vector<int>>& grid, int i, int j, set<pair<int, int>>& coordinates) {
        if(!isSafe(i, j) || grid[i][j] == 0 || coordinates.find({i, j}) != coordinates.end()) {
            return;
        }
        
        coordinates.insert({i, j});
        
        for(auto &it : dir) {
            int n_row = i + it[0];
            int n_col = j + it[1];
            
            dfs(grid, n_row, n_col, coordinates);
        }
    }
    
    //BFS
    int bfs(vector<vector<int>>& grid, set<pair<int, int>>& coordinates) {
        queue<pair<int, int>> q;
        
        for(auto &it : coordinates) {
            q.push({it});
        }
        
        int ans = 0;
        
        while(!q.empty()) {
            int siz = q.size();
            
            while(siz--) {
                auto p = q.front();
                q.pop();
                
                for(auto &it : dir) {
                    int n_row = p.first + it[0];
                    int n_col = p.second + it[1];

                    //to check all the directions are safe and no cell is repeated even its one
                    if(isSafe(n_row, n_col) && coordinates.find({n_row, n_col}) == coordinates.end()) {
                        if(grid[n_row][n_col] == 1) //found another island then return ans
                            return ans;
                        
                        //insert it in coordinates;
                        coordinates.insert({n_row, n_col});
                        q.push({n_row, n_col});
                    }
                }
                
            }
            ans++;
        }
        
        return ans;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        set<pair<int, int>> coordinates;
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                
                if(grid[i][j] == 1) {
                    //we will check for the forst Island though DFS and store its coordinates
                    dfs(grid, i, j, coordinates);

                    //then after that we will do BFS for finding second Island and return if we found the shortest path
                    return bfs(grid, coordinates);
                }
                
            }
        }
        
        return -1;
    }
};
