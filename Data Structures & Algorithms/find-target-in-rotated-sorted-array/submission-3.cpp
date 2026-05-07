class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        // phase 1
        while(right > left){
            int mid = left + (right-left)/2;
            if(nums[mid] > nums[right]){
                left = mid + 1;
            } else{
                right = mid;
            }
        }

        //phase 2
        int pivot = left;
        left = 0;
        right = nums.size()-1;
        // determine if right or left fall
        if(target >= nums[pivot] && target <= nums[right]){
            left = pivot;
        } else {
            right = pivot -1;
        }
        // standard
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid]==target){
                return mid;
            } else if(nums[mid] < target){
                left = mid + 1;
            } else{
                right = mid -1;
            }
        }

        return -1;
    }
};
