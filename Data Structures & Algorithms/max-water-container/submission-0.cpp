class Solution {
public:
    int maxArea(vector<int>& heights) {
        int first = 0;
        int last = heights.size()-1;
        int global_max = 0;
    
        while(first<last){
            int area = min(heights[first], heights[last]) * (last-first);
            
            if(area > global_max){
                global_max = area;
            }

            if(heights[first] > heights[last]){
                last--;
            } else{
                first++;
            }
        }

        return global_max;
    }
};
