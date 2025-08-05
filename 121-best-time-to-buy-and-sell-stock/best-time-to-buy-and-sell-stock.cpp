class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=prices[0],max=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<min)
            min=prices[i];
            else if(prices[i]-min>max)
            max=prices[i]-min;
        }
        return max;
    }
};

