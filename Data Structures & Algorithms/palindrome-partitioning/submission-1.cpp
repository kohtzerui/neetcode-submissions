class Solution {
private:
    vector<vector<string>> res = {};

    bool isPalindrome(string substring, int l_index, int r_index){
        while(l_index < r_index){
            if(substring[l_index] != substring[r_index]){
                return false;
            } 
            l_index++;
            r_index--;
        }
        return true;
    }

    void dfs(int start_index, vector<string>& cur, string& s){
        if(start_index == s.length()){
            res.push_back(cur);
            return;
        }

        for(int i=start_index; i<s.length(); i++){
            if(isPalindrome(s, start_index, i)){
                cur.push_back(s.substr(start_index, i-start_index+1));
                dfs(i + 1, cur, s);
                cur.pop_back();
            }
        }
    }   

public:
    vector<vector<string>> partition(string s) {
        vector<string> cur = {};
        dfs(0, cur, s);
        return res;
    }
};
