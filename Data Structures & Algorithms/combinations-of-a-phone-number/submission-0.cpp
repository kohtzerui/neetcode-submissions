class Solution {
private:
    vector<string> res;

    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void dfs(int index, string& cur, string& digits) {
        if (index == digits.length()) {
            res.push_back(cur);
            return;
        }

        string letters = mp[digits[index]];

        for (char c : letters) {
            cur.push_back(c);
            dfs(index + 1, cur, digits);
            cur.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        string cur = "";
        dfs(0, cur, digits);
        return res;
    }
};