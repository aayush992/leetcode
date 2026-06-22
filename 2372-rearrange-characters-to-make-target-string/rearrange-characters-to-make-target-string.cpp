class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> sFreq;
        unordered_map<char, int> tFreq;

        for(char ch : s) {
            sFreq[ch]++;
        }

        for(char ch : target) {
            tFreq[ch]++;
        }

        int ans = INT_MAX;

        for(auto &p : tFreq) {
            ans = min(ans, sFreq[p.first] / p.second);
        }

        return ans;
    }
};