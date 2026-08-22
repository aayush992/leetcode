class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int a=n;
        int product=1;
        while(a>0){
            int lastdigit=a%10;
            product=product*lastdigit;
            sum+=lastdigit;
            a=a/10;
        }
        return (n%(product+sum)==0);
    }
};