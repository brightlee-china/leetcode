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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *result = new ListNode(0);
        ListNode *front = result;
        ListNode *cur = head;
        while (cur) {
            if (cur -> next == NULL || cur -> next -> val != cur -> val) {
                result -> next = cur;
                result = result -> next;
            }
            
            cur = cur -> next;
        }
        
        result -> next = NULL;
        
        return front -> next;
    }
};