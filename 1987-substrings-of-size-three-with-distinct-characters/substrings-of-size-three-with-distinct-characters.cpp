class Solution {
public:
    int countGoodSubstrings(string s) {
  int count = 0;
    
    // Check if the string has fewer than 3 characters
    if (s.length() < 3) return 0;

    for (int i = 0; i <= s.length() - 3; ++i) {
        unordered_set<char> uniqueChars = {s[i], s[i + 1], s[i + 2]};
        
        if (uniqueChars.size() == 3) {
            count++;
        }
    }
    
    return count;
}
};