class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> pairing = {
            {')', '('}, 
            {']', '['},
            {'}', '{'}
        };
        stack<char> brackets = {};
        
        for(char c: s){
            if(pairing.count(c)){
                if(brackets.empty()){
                    return false;
                }
                if(brackets.top() == pairing[c]){
                    brackets.pop();
                } else {
                    return false;
                }
            } else {
                brackets.push(c);
            }
        }
        return brackets.empty();
    }
};
