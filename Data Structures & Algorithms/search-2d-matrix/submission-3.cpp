// in each array if 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int bottom = matrix.size()-1;
        int lastInt = matrix[0].size()-1;
        int firstInt = 0;
        
        if(target < matrix[0][firstInt] || target > matrix[matrix.size()-1][lastInt]){
            return false;
        }

        while(top <= bottom){
            int midRow = top + (bottom-top)/2;
            // checking boundary conditions
            if(target > matrix[midRow][lastInt]){
                top = midRow + 1;
            } else if(target < matrix[midRow][firstInt]){
                bottom = midRow - 1;
            } else {
                break;
            }
        }
        
        if(top > bottom) return false;

        int targetRowIndex = top + (bottom - top) / 2;
        const vector<int>& targetRow = matrix[targetRowIndex];
        
        int left = 0;
        int right = targetRow.size()-1;

        while(left <= right){
            int mid = left + (right-left)/2;
            if(target > targetRow[mid]){
                left = mid + 1;
            } else if(target < targetRow[mid]){
                right = mid -1;
            } else {
                return true;
            }
        }
        
        return false;
    }
};
