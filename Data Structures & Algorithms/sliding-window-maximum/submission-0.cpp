class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq; // Stores indices, not the actual values

        for (int i = 0; i < nums.size(); i++) {
            // 1. Remove elements from the front that have fallen out of the window
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            // 2. Remove "useless" smaller elements from the back
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // 3. Add the current element's index to the deque
            dq.push_back(i);

            // 4. Once the window reaches size k, add the front of the deque to the result
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};
