class Solution {
public:
    bool isPalindrome(int x) {
        long res=0;
        if(x<0)return false;
        int q=x;
        while(q!=0){
            int rem = q%10;
            res = res*10+rem;
            q=q/10; 
        }
        return x==res;
    }
};