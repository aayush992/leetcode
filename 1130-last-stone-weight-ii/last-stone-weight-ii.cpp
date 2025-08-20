class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total = 0;
        for(int x : stones){
            total += x;
        }
        
        int target = total / 2;  // max sum we want to get close to
        vector<bool> t(target+1, false);
        t[0] = true;

        for(int stone : stones){
            for(int j = target; j >= stone; j--){  // loop backwards
                t[j] = t[j] || t[j-stone];
            }
        }

        int best = 0;
        for(int j = target; j >= 0; j--){
            if(t[j]){
                best = j;
                break;
            }
        }
        return total - 2*best;
    }
};
