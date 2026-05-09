class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> temp;
        vector<int> answer(temperatures.size(), 0);

        for(int i=0; i<temperatures.size(); i++){
            while(!temp.empty() && temperatures[i] > temperatures[temp.top()]){
                int prevDayIndex = temp.top();
                temp.pop();

                answer[prevDayIndex] = i - prevDayIndex;
            }
            temp.push(i);
        }

        return answer;
    }
};
