class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n =s.length();
        int sum=0,ans=0;
        unordered_map<char,int>mp;

        int i=0,j=0;
        while(j<n){

            mp[s[j]]++;
            sum++;

            while(mp[s[j]]>2){
                mp[s[i]]--;
                sum--;
                i++;
            }
            ans=max(ans,sum);
            j++;
        }
        return ans;
    }
};