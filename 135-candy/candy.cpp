class Solution {
public:
 int candy(vector<int>& ratings) {
    int n = ratings.size();
    if (n == 0) return 0;

    int sum = 1, i = 1;   // sum = total candies, start with 1 for first child
    int peak = 0;         // length of increasing slope
    int down = 0;         // length of decreasing slope

    while (i < n) {
        // Case 1: Equal ratings → give exactly 1 candy
        if (ratings[i] == ratings[i - 1]) {
            sum += 1;
            peak = 0;     // reset slope trackers
            down = 0;
            i++;
            continue;
        }

        // Case 2: Increasing slope
        int up = 0;
        while (i < n && ratings[i] > ratings[i - 1]) {
            up++;
            sum += 1 + up; // increasing sequence, each gets +1 more
            i++;
        }
        peak = up; // store peak length of increase

        // Case 3: Decreasing slope
        down = 0;
        while (i < n && ratings[i] < ratings[i - 1]) {
            down++;
            sum += down;   // give decreasing candies
            i++;
        }

        // Adjust if downhill longer than uphill
        if (down > peak) {
            sum += down - peak;
        }
    }

    return sum;
}

};



/*
   int n= ratings.size();
        vector<int>l2r(n,1);// to calculate greed from left
        vector<int>r2l(n,1);// to calculate greed from right
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                l2r[i]=l2r[i-1]+1;// filling vector according to greed from left ot right
            }
          }  int sum=0;
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                r2l[i]=r2l[i+1]+1;// from right to left
            }
        }            
        for(int i = 0; i < n; i++) {
            sum += max(l2r[i], r2l[i]);//maximum of left and right
        }
        return sum;
        // tc=O(2n) sc=O(2n)
        */

            /* int n = ratings.size();
        vector<int> l2r(n, 1);  // candies from left to right

        // left to right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                l2r[i] = l2r[i - 1] + 1;
            }
        }

        // right to left
        int sum = l2r[n - 1]; // include last child
        int curr = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                curr++;
            } else {
                curr = 1;
            }
            sum += max(l2r[i], curr);
        }

        return sum;
        
        tc=O(2n)  sc=O(n)

        */