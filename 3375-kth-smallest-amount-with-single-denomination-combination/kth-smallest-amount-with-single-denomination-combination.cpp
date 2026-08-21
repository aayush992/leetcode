class Solution {
public:
    // Helper function
    long long countNumbers(long long mid, vector<int>& coins) {
        int n = coins.size();
        long long count = 0;

        for (int mask = 1; mask < (1 << n); mask++) {

            long long l = 1;
            int bits = 0;
            bool valid = true;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;
                    l = lcm(l, (long long)coins[i]);

                    if (l > mid) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid) continue;

            if (bits % 2)
                count += mid / l;
            else
                count -= mid / l;
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long low = 1;
        long long high = 25LL * k;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (countNumbers(mid, coins) >= k)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};