class Solution {
private: 
    int rows;
    int cols;

public:
    int orangesRotting(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c] == 2){
                    q.push({r,c});
                } else if(grid[r][c] == 1){
                    fresh++;
                }
            }
        }

        int directions[4][2] = {
            {1,0}, 
            {-1,0},
            {0,1},
            {0,-1}
        };

        int minutes = 0;

        while(!q.empty() && fresh > 0){
            int levelSize = q.size();

            for(int i = 0; i < levelSize; i++){
                auto[r,c] = q.front();
                q.pop();

                for(auto& direction : directions){
                    int newR = r + direction[0];
                    int newC = c + direction[1];

                    if(newR < 0 || newC < 0 || newR >= rows || newC >= cols){
                        continue;
                    }

                    if(grid[newR][newC] != 1){
                        continue;
                    }

                    grid[newR][newC] = 2;
                    fresh--;

                    q.push({newR, newC});
                }
            }

            minutes++;
        }

        return (fresh == 0) ? minutes : -1;
    }
};
