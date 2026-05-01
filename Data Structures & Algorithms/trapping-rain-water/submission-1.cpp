//interesting min(prefix-suffix array)-height at each index

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;

        vector<int> prefix(n);
        vector<int> suffix(n);
        
        prefix[0] = height[0];
        for(int i = 1; i < n; i++){
            prefix[i] = max(prefix[i-1], height[i]); 
        }
        
        suffix[n-1] = height[n-1]; // Set the base case safely
        for(int i = n - 2; i >= 0; i--){
            suffix[i] = max(suffix[i+1], height[i]);
        }
        
        int totalWater = 0;
        for(int i=0; i<height.size(); i++){
            int water = min(prefix[i], suffix[i]) - height[i];
            if(water > 0){
                totalWater += water; 
            }
        }
        return totalWater;
    }
};
