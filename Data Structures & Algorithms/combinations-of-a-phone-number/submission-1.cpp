class Solution {
private:
    vector<string> res = {};

    unordered_map<char, string> dial = {
        {'2', "abc"},
        {'3', "def"}, 
        {'4', "ghi"}, 
        {'5', "jkl"}, 
        {'6', "mno"}, 
        {'7', "pqrs"}, 
        {'8', "tuv"}, 
        {'9', "wxyz"}  
    };

    void dfs(int start, string& cur, string& digits){
        if(start == digits.length()){
            res.push_back(cur);
            return;
        }
        string temp = dial[digits[start]];

        for(int i=0; i<temp.size(); i++){
            cur.push_back(temp[i]);
            dfs(start+1, cur, digits);
            cur.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits == ""){
            return res;
        }
        string cur = "";
        dfs(0, cur, digits);
        return res;
    }
};
