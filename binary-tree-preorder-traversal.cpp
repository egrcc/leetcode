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
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> v;
//         if (root == NULL) return v;
//         v.push_back(root->val);
//         vector<int> left_v = preorderTraversal(root->left);
//         vector<int> right_v = preorderTraversal(root->right);
//         v.insert(v.end(), left_v.begin(), left_v.end());
//         v.insert(v.end(), right_v.begin(), right_v.end());
//         return v;
//     }
// };
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if (root == NULL) return v;
        stack<TreeNode *> stk;
        TreeNode *p = root;
        stk.push(p);
        while (!(stk.empty())) {
            p = stk.top();
            stk.pop();
            v.push_back(p->val);
            if (p->right != NULL) stk.push(p->right);
            if (p->left != NULL) stk.push(p->left);
        }
        return v;
    }
};