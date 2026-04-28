class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int first = 0; 
        int last = numbers.size()-1;

        vector<int> answer = {};
        for(int i=0; i<numbers.size(); i++){
            int sum = numbers[first] + numbers[last];
            if(sum > target){
                last--;
            } else if(sum < target){
                first++;
            } else{
                answer.push_back(first + 1);
                answer.push_back(last + 1);
                return answer;
            }
        }
    }
};
