class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n= word1.length();
        int m= word2.length();

        vector<int>righthandsidematchlength(n,0);

        int rightMatched=0;
        int i=n-1;
        int j=m-1;
        while(i>=0){
            if(j>=0 && word1[i]==word2[j]){
                rightMatched++;
                j--;
            }
                righthandsidematchlength[i]=rightMatched;
                i--;
         }
            vector<int>seq;
            bool changepower=true;
            i=0,j=0;
            while(i<n && j<m){
                if(word1[i]==word2[j]){
                    seq.push_back(i);
                    j++;
                }
                else if(changepower==true && i+1<n && righthandsidematchlength[i+1]>=m-j-1){
                    seq.push_back(i);
                    j++;
                    changepower=false;
                }
                i++;
            }
            return j==m?seq:vector<int>();
    }
};