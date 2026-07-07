class Solution {
private:
    int direction[4][2] = {{1, 0}, {-1, 0}, {0,1}, {0,-1}};
    
    void dfs(vector<vector<char>>&grid, int r, int c){
        int rows = grid.size();
        int cols = grid[0].size();

        if(r < 0 || c < 0 || c >= cols || r >= rows || grid[r][c] == '0'){
            return;
        }

        grid[r][c] = '0';

        for(int i=0; i<4; i++){
            int nr = r + direction[i][0];
            int nc = c + direction[i][1];

            dfs(grid, nr, nc);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int islands = 0;

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c] == '1'){
                    islands++;
                    dfs(grid, r, c);
                }
            }
        }

        return islands;
    }
};
