class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> answer = {};
        unordered_map<int, int> track;

        for(int i=0; i<nums.size(); i++){
            track[nums[i]]++;
        }

        vector<vector<int>> buckets(nums.size()+1);
        for(const auto& pair : track){
            buckets[pair.second].push_back(pair.first);
        }

        for(int i=buckets.size()-1; i>=0; i--){
            for(const auto& num : buckets[i]){
                answer.push_back(num);
                if(answer.size() == k){
                    return answer;
                }
            }
        }
        
        return answer;
    }
};
