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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* newHead = NULL;
        int cnt = 1;
        ListNode* mid = new ListNode(0);
        ListNode* cur = head;
        ListNode* front = NULL;
        while (cur && cnt < m) {
            front = cur;
            cur = cur -> next;
            cnt ++;
        }
        
        ListNode* second = cur;
        while (cur && cnt <= n) {
            ListNode *temp = cur;
            cur = cur -> next;
            temp -> next = mid -> next;
            mid -> next = temp;
            cnt ++;
        }
        
        if (!head)
            return head;
        
        second -> next = cur;
        
        if (!front) {
            return mid -> next;
        }
        else {
            front -> next = mid -> next;
            return head;
        }
    }
};