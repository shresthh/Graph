class Solution {
public:
    void mark_curr_island(vector<vector<char>> &grid, int i, int j, int n, int m){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] != '1')
            return;
        grid[i][j] = 2;
        
        mark_curr_island(grid, i+1, j, n, m);
        mark_curr_island(grid, i-1, j, n, m);
        mark_curr_island(grid, i, j-1, n, m);
        mark_curr_island(grid, i, j+1, n, m);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0)
            return 0;
        int m = grid[0].size();
        int no_of_islands = 0;
        for(int i = 0; i< n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '1'){
                    mark_curr_island(grid, i, j, n, m);
                    no_of_islands += 1;
                }
            }
        }
        return no_of_islands;
    }
};
