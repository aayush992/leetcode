class Solution {
public:
    int countOnebit(int num){
        int count=0;
        while(num){
            count+=num&1;
            num>>=1;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {

        auto lambda=[&](int &a,int &b){
            int ca=countOnebit(a);
            int cb=countOnebit(b);
            if(ca==cb)
            return a<b;
            else
            return ca<cb;
        };

        sort(begin(arr),end(arr),lambda);
        return arr;
    }
};