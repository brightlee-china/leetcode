/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;
        ListNode* back;
        if (cur != NULL)
             back = cur -> next;
        ListNode* pre = head;
        while (cur && back) {
            if (pre == head) {
                cur -> next = back -> next;
                back -> next = head;
                head = back;
            }
            else {
                cur -> next = back -> next;
                back -> next = cur;
                pre -> next = back;
            }
            
            pre = cur;
            cur = pre -> next;
            
            if (cur != NULL)
                back = cur -> next;
            else 
                break;
        }
        
        return head;
    }
};