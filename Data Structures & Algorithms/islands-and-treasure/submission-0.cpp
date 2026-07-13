class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 0){
                    q.push({r,c});
                }
            }
        }

        int directions[4][2] = {
            {1, 0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(auto& direction : directions){
                int newR = r + direction[0];
                int newC = c + direction[1];

                if(newR < 0 || newC < 0 || newR >= rows || newC >= cols){
                    continue;
                }

                if(grid[newR][newC] != INT_MAX){
                    continue;
                }

                grid[newR][newC] = grid[r][c] + 1;
                q.push({newR, newC});
            }
        }
    }
};
