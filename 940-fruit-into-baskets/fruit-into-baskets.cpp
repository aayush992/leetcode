class Solution {
public:
   int totalFruit(vector<int>& fruits) {
    int l = 0, r = 0, maxlen = 0;
    unordered_map<int,int> mpp;

    while (r < fruits.size()) {
        mpp[fruits[r]]++;

        // shrink window if more than 2 types
        while (mpp.size() > 2) {
            mpp[fruits[l]]--;
            if (mpp[fruits[l]] == 0) {
                mpp.erase(fruits[l]);
            }
            l++;
        }

        // now window has at most 2 types
        maxlen = max(maxlen, r - l + 1);
        r++;
    }

    return maxlen;
}

 
 
 
 
 
 
 
 
       /*  int maxlen=0;
        for(int i=0;i<fruits.size();i++){
            set<int>st;
            for(int j=i;j<fruits.size();j++){
                st.insert(fruits[j]);
                if(st.size()<=2){
                    maxlen=max(maxlen,j-i+1);
                }
                else break;
            }
        }
        return maxlen; 
        
        TLE tc=O(n^2)
        sc=O(3)
        */ 
    
};