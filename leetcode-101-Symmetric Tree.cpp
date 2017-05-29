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
    bool solve(TreeNode *a, TreeNode *b) {
        if (!a && !b)
            return true;
        if (!a || !b || a -> val != b -> val)
            return false;
        return solve(a -> left, b -> right) && solve(a -> right, b -> left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) 
            return true;
        return solve(root -> left, root -> right);
    }
};