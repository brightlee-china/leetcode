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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0)
            return head;
        
        ListNode* cur = head;
        int len = 1;
        while (cur -> next != NULL) {
            cur = cur -> next;
            len ++;
        }
        
        cur -> next = head;
        
        k = k % len;
        for (int i = 0; i < len - k; i ++) {
            cur = cur -> next;
        }
        
        head = cur -> next;
        cur -> next = NULL;
        
        return head;
    }
};