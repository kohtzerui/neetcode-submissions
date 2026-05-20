class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()){
            return "";
        }
        vector<int> need(128,0);
        vector<int> window(128,0);

        for(char character : t){
            need[character]++;
        }

        int needCount = 0;
        for(int i=0; i<128; i++){
            if(need[i] > 0) needCount++;
        }

        int have = 0;
        int left = 0;
        int resLeft = 0;
        int resLen = INT_MAX;

        for(int right = 0; right<s.size(); right++){
            char temp = s[right];
            window[temp]++;
            if(need[temp]>0 && window[temp] == need[temp]){
                have++;
            }
            while(have == needCount){
                if(right - left + 1 < resLen){
                    resLen = right - left + 1;
                    resLeft = left;
                }
                char leftChar = s[left];
                window[leftChar]--;
                if(need[leftChar] > 0 && window[leftChar] < need[leftChar]){
                    have--;
                }
                left++;
            }    
        }
        return resLen == INT_MAX ? "" : s.substr(resLeft, resLen);
    }
};
