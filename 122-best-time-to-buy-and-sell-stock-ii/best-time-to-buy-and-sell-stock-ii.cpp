class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0;
        int totalProfit=0;
        int buy=prices[0];
        for(int i=1;i<n;i++){
            
            if(buy>prices[i]){
                buy=prices[i];
            }
            if(prices[i]>buy){
                profit=prices[i]-buy;
                totalProfit+=profit;
                buy=prices[i];
            }
        
        }
 return totalProfit;
    }
};