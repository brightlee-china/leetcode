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
    // less 从小到大排序，大根推。
    // greater 从大到小排序，小根堆。
    struct cmp{
        bool operator() (ListNode* a, ListNode* b) {
            return (a -> val) > (b -> val);
        }  
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode* >, cmp> pq;
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        
        for (int i = 0; i < lists.size(); i ++) {
            if (lists[i] != NULL)
                pq.push(lists[i]);
            
        }
        
        while (!pq.empty()) {
            ListNode* a = pq.top(); pq.pop();
            cur -> next = a;
            cur = cur -> next;
            
            if (a -> next != NULL) 
                pq.push(a -> next);
        }
        
        head = head -> next;
        return head;
    }
};