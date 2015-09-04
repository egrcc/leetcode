/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> v;
//         if (root == NULL) return v;
//         vector<int> left_v = inorderTraversal(root->left);
//         vector<int> right_v = inorderTraversal(root->right);
//         v.insert(v.end(), left_v.begin(), left_v.end());
//         v.push_back(root->val);
//         v.insert(v.end(), right_v.begin(), right_v.end());
//         return v;
//     }
// };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if (root == NULL) return v;
        stack<TreeNode *> stk;
        TreeNode *p = root;
        while (!(stk.empty()) || p != NULL) {
            if (p != NULL) {
                stk.push(p);
                p = p->left;
            } else {
                p = stk.top();
                stk.pop();
                v.push_back(p->val);
                p = p->right;
            }
        }
        return v;
    }
};