class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        stack<pair<int, int>> tracker; //index, height

        for(int i=0; i<heights.size(); i++){
            int start_index = i;
            while(!tracker.empty() && heights[i] < tracker.top().second){
                int popped_index = tracker.top().first;
                int popped_height = tracker.top().second;
                tracker.pop();

                int width = i - popped_index;
                int area = popped_height * width;
                max_area = max(max_area, area);
                
                start_index = popped_index;
            }
            tracker.push({start_index, heights[i]});
        }

        while(!tracker.empty()){
            int popped_index = tracker.top().first;
            int popped_height = tracker.top().second;
            tracker.pop();

            int width = heights.size() - popped_index;
            int area = popped_height * width;
            max_area = max(max_area, area);
        }

        return max_area;
    }
};
