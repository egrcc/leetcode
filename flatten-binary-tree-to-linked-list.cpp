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
    void flatten(TreeNode* root) {
        TreeNode *node = flattenBT(root);         
    }

    TreeNode* flattenBT(TreeNode* root) {
        if (root == NULL) return root;
        if (root->left == NULL && root->right == NULL) return root;
        TreeNode *left_tail = flattenBT(root->left);
        TreeNode *right_tail = flattenBT(root->right);
        if (root->left != NULL) {
            TreeNode *temp = root->right;
            root->right = root->left;
            root->left = NULL;
            left_tail->right = temp;
        } 
        if (right_tail != NULL) {
            return right_tail;
        }
        return left_tail;
    }
};