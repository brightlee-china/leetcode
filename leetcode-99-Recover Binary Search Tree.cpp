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
    TreeNode *first;
    TreeNode *second;
    TreeNode *pre_node;

    void inorder(TreeNode *root) {
        if (!root)
            return;
        inorder(root -> left);
        if (!first && pre_node -> val >= root -> val)
            first = pre_node;
        if (first && pre_node -> val >= root -> val)
            second = root;
        
        pre_node = root; // remember pre node 
        inorder(root -> right);
    } 
    
    void recoverTree(TreeNode* root) {
        pre_node = new TreeNode(INT_MIN);
        inorder(root);
        int temp = first -> val;
        first -> val = second -> val;
        second -> val = temp;
    }
};