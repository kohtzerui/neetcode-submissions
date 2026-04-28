class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer = {};
        sort(nums.begin(), nums.end());

        for(int first=0; first<nums.size()-2; first++){
            int last = nums.size()-1;
            int middle = first+1;

            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }

            while(middle < last){
                int sum = nums[first] + nums[middle] + nums[last];
                if(sum == 0){
                    answer.push_back({nums[first], nums[middle], nums[last]});
                    middle++;
                    last--;

                    while (middle < last && nums[middle] == nums[middle - 1]) {
                        middle++;
                    }
                } else if(sum < 0){
                    middle++;
                } else {
                    last --;
                }
            }
            middle = first+1;
            last = nums.size()-1;
        }
        return answer;
    }
};
