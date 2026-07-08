class Solution {
private:
    int res = 0;
    int rows; 
    int cols;

    int dfs(vector<vector<int>>& grid, int r, int c, int& local_max){
        if(r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0){
            return 0;
        }

        grid[r][c] = 0;
        local_max++;
        
        dfs(grid, r+1, c, local_max);
        dfs(grid, r-1, c, local_max);
        dfs(grid, r, c+1, local_max);
        dfs(grid, r, c-1, local_max);

        return local_max;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                int local_max = 0;
                int temp = dfs(grid, r, c, local_max);
                if(temp != 0){
                    res = max(temp, res);
                }
            }
        }

        return res;
    }
};
