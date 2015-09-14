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
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        if (nums.size() == 0) return NULL;
        vector<int>::iterator mid = nums.begin() + (nums.size() - 1) / 2;
        TreeNode *node = new TreeNode(*mid);
        if (nums.size() == 1) return node;
        vector<int> left_vec(nums.begin(), mid);
        vector<int> right_vec(mid + 1, nums.end());
        node->left = sortedArrayToBST(left_vec);
        node->right = sortedArrayToBST(right_vec);
        return node;
    }
};