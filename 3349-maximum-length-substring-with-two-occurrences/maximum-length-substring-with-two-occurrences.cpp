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



      /*  for(int i=0; i<n; i++){
            mp[s[i]]++;
            sum++;
            if(mp[s[i]]==2){
                sum=0;
                mp[s[i]]--;
            }
            ans=max(sum, ans);
        }
        return ans; */
    }
};