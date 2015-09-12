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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> v;
        if (root == NULL) return v;

        queue<TreeNode *> current, next;
        current.push(root);
        vector<int> level; 
        bool left_to_right = true;

        while (!(current.empty())) {
            while (!(current.empty())) {
                TreeNode *t = current.front();
                level.push_back(t->val);
                if (t->left != NULL) next.push(t->left);
                if (t->right != NULL) next.push(t->right);
                current.pop();
            }
            if (left_to_right == false) {
                reverse(level.begin(), level.end());
            }
            v.push_back(level);
            left_to_right = left_to_right?false:true;
            level.clear();
            swap(next, current);
        }

        return v;
        
    }
};