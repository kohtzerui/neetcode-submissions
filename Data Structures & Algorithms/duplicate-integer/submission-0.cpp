//Duplicate = true
//NoDuplicate = false

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> duplicate;
        
        for(int x : nums){
            if(duplicate.find(x) != duplicate.end()){
                return true;
            }
            duplicate.insert(x);
        }
        return false;
    }
};