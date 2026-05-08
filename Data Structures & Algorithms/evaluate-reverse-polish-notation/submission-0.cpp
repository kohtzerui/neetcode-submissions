class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> temp;
        for(const string& token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                //operate the symbols here
                int right = temp.top();
                temp.pop();
                int left = temp.top();
                temp.pop();

                if(token == "+"){
                    temp.push(left + right);
                }
                if(token == "-"){
                    temp.push(left - right);
                }
                if(token == "*"){
                    temp.push(left * right);
                }
                if(token == "/"){
                    temp.push(left/right);
                }
            } else {
                temp.push(stoi(token));
            }
        }
        return temp.top();
    }
};
