class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt=0;
      int lastseen[3]={-1,-1,-1};
      for(int i=0;i<s.length();i++){
        lastseen[s[i]-'a']=i;
        if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1){
            cnt += (1 + min({lastseen[0], lastseen[1], lastseen[2]}));

        }
      }
      return cnt;
  
      
      
       /*    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        int hash[3] = {0};  // reset for each new starting index
        for (int j = i; j < s.length(); j++) {
            hash[s[j] - 'a'] = 1;   // ✅ use s[j] instead of s[i]
            if (hash[0] + hash[1] + hash[2] == 3) {
                cnt += (s.length() - j);
                break;  // stop, because all substrings beyond j also have all 3 chars
            }
        }
    }
    return cnt;
TLE tc=O(n^2)
    sc=O(n)
*/
    }
};