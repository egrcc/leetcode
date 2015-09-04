class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> stk;

        vector<string>::iterator it;
        for (it = tokens.begin(); it != tokens.end(); it++) {
            if (*it != "+" && *it != "-" && *it != "*" && *it != "/") {
                stk.push(*it);
            } else {
                int y = stoi(stk.top());
                stk.pop();
                int x = stoi(stk.top());
                stk.pop();
                if (*it == "+") stk.push(to_string(x + y));
                else if (*it == "-") stk.push(to_string(x - y));
                else if (*it == "*") stk.push(to_string(x * y));
                else stk.push(to_string(x / y));
            }
        }

        return stoi(stk.top());
    }
};