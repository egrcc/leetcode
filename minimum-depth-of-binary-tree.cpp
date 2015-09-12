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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        if (left == NULL) return minDepth(right) + 1;
        if (right == NULL) return minDepth(left) + 1;
        return min(minDepth(left), minDepth(right)) + 1;
    }
};