//return indices, condition, unique indices, only one answer exist

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer = {};
        
        unordered_map<int, int> tracker;

        for(int i=0; i<nums.size(); i++){
            int remainder = target - nums[i];
            if(tracker.find(remainder) == tracker.end()){
                tracker[nums[i]] = i;
            } else{
                answer.push_back(tracker[remainder]);
                answer.push_back(i);
                return answer;
            }
        }

        return answer;
    }
};