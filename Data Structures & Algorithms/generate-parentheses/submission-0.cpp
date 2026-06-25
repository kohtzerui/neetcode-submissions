class Solution {
private:
    vector<string> res = {};

    void dfs(int n, int open, int close, string cur){
        if(cur.length() == 2*n){
            res.push_back(cur);
        }
        if(n > open){
            cur.push_back('(');
            dfs(n, open + 1, close, cur);
            cur.pop_back();
        }
        if(open > close){
            cur.push_back(')');
            dfs(n, open, close + 1, cur);
            cur.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        string cur = "";
        dfs(n, 0, 0, cur);
        return res;
    }
};
