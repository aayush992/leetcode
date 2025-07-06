class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<int> b = flowerbed;
        int a = b.size();

        if (a == 1) {
            if (b[0] == 0) n--;
            return n <= 0;
        }

        if (b[0] == 0 && b[1] == 0) {
            b[0] = 1;
            n--;
        }

        for (int i = 1; i < a - 1; i++) {
            if (b[i] == 0 && b[i - 1] == 0 && b[i + 1] == 0) {
                b[i] = 1;
                n--;
            }
        }

        if (b[a - 1] == 0 && b[a - 2] == 0) {
            b[a - 1] = 1;
            n--;
        }

        return n <= 0;
    }
};
