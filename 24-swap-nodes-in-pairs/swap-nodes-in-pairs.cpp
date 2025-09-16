class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Edge case: 0 or 1 node
        if (!head || !head->next) return head;

        // New head will be the second node after first swap
        ListNode* newHead = head->next;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr && curr->next) {
            ListNode* nextPair = curr->next->next;
            ListNode* second = curr->next;

            // Swap
            second->next = curr;
            curr->next = nextPair;

            if (prev) {
                prev->next = second;  // connect with previous swapped pair
            }

            // Move prev and curr forward
            prev = curr;
            curr = nextPair;
        }

        return newHead;
    }
};
