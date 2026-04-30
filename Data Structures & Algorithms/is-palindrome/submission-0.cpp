/*
Outer Loop: while (left < right)

Inner Loop (Left): while (left < right && !isalnum(s[left])) { left++; }

Inner Loop (Right): while (left < right && !isalnum(s[right])) { right--; }

Comparison: If tolower(s[left]) != tolower(s[right]), return false.

Advance: Otherwise, left++; right--;
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        
        while(left < right){
            while(left < right && !isalnum(s[left])){
                left++;
            }
            while(left < right && !isalnum(s[right])){
                right--;
            }
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
