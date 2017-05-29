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
    ListNode* partition(ListNode* head, int x) {
        ListNode *a = new ListNode(0);
        ListNode *b = new ListNode(0);
        ListNode *head1 = a;
        ListNode *head2 = b;
        
        ListNode *cur = head;
        while (cur != NULL) {
            if ((cur -> val) < x) {
                a -> next = cur;
                a = a -> next;
            }
            else {
                b -> next = cur;
                b = b -> next;
            }
            
            cur = cur -> next;
        }
        
        b -> next = NULL;
        a -> next = head2 -> next;
        return head1 -> next;
    }
};