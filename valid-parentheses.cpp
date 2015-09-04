class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        stack<int> stk;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
            } else if ((s[i] == ')' && !(stk.empty()) && stk.top() == '(') || 
                (s[i] == ']' && !(stk.empty()) && stk.top() == '[') || 
                (s[i] == '}' && !(stk.empty()) && stk.top() == '{')) {
                stk.pop();
            } else {
                return false;
            }
        }
        if (!(stk.empty())) return false;
        return true;
    }
};