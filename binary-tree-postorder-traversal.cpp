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
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> v;
//         if (root == NULL) return v;
//         vector<int> left_v = postorderTraversal(root->left);
//         vector<int> right_v = postorderTraversal(root->right);
//         v.insert(v.end(), left_v.begin(), left_v.end());
//         v.insert(v.end(), right_v.begin(), right_v.end());
//         v.push_back(root->val);
//         return v;
//     }
// };
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if (root == NULL) return v;
        stack<TreeNode *> stk;
        TreeNode *p = root;
        TreeNode *visit;

        while (!(stk.empty()) || p != NULL) {
            if (p != NULL) {
                stk.push(p);
                p = p->left;
            } else {
                p = stk.top();
                if (p->right != NULL && p->right != visit) {
                    p = p->right;
                } else {
                    stk.pop();
                    v.push_back(p->val);
                    visit = p;
                    p = NULL;
                }
            }
        }

        return v;
    }
};