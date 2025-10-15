/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode* ptr = head;
        int count = 1;
        stack<int> revval; //stack for LIFO
        while(ptr != nullptr)
        {
            if(count > right) break;
            if(count >= left)
            {
                revval.push(ptr->val);
            }
            ptr = ptr->next;
            count++;
        }
        //reset counter and pointer
        count = 1;
        ptr = head;
        while(ptr != nullptr)
        {
            if(count > right) break;
            if(count >= left)
            {
                ptr->val = revval.top();//overwrite from stack
                revval.pop();
            }
            ptr = ptr->next;
            count++;
        }
        return head;
    }
};