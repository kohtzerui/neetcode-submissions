class Solution {
public:
    void swap(int& num1, int& num2){
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    int findDuplicate(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            while(nums[i] != i+1){
                if (nums[i] == nums[nums[i] - 1])  // duplicate detected
                    return nums[i];
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        return -1;
    }
};
