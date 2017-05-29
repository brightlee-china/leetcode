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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* f = new ListNode(0);
        f -> next = head;
        ListNode* cur = head;
        ListNode* pre = f;
        if (head == NULL)
            return NULL;

        while(true) {
            int cnt = k;
            ListNode* new_cur = NULL;
            ListNode* back = cur;

            while (cur != NULL && cnt > 0) {
                ListNode* temp = cur -> next;
                cur -> next = new_cur;
                new_cur = cur;
                cur = temp;
                cnt --;
            }

            if (cur == NULL && cnt > 0) {
                //do reverse again;
                ListNode* other = NULL;
                while (new_cur != NULL) {
                    ListNode* temp = new_cur -> next;
                    new_cur -> next = other;
                    other = new_cur;
                    new_cur = temp;
                }

                pre -> next = other;
                break;
            }

            back -> next = cur;
            pre -> next = new_cur;
            pre = back;


            if (cur == NULL && cnt == 0) {
                break;
            }
        }

        f = f -> next;
        return f;
    }
};