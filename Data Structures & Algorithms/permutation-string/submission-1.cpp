class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()){
            return false;
        }
        vector<int> s1count(26,0);
        vector<int> s2count(26,0);
        for(int i=0; i<s1.length(); i++){
            s1count[s1[i] - 'a']++;
            s2count[s2[i] - 'a']++;
        }

        int left = 0;
        for(int right = s1.length(); right<s2.length(); right++){
            if(s1count == s2count){
                return true;
            }
            s2count[s2[right] - 'a']++;
            s2count[s2[left] - 'a']--;
            left++;
        }
        if(s1count == s2count){
            return true;
        }
        return false;
    }
};
