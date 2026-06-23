class Solution {
private:
    vector<vector<int>> res = {};

    void dfs(int start, vector<int>& cur, vector<int>& candidates, int target, int cursum){
        if(cursum == target){
            res.push_back(cur);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates at the same recursion level
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Since sorted, no need to continue if this exceeds target
            if (cursum + candidates[i] > target) {
                break;
            }

            cur.push_back(candidates[i]);

            // i + 1 because each element can only be used once
            dfs(i + 1, cur, candidates, target, cursum + candidates[i]);

            cur.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur = {};
        int cursum = 0;
        sort(candidates.begin(), candidates.end());
        dfs(0, cur, candidates, target, cursum);
        return res;
    }
};
