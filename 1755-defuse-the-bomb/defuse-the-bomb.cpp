class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        int n = code.size();
        vector<int> result(n, 0); // Result vector initialized to 0
        
        if (k == 0)    return result;

       if (k > 0) {
            for (int i = 0; i < n; i++) 
            {
                int sum = 0;
                for (int j = 1; j <= k; j++) 
                    sum += code[(i + j) % n]; // Access the next k elements
                
                result[i] = sum; // Store the sum in the result
            }
        } 

        else {
            for (int i = 0; i < n; i++) 
            {
                int sum = 0;
                for (int j = 1; j <= -k; j++) 
                    sum += code[(i - j + n) % n]; // Access the previous -k elements
                
                result[i] = sum; // Store the sum in the result
            }
        }
       return result ;
    }
};