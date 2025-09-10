class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool sign = !((dividend >= 0) ^ (divisor >= 0)); // same sign -> positive

        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);
        long long quotient = 0;

        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt++;
            }
            quotient += 1LL << cnt;
            n -= d << cnt;
        }

        quotient = sign ? quotient : -quotient;

        if (quotient > INT_MAX) return INT_MAX;
        if (quotient < INT_MIN) return INT_MIN;

        return (int)quotient;
    }
};
