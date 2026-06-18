class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ma=minutes*6;
        double hA=(hour%12)* 30 + minutes*0.5;
        double diff=abs(hA-ma);
        return min(diff,360-diff);
    }
};