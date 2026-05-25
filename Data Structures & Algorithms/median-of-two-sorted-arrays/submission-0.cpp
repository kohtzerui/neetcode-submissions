class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Step 1: Always binary search on the smaller array.
        // This ensures the time complexity is O(log(min(m, n))) and 
        // prevents index out-of-bounds errors when calculating partition2.
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        
        // Define the search space in nums1
        int left = 0;
        int right = m;
        
        while (left <= right) {
            // Make our guess for the cut in nums1
            int partition1 = left + (right - left) / 2;
            
            // Calculate the corresponding cut in nums2
            int partition2 = (m + n + 1) / 2 - partition1;
            
            // Fetch the 4 boundary elements. 
            // If there are no elements on a side, use infinity / negative infinity.
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];
            
            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];
            
            // Evaluate our guess
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // We found the perfect partition!
                
                // If the total combined length is odd
                if ((m + n) % 2 != 0) {
                    return max(maxLeft1, maxLeft2);
                } 
                // If the total combined length is even
                else {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                }
            }
            // Cut in nums1 is too far to the right, pull it left
            else if (maxLeft1 > minRight2) {
                right = partition1 - 1;
            }
            // Cut in nums1 is too far to the left, push it right
            else {
                left = partition1 + 1;
            }
        }
        
        // Code should logically never reach here if inputs are valid sorted arrays
        return 0.0;
    }
};
