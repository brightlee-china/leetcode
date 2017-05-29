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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        while (n > 0) {
            fast = fast -> next;
            n --;
        }
        
        if (fast == NULL) {
            head = head -> next;
            return head;
        }
        
        ListNode* slow = head;
        while (fast -> next != NULL) {
            fast = fast -> next;
            slow = slow -> next;
        }
        
        slow -> next = slow -> next -> next;
        
        return head;
    }
};