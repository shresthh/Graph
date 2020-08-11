class Solution {
public:
    void dfs(vector<vector<int>> &A, int i, int j){
        if(i < 0 || j < 0 || i > A.size()-1 || j > A[i].size()-1 || A[i][j] == 0 )
            return;
        A[i][j] = 0;
        dfs(A, i+1, j);
        dfs(A, i-1, j);
        dfs(A, i, j+1);
        dfs(A, i, j-1);
    }
    int numEnclaves(vector<vector<int>>& A) {
        int rows = A.size();
        if(rows == 0)
            return 0;
        int cols = A[0].size();
    
        int c = 0;
        for(int i= 0; i< rows; i++){
            for (int j = 0; j< cols; j++){
                if(A[i][j] == 1){
                    if(i == 0 || j == 0 || i==rows-1 || j == cols-1)
                        dfs(A, i, j);
                }

            }
        }
        for(int i = 0; i< rows; i++){
            for (int j = 0; j< cols; j++){
                if(A[i][j] == 1)
                    c++;
            }
        }
        return c;
    }
};
