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
    vector<TreeNode*> solve(int from, int to) {
        vector<TreeNode*> result;
        if (from == to) {
            TreeNode *cur = new TreeNode(from);
            result.push_back(cur);
            return result;
        }
        
        for (int i = from; i <= to; i ++) {
            vector<TreeNode*> left;
            vector<TreeNode*> right;
            if (i != from)
                left = solve(from, i - 1);
                
            if (i != to)
                right = solve(i + 1, to);
                
            if (i == from) {
                for (int j = 0; j < right.size(); j ++) {
                    TreeNode *cur = new TreeNode(i);
                    cur -> right = right[j];
                    result.push_back(cur);
                }
                continue;
            }
            
            if (i == to) {
                for (int j = 0; j < left.size(); j ++) {
                    TreeNode *cur = new TreeNode(i);
                    cur -> left = left[j];
                    result.push_back(cur);
                }
                continue;
            }
            
            for (int j = 0; j < left.size(); j ++) {
                for (int k = 0; k < right.size(); k ++) {
                    TreeNode *cur = new TreeNode(i);
                    cur -> left = left[j];
                    cur -> right = right[k];
                    result.push_back(cur);
                }
            }
        }
        
        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result = solve(1, n);
        return result;
    }
};