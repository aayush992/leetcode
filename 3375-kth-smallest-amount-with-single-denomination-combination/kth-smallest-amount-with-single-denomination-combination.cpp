class Solution {
public:
    typedef long long ll;

    ll countSmaller(ll mid, vector<int>& coins){
        ll corrected_count=0;
        int n=coins.size();

        for(int expression =1; expression<=(1<<n)-1; expression++){
            ll lcm =0;
            ll order=0;

            for(int i=0;i<n;i++){
                if(expression & (1<<i)){
                    order++;
                    if(lcm==0){
                        lcm=coins[i];
                    }
                    else{
                        lcm=(lcm*coins[i])/gcd(coins[i],lcm);
                    }
                }
            }
            if(order%2==0){
                corrected_count-=mid/lcm;
            }
            else{
                corrected_count+=mid/lcm;
            }
        }
        return corrected_count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        ll result=-1;
        ll low=0;
        ll high =(ll)(*max_element(begin(coins),end(coins))) * k;

        while(low<=high){
            ll mid=low+(high-low)/2;

            if(countSmaller(mid,coins)>=k){
                result=mid;
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return result;

    }
};