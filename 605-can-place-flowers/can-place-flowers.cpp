class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int a = flowerbed.size();

        if (a == 1) {
            if (flowerbed[0] == 0) n--;
            return n <= 0;
        }

        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
            flowerbed[0] = 1;
            n--;
        }

        for (int i = 1; i < a - 1; i++) {
            if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }

        if (flowerbed[a - 1] == 0 && flowerbed[a - 2] == 0) {
            flowerbed[a - 1] = 1;
            n--;
        }

        return n <= 0;
    }
};
