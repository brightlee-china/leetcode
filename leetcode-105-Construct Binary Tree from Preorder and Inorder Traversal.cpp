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
    TreeNode* solve(vector<int> &preorder, int start_a, vector<int> &inorder, int start_b, int len, unordered_map<int, int> &m) {
        if (len <= 0)
            return NULL;
        int temp = preorder[start_a];
        TreeNode *root = new TreeNode(temp);
        int new_len = m[temp] - start_b;
        root -> left = solve(preorder, start_a + 1, inorder, start_b, new_len, m);
        root -> right = solve(preorder, start_a + 1 + new_len, inorder, start_b + 1 + new_len, len - new_len - 1, m);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); i ++) 
            m[inorder[i]] = i;
        return solve(preorder, 0, inorder, 0, preorder.size(), m);
    }
};