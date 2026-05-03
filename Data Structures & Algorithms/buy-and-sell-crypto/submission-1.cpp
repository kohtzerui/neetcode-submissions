class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int first = 0;
        int next = 1;
        int max = 0;

        while(next < prices.size()){
            int local = prices[next] - prices[first];
            if(local<=0){
                first = next;
            } else {
                if(local > max){
                    max = local;
                }
            }
            next++;
        }
        return max;
    }
};
