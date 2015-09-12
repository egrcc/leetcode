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

    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        return max(maxDepth(left), maxDepth(right)) + 1;
        
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;

        TreeNode *left = root->left;
        TreeNode *right = root->right;

        int left_depth = maxDepth(left);
        int right_depth = maxDepth(right);
        if (abs(left_depth - right_depth) > 1) {
            return false;
        } else {
            bool left_balanced = isBalanced(left);
            bool right_balanced = isBalanced(right);
            if (left_balanced && right_balanced) {
                return true;
            } else {
                return false;
            }
        }
        
    }
};