class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        char ptr0 = ' ';
        char ptr1 = ' ';

        for(int i=0; i<s.length(); i++){
            ptr0 = s[i];
            ptr1 = t[i];
            if(ptr0 != ptr1){
                return false;
            }
        }
        return true;
    }
};
