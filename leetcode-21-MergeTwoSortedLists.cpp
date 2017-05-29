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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while (l1 != NULL || l2 != NULL) {
            if (l1 == NULL || (l2 != NULL && (l1 -> val) > (l2 -> val))) {
                cur -> next = l2;
                l2 = l2 -> next;
                cur = cur -> next; 
            }
            else {
                cur -> next = l1;
                l1 = l1 -> next;
                cur = cur -> next;
            }
        }
        
        ListNode* temp = head;
        delete temp;
        head = head -> next;
        return head;
    }
};