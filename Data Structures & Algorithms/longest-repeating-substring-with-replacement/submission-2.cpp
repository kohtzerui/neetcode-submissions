class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int left = 0, maxFreq = 0, maxLen = 0;
        
        for(int right = 0; right<s.length(); right++){
            int currCharIndex = s[right] - 'A';
            count[currCharIndex]++;
            
            maxFreq = max(maxFreq, count[currCharIndex]);

            int windowSize = right - left + 1;
            while(windowSize - maxFreq > k){
                int leftCharIndex = s[left] - 'A';
                count[leftCharIndex]--;
                left++;
                windowSize = right - left + 1;
            }
            maxLen = max(maxLen, windowSize);
        }
        return maxLen;
    }
};
