class Solution {
public:
    string number_of_distinct_islands(vector<vector<int>> &grid, int i, int j, int rows, int cols, string direction){
        if(i<0 || j<0 || i>=rows || j>=cols || grid[i][j] == 0){
            return "O";
        }
        grid[i][j] = 0;
        
        string left = number_of_distinct_islands(grid, i, j-1, rows, cols, "L");
        string right = number_of_distinct_islands(grid, i, j+1, rows, cols, "R");
        string up = number_of_distinct_islands(grid, i-1, j, rows, cols, "U");
        string down = number_of_distinct_islands(grid, i+1, j, rows, cols, "D");
        
        return (direction + left + right + up + down);
        
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows == 0)
            return 0;
        int cols = grid[0].size();
        set<string> set;
        for(int i =0; i < rows; i++){
            for(int j = 0; j< cols; j++){
                if(grid[i][j] == 1){
                    string path = number_of_distinct_islands(grid, i,j, rows, cols, "X");
                    set.insert(path);
                }
            }
        }
        return set.size();
    }
};
