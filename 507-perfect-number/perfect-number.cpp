class Solution {
public:
    bool checkPerfectNumber(int num) {
        int i=1,c=0;
        while(i<num){
            if(num%i==0){
                c+=i;
            }
            i++;
        }
      return c==num;
    }
};