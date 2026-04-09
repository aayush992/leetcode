class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int opened = 0;
        for (char c : s) {
            if (c == '(') {
                // If it's not the outermost opening parenthesis, add it
                if (opened > 0) result += c;
                opened++;
            } else {
                opened--;
                // If it's not the outermost closing parenthesis, add it
                if (opened > 0) result += c;
            }
        }
        return result;
    }
};
