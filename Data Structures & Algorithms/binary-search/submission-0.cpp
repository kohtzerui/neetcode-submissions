/*
(1) Split the array: You set up a boundary with left = 0 and right = nums.size() - 1. Then, you find the middle index.

Pro-tip: Instead of doing (left + right) / 2, use left + (right - left) / 2. It does the exact same math, but protects your code from integer overflow bugs if you are dealing with massive arrays!

(2) Find the number: You look at the value sitting at nums[mid].

(3) Compare to target: Check if nums[mid] == target. If it is a match, you're done! Return the mid index.

(4) Move left or right:

If nums[mid] < target (e.g., you landed on 2, but are looking for 4), the target must be to the right. You chop off the left half by setting left = mid + 1.

If nums[mid] > target, the target must be to the left. You chop off the right half by setting right = mid - 1.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() -1;

        for(int i=0; i<nums.size(); i++){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                return mid;
            } else if (nums[mid] < target){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
