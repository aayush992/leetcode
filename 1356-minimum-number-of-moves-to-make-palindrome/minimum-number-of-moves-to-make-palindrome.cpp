class Solution {
public:
    int minMovesToMakePalindrome(string s) {
       int n=s.length();
       int i=0; //left pointer
       int j=n-1;//right pointer
       int c=0;
       while(i<j){
        if(s[i]==s[j]){ //if last and first char are equal
            i++;j--;
        }
            else {
                int k = j;//start checking from last charcater
                while (k > i && s[k] != s[i]) k--;//check till not reaching i
                            
                if (k == i) {
                    // Middle char, swap with next
                    swap(s[i], s[i+1]);
                        c++;
                } else {
                    // Bubble matched char to right i.e. j
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




       