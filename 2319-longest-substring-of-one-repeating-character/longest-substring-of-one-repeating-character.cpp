class Solution {
public:
    
    struct Node{
        int pre = 0;
        int suf = 0;
        int maxlen = 0;
        int leftChar = 0;
        int rightChar = 0;
    };

    int n;
    vector<Node> segTree;

    Node merge(const Node& L, const Node& R, int leftLen, int rightLen){

        Node res;
        res.leftChar = L.leftChar;
        res.rightChar = R.rightChar;

        res.pre = L.pre;
        if(L.pre == leftLen && L.leftChar == R.leftChar){
            res.pre = L.pre + R.pre;
        }

        res.suf = R.suf;
        if(R.suf == rightLen && L.rightChar == R.leftChar){
            res.suf = R.suf + L.suf;
        }

        res.maxlen = max(L.maxlen, R.maxlen);
        if(L.rightChar == R.leftChar){
            res.maxlen = max(res.maxlen , L.suf + R.pre);
        }
        return res;
    }

    void buildSegmentTree(int i, int l, int r, string& s){
        if(l==r){
            segTree[i]={1,1,1,s[l],s[l]};
            return;
        }
        int mid= l+ (r-l)/2;
        buildSegmentTree(2*i+1,l,mid,s);
        buildSegmentTree(2*i+2,mid+1,r,s);
        segTree[i]=merge(segTree[2*i+1],segTree[2*i+2],mid-l+1,r-mid);
    }

    void update(int i, int l, int r, int pos, int ch){
        if(l== r){
            segTree[i] ={ 1, 1, 1, ch, ch };
            return;
        }
        int mid =l +(r- l)/2;
        if(pos<=mid){
            update(2*i+1, l ,mid, pos, ch);
        }else{
            update(2*i+2 , mid+1, r, pos, ch);
        }
        segTree[i] = merge(segTree[2*i+1],segTree[2*i+2],mid-l+1,r-mid);
    }


    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices){
        n=s.size();
        segTree.assign(4*n , Node());

        buildSegmentTree(0, 0, n-1, s);

        int k=queryIndices.size();
        vector<int>result(k);
        for(int i=0; i<k; i++){
            int pos = queryIndices[i];
            char ch = queryCharacters[i];
            update(0, 0, n-1, pos, ch);

            result[i]= segTree[0].maxlen;
        }
        return result;

    }        
  
  
   /* int longestRepeatingCharacter(string &s){
        int i=0,j=0;
        int a=s.length();
        int sum=0, maxsum=0;
        while(j<a){
            if(s[i]==s[j]){
                sum++;
                j++;
                maxsum=max(sum,maxsum);
            }
            else{
                i=j;
                sum=0;
            }
        }
        return maxsum;
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        int k = queryIndices.size();
        vector<int>ans(k);

        for(int i=0; i<k; i++){
            s[queryIndices[i]] = queryCharacters[i];
            ans[i] = longestRepeatingCharacter(s);
        }
        return ans;
    }

    */
};