class Solution {
public:
    bool checkDivisibility(int n) {

        int original = n;
        int sum = 0;
        int product = 1;

        while (n > 0) {
            int lastdigit = n % 10;
            sum += lastdigit;
            product *= lastdigit;
            n /= 10;
        }

        return original % (sum + product) == 0;
    }
};