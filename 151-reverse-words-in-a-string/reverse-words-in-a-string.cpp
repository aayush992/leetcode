class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);       // put the string into a stream
        string word;
        vector<string> words;

        // Step 1: Extract words from the string
        while (ss >> word) {      // >> skips extra spaces automatically
            words.push_back(word);
        }

        // Step 2: Reconstruct words in reverse order
        string res;
        for (int i = words.size() - 1; i >= 0; i--) {
            res += words[i];      // append current word
            if (i != 0) {         // add space if not the last word
                res += " ";
            }
        }

        return res;
    }
};
