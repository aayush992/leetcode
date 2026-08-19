class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,set<int>> mp;

        for(auto& it:reservedSeats){
            int row=it[0];
            int seat=it[1];
            mp[row].insert(seat);
        }
        int result=(n-mp.size())*2;

        for(auto& [now,bookedSeat]:mp){

            auto isAvilable=[&](int seat){
                return bookedSeat.find(seat)==bookedSeat.end();
            };

            bool GroupA = isAvilable(2) && isAvilable(3) && isAvilable(4) && isAvilable(5);
            bool GroupB = isAvilable(4) && isAvilable(5) && isAvilable(6) && isAvilable(7);
            bool GroupC = isAvilable(6) && isAvilable(7) && isAvilable(8) && isAvilable(9);

            if(GroupA && GroupC){
                result+=2;
            }
            else if(GroupA || GroupB || GroupC){
                result+=1;
            }

        }
        return result;
    }
};