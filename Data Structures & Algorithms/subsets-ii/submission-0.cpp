class Solution {
private:
    vector<vector<int>> res = {};

    void dfs(int start, vector<int>& cur, vector<int>& nums){
        res.push_back(cur);
        for(int i = start; i < nums.size(); i++){
            if(i > start && nums[i] == nums[i-1]){
                continue;
            }
            cur.push_back(nums[i]);
            dfs(i+1, cur, nums);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur = {};
        dfs(0, cur, nums);
        return res;
    }
};
