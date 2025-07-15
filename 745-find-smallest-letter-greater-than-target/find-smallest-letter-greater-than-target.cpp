class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        // As given array sorted in non-decreasing order, we should try to solve using Binary Search

        // variable ans, stores the index of the smallest character that is greater than target.
        int ans = 0;

        // Traversing the given array
        int start = 0, end = letters.size() - 1;
        while(start <= end){

            // mid calculated in such a way, that it doesn't cause integer overflow for start and end indices having higher integer.
            int mid = start + (end - start)/2;
            // now, even if we find the target element in mid, we have to look for the smallest element greater than target,
            // so we move to right half. Basically, we are looking for characters greater than target but the smallest one.
            if(letters[mid] == target)
                start = mid + 1;
            else if(letters[mid] < target)
                start = mid + 1;
            else { // letters[mid] > target, and could be a potential candidate for an answer, so we store its index in ans variable.
                ans = mid;
                end = mid - 1; // and we move the end towards left, as we have the find the SMALLEST character greater than target, which will/may be present at the left half.
            }
        }
        // finally we have the index of our required character, and we return the character
        return letters[ans];
    }
};