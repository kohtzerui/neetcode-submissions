class TrieNode {
public:
    TrieNode* children[26];
    string word;

    TrieNode() {
        for(int i=0; i<26; i++){
            children[i] = nullptr;
        }
        word = "";
    }
};

class Solution {
private:
    vector<string> res;
    int rows;
    int cols;

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node){
        if(r < 0 || c < 0 || r >= rows || c >= cols){
            return;
        }

        char ch = board[r][c];
        if(ch == '#'){
            return;
        }

        //Mistake! Must always check and return before accessing memory
        int index = ch - 'a';
        if(node->children[index] == nullptr){
            return;
        }
        node = node->children[index];

        if(node->word != ""){
            res.push_back(node->word);
            node->word = "";
        }

        board[r][c] = '#';

        dfs(board, r+1, c, node);
        dfs(board, r-1, c, node);
        dfs(board, r, c+1, node);
        dfs(board, r, c-1, node);

        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for(string& word : words){
            TrieNode* cur = root;
            for(char c : word){
                int index = c -'a';
                if(cur->children[index] == nullptr){
                    cur->children[index] = new TrieNode();
                }
                cur = cur->children[index];
            }
            cur->word = word;
        }

        rows = board.size();
        cols = board[0].size();

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                dfs(board, r, c, root);
            }
        }

        return res;
    }
};
