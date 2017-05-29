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
        ListNode* cur = head;
        ListNode* result = new ListNode(0);
        head = result;
        while (cur) {
            int cnt = 1;
            while (cur -> next && cur -> next -> val == cur -> val) {
                cur = cur -> next;
                cnt ++;
            }
            
            if (cnt == 1) {
                result -> next = cur;
                result = result -> next;
            }
            
            cur = cur -> next;
        }
        result -> next = NULL;
        
        return head -> next;
    }
};