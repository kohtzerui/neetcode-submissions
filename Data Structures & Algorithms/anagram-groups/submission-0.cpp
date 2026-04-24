class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        
        string curr_word = " ";
        string app_word = " ";
        unordered_map<string, vector<string>> tracker;

        for(int i=0; i<strs.size(); i++){
            curr_word = strs[i];
            app_word = strs[i];
            sort(curr_word.begin(), curr_word.end());

            tracker[curr_word].push_back(app_word);
        }

        for(auto& pair : tracker){
            answer.push_back(pair.second);
        }

        return answer;
    }
};
