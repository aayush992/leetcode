class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt=numBottles;
        int empty=0;
        while(numBottles){
            numBottles=numBottles+empty;
            empty=numBottles%numExchange;
            numBottles=numBottles/numExchange;
            cnt+=numBottles;
        }
        return cnt;
    }
};