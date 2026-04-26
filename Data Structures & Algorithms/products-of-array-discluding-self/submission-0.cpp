class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) { 
        vector<int> prefix = {};
        vector<int> suffix = {};

        int pre_accum = 1;
        for(int i=0; i<nums.size(); i++){
            if(i==0){
                prefix.push_back(1);    
            } else {
                pre_accum*=nums[i-1];
                prefix.push_back(pre_accum);
            }
        }

        int suf_accum = 1;
        for(int i=nums.size()-1; i >= 0; i--){
            if(i==nums.size()-1){
                suffix.push_back(1);    
            } else {
                suf_accum *= nums[i+1];
                suffix.push_back(suf_accum);
            }
        }

        vector<int> answer = {};
        for(int i=0; i<nums.size(); i++){
            answer.push_back(prefix[i] * suffix[nums.size()-1-i]);
        }
        return answer;
    }
};
