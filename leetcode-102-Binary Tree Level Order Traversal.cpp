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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        vector<vector<int>> result;
        if (!root)
            return result;
        q.push(root);
        vector<int> cur;
        TreeNode *pre = root;
        while (!q.empty()) {
            TreeNode *temp = q.front();
            cur.push_back(temp -> val);
            if (temp -> left)
                q.push(temp -> left);
            if (temp -> right)
                q.push(temp -> right);
            if (temp == pre) {
                result.push_back(cur);
                cur.clear();
                pre = q.back();
            }
            
            q.pop();
        }
        
        return result; 
    }
};