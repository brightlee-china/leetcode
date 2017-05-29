class Solution {
public:
    bool correct(char a, char b) {
        return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
    }

    bool isValid(string s) {
        stack<char > stk;
        for (int i = 0; i < s.size(); i ++) {
            if (!stk.empty()) {
                char t = stk.top();
                if (correct(t, s[i])) {
                    stk.pop();
                    continue;
                }
            }

            stk.push(s[i]);
        }

        return stk.empty();
    }
};