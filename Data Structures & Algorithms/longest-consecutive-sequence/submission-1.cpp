class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> elements(nums.begin(), nums.end());

        int global_max = 0;
        
        for(int number : elements){
            if(elements.find(number-1) == elements.end()){
                int current = number; 
                int local_max = 1; 
                
                while(elements.find(current + 1) != elements.end()){
                    current++;
                    local_max++;
                } 

                if(local_max > global_max){
                    global_max = local_max;
                    local_max = 1;
                }
            }        
        }

    return global_max;
    }
};
