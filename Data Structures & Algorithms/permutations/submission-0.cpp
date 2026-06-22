class Solution {
private:
    vector<vector<int>> res = {};
    
    void dfs(vector<int>& cur, vector<int>& nums, vector<bool>& used){
        if(cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(used[i]){
                continue;
            }
            used[i] = true;
            cur.push_back(nums[i]);

            dfs(cur, nums, used);
            cur.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur = {};
        vector<bool> used(nums.size(), false);
        dfs(cur, nums, used);
        return res;
    }
};
