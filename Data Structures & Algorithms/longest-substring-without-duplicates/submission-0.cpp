class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0){
            return 0;
        }

        unordered_set<char> tracker = {};
        int first = 0;
        int second = 0;
        int maxLen = 0;

        while(second < s.length()){
            if(tracker.find(s[second]) == tracker.end()){
                tracker.insert(s[second]);
                maxLen = max(maxLen, second - first + 1);
                second++;
            } else {
                tracker.erase(s[first]);
                first++;
            }
        }
        return maxLen;
    }
};
