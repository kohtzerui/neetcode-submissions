class Solution {
public:
    bool checkRow(const vector<char>& selectedRow){
        unordered_set<char> duplicates = {};
        for(char number: selectedRow){
            if(number != '.'){
                if(duplicates.find(number) != duplicates.end()){
                    return false;
                }
                duplicates.insert(number);
            }
        }
        return true;
    }

    bool checkColumn(vector<vector<char>>& board, int columnNum){
        unordered_set<char> duplicates = {};
        
        for(int i=0; i<board.size(); i++){
            char number = board[i][columnNum];
            if(number != '.'){
                if(duplicates.find(number) != duplicates.end()){
                    return false;
                }
                duplicates.insert(number);
            }
        }
        return true;    
    }

    bool checkBox(vector<vector<char>>& board, int columnNum, int rowNum){
        unordered_set<char> duplicates = {};
        int boxCol = (columnNum/3)*3;
        int boxRow = (rowNum/3)*3;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                char current = board[boxRow+i][boxCol+j];
                if(current != '.'){
                    if(duplicates.find(current) != duplicates.end()){
                        return false;
                    }
                }
                duplicates.insert(current);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++){
            if(checkRow(board[i]) == false){
                cout<< '0';
                return false;
            }
            if(checkColumn(board, i) == false){
                cout<< '1';
                return false;
            }
        }

        for(int i=0; i<board.size(); i+=3){
            for(int j=0; j<board.size(); j+=3){
                if(checkBox(board, j, i) == false){
                    cout<< '2';
                    return false;
                }
            }
        }
        return true;
    }
};
