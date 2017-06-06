/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution { 
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root)
            return result;
        int cnt_f = 1;
        int cnt = 0;
        deque<TreeNode *> dq;
        bool direction = true;
        dq.push_front(root);
        vector<int> temp;
        while (!dq.empty()) {
            if (direction) {
                TreeNode *cur = dq.front();
                temp.push_back(cur -> val);
                if (cur -> left) {
                    dq.push_back(cur -> left);
                    cnt ++;
                }
                if (cur -> right) {
                    dq.push_back(cur -> right);
                    cnt ++;
                }
                dq.pop_front();
            }
            else {
                TreeNode *cur = dq.back();
                temp.push_back(cur -> val);
                if (cur -> right) {
                    dq.push_front(cur -> right);
                    cnt ++;
                }
                if (cur -> left) {
                    dq.push_front(cur -> left);
                    cnt ++;
                }
                dq.pop_back();
            }
            
            if (-- cnt_f == 0) {
                direction = ! direction;
                cnt_f = cnt;
                cnt = 0;
                result.push_back(temp);
                temp.clear();
            }
        }
        
        return result;
    }
};