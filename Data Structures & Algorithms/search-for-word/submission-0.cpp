class Solution {
private:
    int row;
    int column;

    bool dfs(vector<vector<char>>& board, string word, int r, int c, int letter_index){
        if(letter_index == word.size()){
            return true;
        }
        
        //recurse end condition/rejection criteria
        if(r >= row || c >= column || r < 0 || c < 0){
            return false;
        }
        
        //if the first letter, not the first index of the word
        if(board[r][c] != word[letter_index]){
            return false;
        }
         
        //if the first letter, is the first index of the word perform dfs
        char temp = board[r][c];
        board[r][c] = '@';

        bool found = dfs(board, word, r+1, c, letter_index+1) ||
                     dfs(board, word, r-1, c, letter_index+1) ||
                     dfs(board, word, r, c+1, letter_index+1) ||
                     dfs(board, word, r, c-1, letter_index+1);

        board[r][c] = temp;

        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        column = board[0].size();
        row = board.size();
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                if(dfs(board, word, i, j, 0)){
                    return true;
                }
            }
        }

        return false;
    }
};
