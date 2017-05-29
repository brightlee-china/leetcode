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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        vector<TreeNode *> stack;
        while (root || !stack.empty()) {
            if (root) {
                stack.push_back(root);
                root = root -> left;
            }
            else {
                result.push_back(stack.back() -> val);
                root = stack.back() -> right;
                stack.pop_back();
            }
        }
        
        return result;
    }
};