class Solution {
public:
    int n;
    vector<int>t;
    int solve(vector<int>& stone, int i){
        
        int result=INT_MIN;
        if(i>=n)return 0;
        if(t[i]!=-1)return t[i];
        result=max(result,stone[i]-solve(stone,i+1));

        if(i+1<n)
        result=max(result,stone[i]+stone[i+1]-solve(stone,i+2));

        if(i+2<n)
        result=max(result,stone[i]+stone[i+1]+stone[i+2]-solve(stone,i+3));

        return t[i]= result;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        t.resize(n+1,-1);
        int b= solve(stoneValue,0);
        if(b>0)return "Alice";
        else if(b<0)return "Bob";
        else return "Tie";
        
    }
};

