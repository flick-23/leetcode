class Solution {
public:
    int longestValidParentheses(string str) {
        stack<int> s;
        s.push(-1); // Base case to handle valid substrings from the beginning
        int maxLen = 0;

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') {
                s.push(i);  // Store index of '('
            } else { // str[i] == ')'
                s.pop();  // Try matching with a previous '('
                
                if (s.empty()) {
                    s.push(i);  // No matching '(' left, update last unmatched index
                } else {
                    maxLen = max(maxLen, i - s.top());  // Valid length
                }
            }
        }
        return maxLen;
    }
};
