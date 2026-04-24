class Solution {
public:

    string encode(vector<string>& strs) {
        string temp = "";

        for(const auto& word : strs){
            temp += word + '.';
        }

        return temp;
    }

    vector<string> decode(string s) {
        vector<string> answer;
        string temp = "";

        for(const char& letter : s){
            if(letter != '.'){
                temp += letter;
            } else {
                answer.push_back(temp);
                temp = "";
            }
        }

        return answer;
    }
};
