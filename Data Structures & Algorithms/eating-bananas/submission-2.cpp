class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int result = right;

        while(left <= right){
            int mid = left + (right - left)/2;
            long long totalHours = 0;
            for(int& pile : piles){ 
                int hoursForPile = (pile/mid) + (pile%mid != 0);
                totalHours += hoursForPile;
            }    
            if(totalHours <= h){
                result = mid;
                right = mid -1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};
