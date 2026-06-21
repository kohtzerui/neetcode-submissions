class Solution {
private:
    vector<vector<int>> res = {};

    void dfs(int j, vector<int>& cur, vector<int> nums){
        res.push_back(cur);
        for(int i=j; i< nums.size(); i++){
            cur.push_back(nums[i]);
            dfs(i+1, cur, nums);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur = {};
        dfs(0, cur, nums);
        return res;
    }
};
