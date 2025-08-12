class Solution {
public:
    int minMovesToMakePalindrome(string s) {
       int n=s.length();
       int i=0,j=n-1;
       int c=0;
       while(i<j){
        if(s[i]==s[j]){
            i++;j--;
        }
            else {
                int k = j;
                while (k > i && s[k] != s[i]) k--;

                if (k == i) {
                    // Middle char, swap with next
                    swap(s[i], s[i+1]);
                        c++;
                } else {
                    // Bubble matched char to r
                    for (int a = k; a < j; a++) {
                        swap(s[a], s[a+1]);
                        c++;
                    }
                    i++;
                    j--;
                }
            }
       }
       return c;
    }

};




       