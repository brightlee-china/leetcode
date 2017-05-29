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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur = new ListNode(-1);
        ListNode* first = cur;
        int c = 0;
        while (l1 != NULL || l2 != NULL) {
            ListNode* result = new ListNode(0);
            if (l1 != NULL) {
                c += l1 -> val;
                l1 = l1 -> next;
            }
            
            if (l2 != NULL) {
                c += l2 -> val;
                l2 = l2 -> next;
            }
            
            result -> val = c % 10;
            c = c / 10;
            cur -> next = result;
            cur = result;
        }
        
        if (c != 0) {
            ListNode* temp = new ListNode(c);
            temp -> next = NULL;
            cur -> next = temp;
        }
        
        first = first -> next;
        return first;
        
    }
};